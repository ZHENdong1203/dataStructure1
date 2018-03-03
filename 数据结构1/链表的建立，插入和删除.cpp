#include <stdio.h>  
#include <stdlib.h>  
#define OK 1  
#define ERROR 0  
#define OVERFLOW -2  
typedef int status;
typedef int ElemType;
typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;
void CreateList_L(LinkList &L, int n)
{
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	int i;
	LinkList p;
	for (i = n; i > 0; --i)
	{
		p = (LinkList)malloc(sizeof(LNode));
		scanf_s("%d",&p->data);
		p->next = L->next;
		L->next = p;
	}
}//��������
status ListInsert_L(LinkList &L, int i, ElemType e)
{
	LinkList p, s;
	int j = 0;
	p = L;
	while (p&&j < i - 1)
	{
		p = p  ->next;
		++j;
	}
	if (!p || j > i - 1)
	{
		return ERROR;
	}
	s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}//����Ĳ���
status ListDelete_L(LinkList &L, int i, ElemType &e)
{
	LinkList p, q;
	int j = 0;
	p = L;
	while (p->next&&j < i - 1)
	{
		p = p  ->next;
		++j;
	}
	if (!(p->next) || j > i - 1)
	{
		return ERROR;
	}
	q = p->next;
	p->next = q->next;
	e = q->data;
	free(q);
	return e;
}//�����ɾ��
status ListTraverse_L(LinkList L)
{
	LinkList p;
	p = L->next;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}//��������
int main()
{
	LinkList L;
	int e;
	printf("������10����:\n");
	CreateList_L(L, 10);
	printf("�����ӡ����:\n");
	ListTraverse_L(L);
	printf("�ڵ�5��Ԫ��ǰ��������11\n");
	ListInsert_L(L, 5, 11);
	printf("����������ӡ����:\n");
	ListTraverse_L(L);
	printf("ɾ����7��Ԫ��\n");
	printf("ɾ����Ԫ��Ϊ:");
	printf("%d\n", ListDelete_L(L, 7, e));
	printf("ɾ���������ӡ����:\n");
	ListTraverse_L(L);
	system("pause");
	return 0;
}
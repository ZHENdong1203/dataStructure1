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
}//建立链表
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
}//链表的插入
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
}//链表的删除
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
}//遍历链表
int main()
{
	LinkList L;
	int e;
	printf("请输入10个数:\n");
	CreateList_L(L, 10);
	printf("链表打印如下:\n");
	ListTraverse_L(L);
	printf("在第5个元素前插入数字11\n");
	ListInsert_L(L, 5, 11);
	printf("插入后链表打印如下:\n");
	ListTraverse_L(L);
	printf("删除第7个元素\n");
	printf("删除的元素为:");
	printf("%d\n", ListDelete_L(L, 7, e));
	printf("删除后链表打印如下:\n");
	ListTraverse_L(L);
	system("pause");
	return 0;
}
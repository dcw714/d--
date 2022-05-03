#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode, *LinkList;

bool InitList(LinkList &L)
{
	L = NULL;
	return true;
}



// 在指定节点后插入
bool InsertNextNode(LNode *p, int e)
{
	if (p == NULL)
	{
		return false;
	}
	LNode *s = (LNode *)malloc(sizeof(LNode));
	if (s == NULL)
	{
		return false;
	}
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

// 在指定节点前插入
bool InsertPriorNode(LNode *p, int e)
{
	if (p == NULL)
	{
		return false;
	}
	LNode *s = (LNode *)malloc(sizeof(LNode));
	if (s == NULL)
	{
		return false;
	}
	s->data = p->data;
	s->next = p->next;
	p->next = s;
	p->data = e;
	return true;
}

// 按位序删除
bool ListDelete(LinkList &L, int i, int  &e)
{
	if (i < 1)
	{
		return false;
	}
	if (i == 1)
	{
		e = L->data;
		L = L->next;
		return true;
	}
	LNode *p = L;
	int j = 1;
	while (p != NULL && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (p == NULL)
	{
		return false;
	}
	if (p->next == NULL)
	{
		return false;
	}
	LNode *q = p->next;
	e = q->data;
	p->next = q->next;
	free(q);
	return true;
}

// 指定节点删除
bool DeleteNode(LNode *p, LinkList &L)
{
	if (p == NULL)
	{
		return false;
	}
	if (p->next == NULL) // 传入节点是尾节点，只能从头开始遍历
	{
		LNode *s = L;
		while (s->next->next != NULL)
		{
			s = s->next;
		}
		free(s->next);
		s->next = NULL;
		return true;
	}
	LNode *s = p->next;
	p->data = s->data;
	p->next = s->next;
	free(s);
	return true;
}

// 按位查找 返回节点
LNode *GetElem(LinkList &L, int i)
{
	if (i < 1)
	{
		return false;
	}
	LNode *p = L;
	int j = 1;
	while (p != NULL && j < i)
	{
		p = p->next;
		j++;
	}
	return p;
}

bool ListInsert(LinkList &L, int i, int e)
{
	if (i < 1)
	{
		return false;
	}
	if (i == 1)
	{
		LNode *s = (LNode *)malloc(sizeof(LNode));
		s->data = e;
		s->next = L;
		L = s;
		return true;
	}
	int j = 1;
	//LNode *p = L;
	//while (p != NULL && j < i - 1)
	//{
	//	p = p->next;
	//	j++;
	//}
	LNode *p = GetElem(L, i - 1);
	//if (p == NULL)
	//{
	//	return false; // i不合法
	//}
	//LNode *s = (LNode *)malloc(sizeof(LNode));
	//s->data = e;
	//s->next = p->next;
	//p->next = s;
	InsertNextNode(p, e);
	return true;
}

// 按值查找 返回节点
LNode *LocateElem(LinkList &L, int e)
{
	LNode *p = L;
	while (p->data != e && p != NULL)
	{
		p = p->next;
	}
	return p;
}


// 表长
int length(LinkList L)
{
	int len = 0;
	LNode *p = L;
	while (p != NULL)
	{
		p = p->next;
		len++;
	}
	return len;
}
// 打印整个链表
void PrintList(LinkList L)
{
	while (L != NULL)
	{
		printf("我是：%d。\n", L->data);
		L = L->next;
	}
	return;
}

// 尾插法建立链表
void ListTailInsert(LinkList &L)
{
	LNode *s = NULL;
	LNode *r = NULL;
	int x = 0;
	scanf("%d", &x);
	s = (LNode *)malloc(sizeof(LNode));
	s->data = x;
	s->next = NULL;
	L = s;
	r = s;
	scanf("%d", &x);
	while (x != 9999)
	{
		s = (LNode *)malloc(sizeof(LNode));
		s->data = x;
		s->next = NULL;
		r->next = s;
		r = s;
		scanf("%d", &x);
	}
	return;
}

// 头插法建立链表
void ListHeadInsert(LinkList &L)
{
	LNode *s = NULL;
	int x = 0;
	scanf("%d", &x);
	s = (LNode *)malloc(sizeof(LNode));
	s->data = x;
	s->next = NULL;
	L = s;
	scanf("%d", &x);
	while (x != 9999)
	{
		s = (LNode *)malloc(sizeof(LNode));
		s->data = x;
		s->next = L;
		L = s;
		scanf("%d", &x);
	}
	return;
}

// 头插法实现链表逆置
void ReverseList(LinkList &L)
{
	LNode *p = L;
	LNode *r = NULL;
	L = NULL;
	while (p != NULL)
	{
		r = p;
		p = p->next;
		r->next = L;
		L = r;
	}
}

int main(void)
{
	LinkList L;
	InitList(L);
	// ListTailInsert(L);
	ListHeadInsert(L);
	PrintList(L);
	ReverseList(L);
	PrintList(L);

	system("pause");

	return 0;
}
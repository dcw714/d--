#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h> 

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ ,__LINE__)
#define new DBG_NEW
#endif
#endif 


typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode, *LinkList;

// 初始化
bool initList(LinkList &L)
{
	L = (LNode *)malloc(sizeof(LNode));
	L->next = NULL;
	return true;
}

// 尾插法建立链表
void listTailInsert(LinkList &L)
{
	LNode *s = (LNode *)malloc(sizeof(LNode));
	LNode *p = NULL;
	s->next = NULL;
	L = s;
	p = L;
	int x = 0;
	scanf("%d", &x);
	while (x != 9999)
	{
		s = (LNode *)malloc(sizeof(LNode));
		s->data = x;
		s->next = NULL;
		p->next = s;
		p = p->next;
		scanf("%d", &x);
	}
	return;
}

// 头插法建立链表
void listHeadInsert(LinkList &L)
{
	L = (LNode *)malloc(sizeof(LNode));
	L->next = NULL;
	int x = 0;
	scanf("%d", &x);
	LNode *p = NULL;
	// LNode *r = L->next;
	while (x != 9999)
	{
		p = (LNode *)malloc(sizeof(LNode));
		p->data = x;
		p->next = L->next;
		L->next = p;
		scanf("%d", &x);
	}
	return;
}

// 打印链表
void printList(LinkList &L)
{
	LNode *p = L->next;
	while (p != NULL)
	{
		printf("我是：%d\n", p->data);
		p = p->next;
	}
}

// 头插法反转链表 
void reverseList(LinkList &L)
{
	LNode *p = L->next;
	L->next = NULL;
	LNode *r = NULL;
	while (p != NULL)
	{
		r = p;
		p = p->next;
		r->next = L->next;
		L->next = r;
	}
}

// 销毁链表
bool destoryList(LinkList &L)
{
	LNode *p = L->next;
	LNode *r = L->next;
	while (p != NULL)
	{
		p = p->next;
		free(r);
		r = p;
	}
	L->next = NULL;
	return true;
}

// 判断链表是否为空
bool isEmpty(LinkList L)
{
	if (L->next == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// 链表长度
int length(LinkList L)
{
	int len = 0;
	LNode *p = L->next;
	while (p != NULL)
	{
		p = p->next;
		len++;
	}
	return len;
}

// 按位查找 返回节点
LNode *GetElem(LinkList L, int i)
{
	if (i < 1)
	{
		return NULL;
	}
	LNode *p = L;
	int j = 0;
	while (p != NULL && j < i)
	{
		p = p->next;
		j++;
	}
	return p;
}

// 按值查找 返回节点
LNode *LocateElem(LinkList L, int e)
{
	LNode *p = L->next;
	while (p != NULL && p->data != e)
	{
		p = p->next;
	}
	return p;
}

// 在指定节点后插入
bool insertNextNode(LNode *p, int e)
{
	if (p == NULL)
	{
		return false;
	}
	LNode *s = (LNode *)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

// 在指定节点前插入
bool insertPriorNode(LNode *p, int e)
{
	if (p == NULL)
	{
		return false;
	}
	LNode *s = (LNode *)malloc(sizeof(LNode));
	s->data = p->data;
	p->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

// 按位序插入
bool listInsert(LinkList &L, int i, int e)
{
	if (i < 1)
	{
		return false;
	}
	LNode *p = GetElem(L, i - 1);
	insertNextNode(p, e);
	return true;
}

// 按位序删除
bool listDelete(LinkList &L, int i, int &e)
{
	if (i < 1)
	{
		return false;
	}
	LNode *p = GetElem(L, i - 1);
	LNode *r = p->next;
	if (p == NULL || r == NULL)
	{
		return false;
	}
	p->next = r->next;
	e = r->data;
	free(r);
	r = NULL;
	return true;
}

// 指定节点删除
bool deleteNode(LNode *p, LinkList &L)
{
	if (p == NULL)
	{
		return false;
	}
	if (p->next == NULL)
	{
		LNode *r = L->next;
		while (r->next->next != NULL)
		{
			r = r->next;
		}
		r->next = p->next;
		free(p);
		p == NULL;
		return true;
	}
	LNode *r = p->next;
	p->data = r->data;
	p->next = r->next;
	free(r);
	r = NULL;
	return true;
}

int main(void)
{
	LinkList L;
	// initList(L);
	// listHeadInsert(L);
	listTailInsert(L);
	printList(L);
	// listInsert(L, 3, 3);
	//int e = 0;
	//listDelete(L, 3, e);
	deleteNode(L->next->next, L);
	printList(L);
	//printf("%d\n", e);
	// reverseList(L);
	// printf("翻转后\n");
	// printList(L);
	// destoryList(L);
	// printf("链表的长度为：%d.\n", length(L));

	// printf("位序为1的节点的数据为：%d。\n", GetElem(L, 3)->data);// 理应判断其返回值是否为空在使用
	//if (isEmpty(L))
	//{
	//	printf("链表为空。\n");
	//}
	destoryList(L);
	_CrtDumpMemoryLeaks();

	system("pause");
	return 0;
}
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

// ��ʼ��
bool initList(LinkList &L)
{
	L = (LNode *)malloc(sizeof(LNode));
	L->next = NULL;
	return true;
}

// β�巨��������
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

// ͷ�巨��������
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

// ��ӡ����
void printList(LinkList &L)
{
	LNode *p = L->next;
	while (p != NULL)
	{
		printf("���ǣ�%d\n", p->data);
		p = p->next;
	}
}

// ͷ�巨��ת���� 
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

// ��������
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

// �ж������Ƿ�Ϊ��
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

// ������
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

// ��λ���� ���ؽڵ�
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

// ��ֵ���� ���ؽڵ�
LNode *LocateElem(LinkList L, int e)
{
	LNode *p = L->next;
	while (p != NULL && p->data != e)
	{
		p = p->next;
	}
	return p;
}

// ��ָ���ڵ�����
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

// ��ָ���ڵ�ǰ����
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

// ��λ�����
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

// ��λ��ɾ��
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

// ָ���ڵ�ɾ��
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
	// printf("��ת��\n");
	// printList(L);
	// destoryList(L);
	// printf("����ĳ���Ϊ��%d.\n", length(L));

	// printf("λ��Ϊ1�Ľڵ������Ϊ��%d��\n", GetElem(L, 3)->data);// ��Ӧ�ж��䷵��ֵ�Ƿ�Ϊ����ʹ��
	//if (isEmpty(L))
	//{
	//	printf("����Ϊ�ա�\n");
	//}
	destoryList(L);
	_CrtDumpMemoryLeaks();

	system("pause");
	return 0;
}
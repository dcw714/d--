#include <stdio.h>
#include <stdlib.h>

#define INITSIZE 10 // 定义最大长度

typedef struct
{
	int *data;
	int MaxSize;
	int length;
}SeqList;

void InitList_(SeqList &L)
{
	L.data = (int *)malloc(sizeof(int) * INITSIZE);
	L.MaxSize = INITSIZE;
	L.length = 0;
	for (int i = 0; i < L.MaxSize; i++)
	{
		L.data[i] = 0;
	}

	return;
}

void IncreaseSize(SeqList &L, int len)
{
	int *p = L.data;
	L.data = (int *)malloc(sizeof(int) * (L.MaxSize + len));
	L.MaxSize = L.MaxSize + len;
	for (int i = 0; i < L.MaxSize; i++)
	{
		L.data[i] = 0;
	}
	for (int i = 0; i < L.length; i++)
	{
		L.data[i] = p[i];
	}
	free(p);
}

// 插入元素
bool ListInsert_(SeqList &L, int i, int e)
{
	if (i < 1 || i > L.length + 1)
	{
		return false;
	}
	if (L.length >= L.MaxSize)
	{
		return false;
	}
	for (int j = L.length; j >= i; j--)
	{
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;
	L.length++;
	return true;
}

// 删除元素
bool ListDelete(SeqList &L, int i, int &e)
{
	if (i < 1 || i > L.length)
	{
		return false;
	}
	e = L.data[i - 1];
	for (int j = i; j < L.length; j++)
	{
		L.data[j - 1] = L.data[j];
	}
	L.data[L.length - 1] = 0;
	L.length--;
	return true;
}

// 按位序查找
int GetElemt_(SeqList &L, int i)
{
	return L.data[i - 1];
}

//按值查找,返回位序
int LocateElemt_(SeqList &L, int e)
{
	for (int i = 0; i < L.length; i++)
	{
		if (e == L.data[i])
		{
			return i + 1;
		}
	}
	return 0;
}

void PrintList(SeqList &L)
{
	for (int i = 0; i < L.length; i++)
	{
		printf("位序为%d的元素是：%d。\n", i + 1, L.data[i]);
	}
	return;
}

// int main(void)
int main_seqlist(void)
{
	SeqList L;
	InitList_(L);
	ListInsert_(L, 1, 1);
	ListInsert_(L, 2, 2);
	ListInsert_(L, 3, 3);
	IncreaseSize(L, 10);

	for (int i = 4; i <= 19; i++)
	{
		ListInsert_(L, i, i);
	}
	ListInsert_(L, 9, 999);
	int e = -1;
	ListDelete(L, 9, e);
	printf("被删除的元素是%d。\n", e);
	PrintList(L);
	printf("位序为3的元素的值为：%d。\n", GetElemt_(L, 3));
	printf("值为：999的位序是：%d。\n", LocateElemt_(L, 10));
	system("pause");
	return 0;
}
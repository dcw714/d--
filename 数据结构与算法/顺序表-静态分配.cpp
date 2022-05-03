#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10 // 定义最大长度

typedef struct
{
	int data[MAXSIZE];
	int length;
}SqList;

void InitList(SqList &L)
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		L.data[i] = 0;
	}
	L.length = 0;
	return;
}

bool ListInsert(SqList &L, int i, int e)
{
	if (i < 1 || i > L.length + 1)
	{
		return false;
	}
	if (L.length >= MAXSIZE)
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

bool ListDelete(SqList &L, int i, int &e)
{
	if (i < 1 || i > L.length + 1)
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
int GetElemt(SqList &L, int i)
{
	return L.data[i - 1];
}


//按值查找,返回位序
int LocateElemt(SqList &L, int e)
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

void PrintList(SqList &L)
{
	for (int i = 0; i < L.length; i++)
	{
		printf("位序为%d的元素是%d。\n", i + 1, L.data[i]);
	}
	return;
}

// int main(void)
int main_sqlist(void)
{
	SqList L;
	InitList(L);
	if (ListInsert(L, 1, 99) == true)
	{
		printf("插入成功！");
	}
	else
	{
		printf("插入失败！");

	}
	ListInsert(L, 2, 999);
	ListInsert(L, 3, 9999);
	ListInsert(L, 4, 99999);
	ListInsert(L, 5, 999999);
	int e = -1;
	ListDelete(L, 5, e);
	printf("已删除位序为5的元素%d。\n", e);
	printf("位序为3的元素的值为：%d。\n", GetElemt(L, 3));
	printf("值为：999的位序是：%d。\n", LocateElemt(L, 999));
	ListInsert(L, 5, 1);
	ListInsert(L, 3, 1);
	ListInsert(L, 4, 1);
	PrintList(L);


	system("pause");
	return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10 // ������󳤶�

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

// ��λ�����
int GetElemt(SqList &L, int i)
{
	return L.data[i - 1];
}


//��ֵ����,����λ��
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
		printf("λ��Ϊ%d��Ԫ����%d��\n", i + 1, L.data[i]);
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
		printf("����ɹ���");
	}
	else
	{
		printf("����ʧ�ܣ�");

	}
	ListInsert(L, 2, 999);
	ListInsert(L, 3, 9999);
	ListInsert(L, 4, 99999);
	ListInsert(L, 5, 999999);
	int e = -1;
	ListDelete(L, 5, e);
	printf("��ɾ��λ��Ϊ5��Ԫ��%d��\n", e);
	printf("λ��Ϊ3��Ԫ�ص�ֵΪ��%d��\n", GetElemt(L, 3));
	printf("ֵΪ��999��λ���ǣ�%d��\n", LocateElemt(L, 999));
	ListInsert(L, 5, 1);
	ListInsert(L, 3, 1);
	ListInsert(L, 4, 1);
	PrintList(L);


	system("pause");
	return 0;
}
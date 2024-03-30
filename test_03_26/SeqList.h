#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLdatetype;
//动态顺序表
typedef struct SeqList
{
	SLdatetype* a;
	int size; //已存储的大小（个数）
	int capacity;//容量，实际存储空间容量的大小（个数）
}SL;

void SeqListcheckcapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLdatetype* tmp = (SLdatetype*)realloc(ps->a, newcapacity * sizeof(SLdatetype));
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
}

void SeqListinit(SL* ps)
{
	ps->a= NULL;
	ps->capacity = ps->size = 0;
}

void SeqListinsert(SL* ps, int pos, SLdatetype x)//插入
{
	assert(pos >= 0 && pos <= ps->size);
	SeqListcheckcapacity(ps);
	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[pos] = x;
	ps->size++;
}

void SeqListerase(SL* ps, int pos)//删除
{
	assert(pos >= 0 && pos < ps->size);
	int begin = pos + 1;
	while (begin < ps->size)
	{
		ps->a[begin -1] = ps->a[begin];
		begin++;
	}
	ps->size--;
}

void SeqListpushback(SL* ps, SLdatetype x)//尾插
{
    /*SeqListcheckcapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;*/
	SeqListinsert(ps,ps->size,x);
}

void SeqListpushfront(SL* ps, SLdatetype x)//头插
{
	//SeqListcheckcapacity(ps);
	//int end = ps->size - 1;
	//while(end>=0)
	//{	
	//	ps->a[end+1] = ps->a[end];
	//	end--;
	//}
	//ps->a[0] = x;
	//ps->size++;
	SeqListinsert(ps,0,x);
}

void SeqListpopback(SL* ps)
{
	/*assert(ps->size > 0);
	ps->size--;*/
	SeqListerase(ps, ps->size - 1);
}


void SeqListprintf(SL* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

void SeqListdestory(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

void SeqListpopfront(SL* ps)
{
	/*assert(ps->size > 0);
	int begin = 1;
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		begin++;
	}
	ps->size--;*/
	SeqListerase(ps, 0);
}



//接口函数，尽量写在后面
void SeqListpushback(SL* ps, SLdatetype x);//尾插
void SeqListpopback(SL* ps);//尾删
void SeqListinit(SL* ps);//函数初始化
void SeqListpushfront(SL* ps, SLdatetype x);//头插
void SeqListpopfront(SL* ps);//头删
void SeqListprintf(SL* ps);//打印
void SeqListdestory(SL* ps);//释放
void SeqListcheckcapacity(SL* ps);//检验空间是否足够
void SeqListinsert(SL* ps, int pos, SLdatetype x);//插入法（任意插入）
void SeqListerase(SL* ps, int pos);//删除（任意位置）

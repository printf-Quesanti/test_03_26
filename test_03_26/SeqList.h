#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLdatetype;
//��̬˳���
typedef struct SeqList
{
	SLdatetype* a;
	int size; //�Ѵ洢�Ĵ�С��������
	int capacity;//������ʵ�ʴ洢�ռ������Ĵ�С��������
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

void SeqListinsert(SL* ps, int pos, SLdatetype x)//����
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

void SeqListerase(SL* ps, int pos)//ɾ��
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

void SeqListpushback(SL* ps, SLdatetype x)//β��
{
    /*SeqListcheckcapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;*/
	SeqListinsert(ps,ps->size,x);
}

void SeqListpushfront(SL* ps, SLdatetype x)//ͷ��
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



//�ӿں���������д�ں���
void SeqListpushback(SL* ps, SLdatetype x);//β��
void SeqListpopback(SL* ps);//βɾ
void SeqListinit(SL* ps);//������ʼ��
void SeqListpushfront(SL* ps, SLdatetype x);//ͷ��
void SeqListpopfront(SL* ps);//ͷɾ
void SeqListprintf(SL* ps);//��ӡ
void SeqListdestory(SL* ps);//�ͷ�
void SeqListcheckcapacity(SL* ps);//����ռ��Ƿ��㹻
void SeqListinsert(SL* ps, int pos, SLdatetype x);//���뷨��������룩
void SeqListerase(SL* ps, int pos);//ɾ��������λ�ã�

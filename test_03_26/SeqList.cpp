#include"SeqList.h"
void TestSeqlist1()
{
	SL k;
	SeqListinit(&k);
	SeqListpushback(&k, 1);
	SeqListpushback(&k, 2);
	SeqListpushback(&k, 3);
	SeqListpushback(&k, 4);
	SeqListprintf(&k);
	SeqListpopback(&k);
	SeqListprintf(&k);
	SeqListerase(&k, 0);
	SeqListprintf(&k);

	SeqListdestory(&k);
}

void TestSeqList2()
{
	SL sl;
	SeqListinit(&sl);
	SeqListpushback(&sl, 1);
	SeqListpushback(&sl, 2);
	SeqListpushfront(&sl,3);
	SeqListpushfront(&sl, 4);
	SeqListprintf(&sl);
	SeqListpopfront(&sl);
	SeqListprintf(&sl);

	SeqListdestory(&sl);
}

void TestSeqList3()
{
	SL l;
	SeqListinit(&l);
	SeqListpushback(&l, 1);
	SeqListpushback(&l, 2);
	SeqListpushback(&l, 3);
	SeqListpushback(&l, 4);
	SeqListprintf(&l);
	SeqListinsert(&l,0,1);
	SeqListinsert(&l,3,4);
	SeqListprintf(&l);

	SeqListdestory(&l);
}

int main()
{
	TestSeqlist1();
	//TestSeqList2();
	//TestSeqList3();
	return 0;
}
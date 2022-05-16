#include"liststudent.h"
#include<iostream>
void test01()
{
	Student s1;
	Student s2(429,"dj");
	
	ListClass L;
	Student DateItem;
	bool Success;
	L.ListInsert(1, s1, Success);
	L.ListInsert(1, s2, Success);
	for (int i = 1; i <=L.ListLength(); i++)
	{
		L.ListRetrieve(i, DateItem, Success);
		DateItem.show();
	}

}
int main()
{
	test01();
	return 0;
}
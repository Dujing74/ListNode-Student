#include"liststudent.h"
#include<assert.h>
#include<stddef.h>
#include<iostream>
struct ListNode
{
	Student stu;
	ptrType Next = NULL;
};
//学生信息显示
void Student::show()
{
	cout << "学号： " << ID << " 姓名： " << name << endl;
}

//ListClass类的默认构造和复制构造
ListClass::ListClass():Size(0),Head(NULL){}
ListClass::ListClass(const ListClass& L) : Size(L.Size)
{
	if (L.Head == NULL)
		Head = NULL;
	else
	{
		Head = new ListNode;
		assert(Head != NULL);
		Head->stu = L.Head->stu;
		ptrType NewPtr = Head;
		for (ptrType OrigPtr = L.Head->Next; OrigPtr != NULL; OrigPtr = OrigPtr->Next)
		{
			NewPtr->Next = new ListNode;
			assert(NewPtr->Next != NULL);
			NewPtr = NewPtr->Next;
			NewPtr->stu = OrigPtr->stu;
		}
		NewPtr->Next=NULL;
	}
}
//ListClass的析构，防止内存泄漏
ListClass::~ListClass()
{
	bool Success;
	while (!ListIsEmpty())
		ListDelete(1, Success);
}
//判断链表是否为空
bool ListClass::ListIsEmpty()const
{
	return bool(Size == 0);
}
//得到链表节点数
int ListClass::ListLength()const
{
	return Size;
}
//遍历链表节点
ptrType ListClass::PtrTo(int Position)const
{
	if ((Position < 1) || (Position > ListLength()))
		return NULL;
	else
	{
		ptrType cur = Head;
		for (int i = 1; i < Position; i++)
		{
			cur = cur->Next;
		}
		return cur;
	}
}
//插入节点，头插
void ListClass::ListInsert(int NewPosition, Student NewItem, bool& Success)
{
	int NewLength = ListLength() + 1;
	Success = bool((NewPosition >= 1 && NewPosition <= NewLength));
	if (Success)
	{
		ptrType NewPtr = new ListNode;
		if (NewPtr != NULL)
		{
			Size = NewLength;
			NewPtr->stu = NewItem;
			if (NewPosition == 1)
			{
				NewPtr->Next = Head;
				Head = NewPtr;
			}
			else
			{
				ptrType Prev = PtrTo(NewPosition - 1);
				NewPtr->Next = Prev->Next;
				Prev->Next = NewPtr;
			}
		}
	}
}
//删除指定位置节点
void ListClass::ListDelete(int Position, bool& Success)
{
	ptrType cur;
	Success = bool((Position >= 1) && (Position <= Size));
	if (Success)
	{
		Size--;
		if (Position == 1)
		{
			cur = Head;
			Head = Head->Next;
		}
		else
		{
			ptrType prev = PtrTo(Position - 1);
			cur = prev->Next;
			prev = cur->Next;
		}
		delete cur;
		cur = NULL;
	}
}
//取回节点数据
void ListClass::ListRetrieve(int Position, Student& DateItem, bool& Success)const
{
	Success = bool((Position >= 1) && (Position) <= Size);
	if (Success)
	{
		ptrType cur = PtrTo(Position);
		DateItem = cur->stu;
	}
}

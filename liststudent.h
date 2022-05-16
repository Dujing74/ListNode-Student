#pragma once
#include<string>
using namespace std;
struct ListNode;
//typedef class Student SI;
typedef ListNode* ptrType;
class Student
{
private:
	int ID;
	string name;
public:
	Student(int ID=0,string name="noName") :ID(ID), name(name) {}
	~Student() {}
	void show();
};
class ListClass
{
private:
	int Size;//链表的节点个数
	ptrType Head;
	ptrType PtrTo(int Position)const;//遍历节点函数
public:
	ListClass();
	ListClass(const ListClass& L);
	~ListClass();
	bool ListIsEmpty()const;
	int ListLength()const;
	void ListInsert(int NewPosition, Student NewItem, bool& success);
	void ListDelete(int Position, bool& success);
	void ListRetrieve(int Position, Student& DateItem, bool& Success)const;
};
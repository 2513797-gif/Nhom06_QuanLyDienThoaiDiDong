#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <iomanip>

#include "ThuVien.h"

using namespace std;

struct NodeList {
	DienThoai data;
	NodeList* pNext;
};
struct List {
	NodeList* pHead;
	NodeList* pTail;
};
void InitList(List& l) {
	l.pHead = NULL;
	l.pTail = NULL;
}
NodeList* CreateNodeList(DienThoai dt) {
	NodeList* p = new NodeList;
	if (p == NULL) {
		return NULL;
	}
	p->data = dt;
	p->pNext = NULL;
	return p;
}
void AddTail(List& l, DienThoai dt) {
	NodeList* p = CreateNodeList(dt);
	if (p == NULL) {
		return;
	}
	if (l.pHead == NULL) {
		l.pHead = p;
		l.pTail = p;
	}
	else {
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
void RemoveAllList(List& l) {
	NodeList* p;
	while (l.pHead != NULL) {
		p = l.pHead;
		l.pHead = l.pHead->pNext;
		delete p;
	}
	l.pHead = l.pTail = NULL;
}
void chuyenCaysangDSLK(Tree root, List& l) {
	if (root != NULL) {
		chuyenCaysangDSLK(root->left, l);
		AddTail(l, root->data);
		chuyenCaysangDSLK(root->right, l);
	}
}
void XuatDSLK(List list, int& stt) {
	NodeList* p = list.pHead;
	while (p != NULL) {
		if(stt == 1)
			xuatTieuDe();
		xuatDienThoai(p->data, stt++);
		p = p->pNext;
	}
}
int SoSanhUuTien(DienThoai &a, DienThoai &b) {
	int cmp = _stricmp(a.tenDT, b.tenDT);
	if (cmp > 0)
		return 1;
	if (cmp < 0)
		return -1;
	if (a.namSX > b.namSX)
		return 1;
	if (a.namSX < b.namSX)
		return -1;
	if (a.giaBan > b.giaBan)
		return 1;
	if (a.giaBan < b.giaBan)
		return -1;
	return strcmp(a.maDT, b.maDT);
}
void SelectionSort_List(List& l) {
	for (NodeList* p = l.pHead; p != NULL; p = p->pNext) {
		NodeList* minNode = p;
		NodeList* q = p->pNext;
		while (q != NULL) {
			if (SoSanhUuTien(q->data, minNode->data) < 0) {
				minNode = q;
			}
			q = q->pNext;
		}
		if(minNode != p) {
			DienThoai temp = p->data;
			p->data = minNode->data;
			minNode->data = temp;
		}
	}
}
void InsertionSort_List(List& l) {
	if (l.pHead == NULL || l.pHead->pNext == NULL) 
		return;
	NodeList* sortedHead = NULL;
	NodeList* current = l.pHead;

	while (current != NULL) {
		NodeList* nextNode = current->pNext;

		if (sortedHead == NULL || SoSanhUuTien(current->data, sortedHead->data) < 0) {
			current->pNext = sortedHead;
			sortedHead = current;
		}
		else {
			NodeList* p = sortedHead;
			while (p->pNext != NULL && SoSanhUuTien(p->pNext->data, current->data) < 0) {
				p = p->pNext;
			}
			current->pNext = p->pNext;
			p->pNext = current;
		}
		current = nextNode;
	}
	l.pHead = sortedHead;
	NodeList* temp = l.pHead;
	while (temp != NULL && temp->pNext != NULL) {
		temp = temp->pNext;
	}
	l.pTail = temp;
}
void TachDoiList(NodeList* source, NodeList*& head1, NodeList*& head2) {
	NodeList* fast = source->pNext;
	NodeList* slow = source;

	while (fast != NULL) {
		fast = fast->pNext;
		if (fast != NULL) {
			slow = slow->pNext;
			fast = fast->pNext;
		}
	}

	head1 = source;
	head2 = slow->pNext;
	slow->pNext = NULL; 
}
NodeList* TronHaiList(NodeList* a, NodeList* b) {
	NodeList dummy;
	NodeList* tail = &dummy;
	dummy.pNext = NULL;

	while (a != NULL && b != NULL) {
		if (SoSanhUuTien(a->data, b->data) <= 0) {
			tail->pNext = a;
			a = a->pNext;
		}
		else {
			tail->pNext = b;
			b = b->pNext;
		}
		tail = tail->pNext;
	}
	tail->pNext = (a != NULL) ? a : b;
	return dummy.pNext;
}
void MergeSort_Node(NodeList*& head) {
	if (head == NULL || head->pNext == NULL) return;

	NodeList* head1 = NULL;
	NodeList* head2 = NULL;

	TachDoiList(head, head1, head2);

	MergeSort_Node(head1);
	MergeSort_Node(head2);

	head = TronHaiList(head1, head2);
}
void MergeSort_List(List& l) {
	if (l.pHead == NULL || l.pHead->pNext == NULL) return;

	MergeSort_Node(l.pHead);

	NodeList* temp = l.pHead;
	while (temp != NULL && temp->pNext != NULL) {
		temp = temp->pNext;
	}
	l.pTail = temp;
}
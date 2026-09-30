#include <iostream>
#include <conio.h>

#include "ThuVien.h"
#include "ThuVien2.h"
#include "Menu.h"

using namespace std;

void ChayChuongTrinh();

int main() {

	ChayChuongTrinh();
	return 0;
}
void ChayChuongTrinh() {
	Tree root = NULL;
	List l;
	InitList(l);
	Init(root);
	XuLyMenu(root, l);
	
	RemoveTree(root); // Xóa toàn bộ dữ liệu cây khi thoát chương trình.
	RemoveAllList(l); // Xóa toàn bộ dữ liệu DSLK khi thoát chương trình.
}
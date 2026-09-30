#pragma once
#include <iostream>
#include <conio.h>

#include "ThuVien.h"
#include "ThuVien2.h"

using namespace std;

void Menu() {
	cout << "=============== MENU ===============" << endl;
	cout << "1.  Doc danh sach dien thoai tu file." << endl;
	cout << "2.  Xuat danh sach Dien thoai." << endl;
	cout << "3.  Them mot dien thoai moi thu cong." << endl;
	cout << "4.  Tim kiem dien thoai theo ma, ten, hang, nam san xuat." << endl;
	cout << "5.  Sua thong tin dien thoai." << endl;
	cout << "6.  Xoa dien thoai theo ma, ten, hang..." << endl;
	cout << "7.  Thong ke xem co bao nhieu hang dien thoai." << endl;
	cout << "8.  Tim dien thoai co gia ban cao nhat, thap nhat." << endl;
	cout << "9.  Thong ke tat ca cac dien thoai da ban, ton kho va xuat thong tin." << endl;
	cout << "10. Tim kiem hang dien thoai ban duoc nhieu nhat, it nhat." << endl;
	cout << "11. Sap xep dien thoai theo ten neu trung ten thi theo nam SX neu trung nam Sx thi theo gia ban." << endl;
	cout << "12. Luu danh sach dien thoai vao file." << endl;
	cout << "13. Tinh tong gia ban dien thoai." << endl;
	cout << "14. Tim dien thoai theo khoang gia." << endl;
	cout << "0.  Thoat chuong trinh." << endl;
}
void Menu_TongGiaBan() {
	cout << "===== Menu Tinh Tong Gia Ban =====" << endl;
	cout << "1. Tong gia ban tat ca dien thoai." << endl;
	cout << "2. Tong gia ban cac dien thoai da ban." << endl;
	cout << "3. Tong gia ban cac dien thoai ton kho." << endl;
}
void Menu_Duyet() {
	cout << "===== Menu Xuat File =====" << endl;
	cout << "1. Duyet theo kieu NLR." << endl;
	cout << "2. Duyet theo kieu LNR." << endl;
	cout << "3. Duyet theo kieu RLN." << endl;
}
void Menu_XuatFile() {
	cout << "===== Menu Duyet =====" << endl;
	cout << "1. Xuat theo kieu NLR." << endl;
	cout << "2. Xuat theo kieu LNR." << endl;
	cout << "3. Xuat theo kieu RLN." << endl;
	cout << "4. Xuat so do phan cap cay." << endl;
}
void MenuTimKiem() {
	cout << "===== Menu Tim Kiem =====" << endl;
	cout << "1. Tim kiem theo ma." << endl;
	cout << "2. Tim kiem theo ten." << endl;
	cout << "3. Tim kiem theo hang." << endl;
	cout << "4. Tim kiem tat ca dien thoai co namSX <= nam can tim." << endl;
}
void xuLyTimKiem(Tree root, int chon) {
	char maCanTim[20], tenCanTim[30], hangCanTim[20];
	int namSXCanTim;
	int stt = 1;
	switch (chon) {
	case 1: {
		cout << "Nhap ma can tim: ";
		cin >> maCanTim;
		int stt = 1;
		Node* p = TimNodeTheoMa(root, maCanTim, stt);
		if (p != NULL) {
			cout << "\n>> THONG TIN DIEN THOAI TIM THAY:" << endl;
			xuatTieuDe();
			xuatDienThoai(p->data, 1);
		}
		else {
			cout << "\n>> Khong tim thay dien thoai co ma: " << maCanTim << endl;
		}
		break;
	}
	case 2:
		cout << "Nhap ten can tim: ";
		cin.ignore();
		cin.getline(tenCanTim, 30);
		TimKiemTheoTen(root, tenCanTim, stt);
		break;
	case 3:
		cout << "Nhap hang can tim: ";
		cin >> hangCanTim;
		TimKiemTheoHang(root, hangCanTim, stt);
		break;
	case 4:
		cout << "Nhap nam san xuat can tim: ";
		cin >> namSXCanTim;
		TimKiemTheoNamSX2(root, namSXCanTim, stt);
		break;
	default:
		cout << "Chon khong hop le | Moi chon lai." << endl;
	}
}
void MenuSuaThongTin() {
	cout << "===== Menu Sua Thong Tin =====" << endl;
	cout << "1. Sua ten Dien thoai." << endl;
	cout << "2. Sua hang Dien thoai." << endl;
	cout << "3. Sua nam san xuat Dien thoai." << endl;
	cout << "4. Sua gia ban Dien thoai." << endl;
	cout << "5. sua trang thai Dien Thoai." << endl;
	cout << "0. Thoat chuc nang sua thong tin." << endl;
}
void ThucHienSuaThongTin(DienThoai& dt) {
	int chose;
	do {
		MenuSuaThongTin();
		cout << "Chon chuc nang sua thong tin: ";
		cin >> chose;
		switch (chose)
		{
		case 1:
			cout << "Nhap Ten Dien thoai moi: ";
			cin >> dt.tenDT;
			break;
		case 2:
			cout << "Nhap Hang Dien thoai moi: ";
			cin >> dt.hangDT;
			break;
		case 3:
			cout << "Nhap Nam san xuat Dien thoai moi: ";
			cin >> dt.namSX;
			break;
		case 4:
			cout << "Nhap Gia ban Dien thoai moi: ";
			cin >> dt.giaBan;
			break;
		case 5:
			cout << "Nhap trang thai moi: ";
			cin >> dt.tinhTrang;
			break;
		default:
			cout << "Chon khong hop le!" << endl;
			break;
		}
	} while (chose != 0);
}
void MenuXoaDienThoai() {
	cout << "\n===== MENU XOA DIEN THOAI =====" << endl;
	cout << "1. Xoa dien thoai theo Ma (Xoa 1 may)" << endl;
	cout << "2. Xoa tat ca dien thoai theo Ten" << endl;
	cout << "3. Xoa tat ca dien thoai theo Hang" << endl;
	cout << "0. Quay lai menu chinh" << endl;
	cout << "Chon kieu xoa: ";
}
void XuLyXoaNode(Tree& root) {
	int chon;
	char maCanXoa[20], tenCanXoa[30], hangCanXoa[20];
	int stt = 1;
	MenuXoaDienThoai();
	cin >> chon;
	switch (chon) {
	case 1:
		cout << "Nhap ma dien thoai can xoa: ";
		cin >> maCanXoa;
		ChuyenInHoa(maCanXoa);
		if (XoaNodeTheoMa(root, maCanXoa))
			cout << "Da xoa thanh cong dien thoai co ma: " << maCanXoa << endl;
		else
			cout << "Khong tim thay dien thoai co ma: " << maCanXoa << endl;
		break;
	case 2: {
		cout << "Nhap ten dien thoai can xoa: ";
		cin.ignore();
		cin.getline(tenCanXoa, 30);
		int countTen = XoaTatCaNodeTheoTen(root, tenCanXoa);
		if (countTen > 0)
			cout << "Da xoa thanh cong " << countTen << " dien thoai co ten: " << tenCanXoa << endl;
		else
			cout << "Khong tim thay dien thoai co ten: " << tenCanXoa << endl;
		break;
	}
	case 3: {
		cout << "Nhap hang dien thoai can xoa: ";
		cin >> hangCanXoa;
		int countHang = XoaTatCaNodeTheoHang(root, hangCanXoa);
		if (countHang > 0)
			cout << "Da xoa thanh cong " << countHang << " dien thoai co hang: " << hangCanXoa << endl;
		else
			cout << "Khong tim thay dien thoai co hang: " << hangCanXoa << endl;
		break;
	}
	case 0:
		cout << "Quay lai menu chinh." << endl;
		break;
	default:
		cout << "Chon khong hop le." << endl;
		break;
	}
}
void MenuSapXep() {
	cout << "\n===== MENU SAP XEP DIEN THOAI =====" << endl;
	cout << "1. Selection Sort." << endl;
	cout << "2. Insertion Sort." << endl;
	cout << "3. Merge Sort." << endl;
}
void XuLySapXep(List& l, Tree root) {
	int chon;
	int stt = 1;
	RemoveAllList(l); // Xóa hết dữ liệu DSLK nếu trước đó từng sắp xếp.

	chuyenCaysangDSLK(root, l); // chuyển dữ liệu từ cây sang DSLK để phục cho chức năng sắp xếp.
	MenuSapXep();
	cout << "Chon kieu sap xep: ";
	cin >> chon;
	switch (chon) {
	case 1:
		SelectionSort_List(l);
		XuatDSLK(l, stt);
		cout << "Da sap xep danh sach dien thoai theo Selection Sort." << endl;
		break;
	case 2:
		InsertionSort_List(l);
		XuatDSLK(l, stt);
		cout << "Da sap xep danh sach dien thoai theo Insertion Sort." << endl;
		break;
	case 3:
		MergeSort_List(l);
		XuatDSLK(l, stt);
		cout << "Da sap xep danh sach dien thoai theo Merge Sort." << endl;
		break;
	default:
		cout << "Chon khong hop le." << endl;
		break;
	}
}
void XuLyMenu(Tree& root, List& l) {
	int chose;
	char filename[30];
	char maCanTim[20], tenCanTim[30], hangCanTim[20];
	int namSXCanTim;
	int stt;
	do {
		system("cls");
		Menu();
		cout << "Chon chuc nang: ";
		cin >> chose;
		switch (chose) {
		case 1:
			cout << "Nhap ten file: ";
			cin >> filename;
			if (!DocTuFile(filename, root))
				cout << "Doc file that bai!." << endl;
			else
				cout << "Doc file thanh cong | so luong dien thoai la: " << DemTongNode(root) << endl;
			break;
		case 2:
			stt = 1;
			int chon;
			Menu_Duyet();
			cout << "Chon cac duyet: ";
			cin >> chon;
			if (root == NULL) {
				cout << "Danh Sach rong!." << endl;
				break;
			}
			if (chon == 1)
				Duyet_NLR(root, stt);
			else if (chon == 2)
				Duyet_LNR(root, stt);
			else if (chon == 3)
				Duyet_RLN(root, stt);
			else {
				cout << "Chon khong hop le | Moi chon lai." << endl;
				continue;
			}
			break;
		case 3:
			ThemDienThoaiThuCong(root);
			break;
		case 4: {
			int chon2;
			MenuTimKiem();
			cout << "Chon chuc nang tim kiem: ";
			cin >> chon2;
			xuLyTimKiem(root, chon2);
			break;
		}
		case 5: {
			cout << "Nhap ma dien thoai can sua: ";
			cin >> maCanTim;
			stt = 1;
			Node* p = TimNodeTheoMa(root, maCanTim, stt);
			if (p == NULL) {
				cout << "Khong tim thay dien thoai co ma: " << maCanTim << endl;
			}
			else {
				cout << "Thong tin dien thoai truoc khi sua: " << endl;
				xuatTieuDe();
				xuatDienThoai(p->data, 1);
				ThucHienSuaThongTin(p->data);
				cout << "Thong tin dien thoai sau khi sua: " << endl;
				xuatTieuDe();
				xuatDienThoai(p->data, 1);
			}
			break;
		}
		case 6:
			XuLyXoaNode(root);
			break;
		case 7:
			ThongKeCacHangDT(root);
			break;
		case 8: {
			stt = 1;
			int chon3;
			cout << "1. Tim dien thoai co gia ban cao nhat." << endl;
			cout << "2. Tim dien thoai co gia ban thap nhat." << endl;
			cout << "Chon chuc nang: ";
			cin >> chon3;
			double maxGia = TimGiaMax(root);
			double minGia = TimGiaThapNhat(root);
			if (chon3 == 1) {
				XuatDienThoaiGiaMax(root, maxGia, stt);
			}
			else if (chon3 == 2) {
				XuatDienThoaiGiaMin(root, minGia, stt);
			}
			else {
				cout << "Chon khong hop le | Moi chon lai." << endl;
				continue;
			}
			break;
		}
		case 9: {
			stt = 1;
			int chon4;
			cout << "1. Xuat Danh sach dien thoai da ban." << endl;
			cout << "2. Xuat Danh sach dien thoai ton kho." << endl;
			cout << "3. Thong ke so luong dien thoai da ban va ton kho." << endl;
			cout << "Chon chuc nang: ";
			cin >> chon4;
			if (chon4 == 1) {
				XuatDienThoaiTheoTrangThai(root, true, stt);
			}
			else if (chon4 == 2) {
				XuatDienThoaiTheoTrangThai(root, false, stt);
			}
			else if (chon4 == 3) {
				int soLuongDaBan = DemSoLuongDienThoaiTheoTrangThai(root, true);
				int soLuongTonKho = DemSoLuongDienThoaiTheoTrangThai(root, false);
				cout << "So luong dien thoai da ban: " << soLuongDaBan << endl;
				cout << "So luong dien thoai ton kho: " << soLuongTonKho << endl;
			}
			else {
				cout << "Chon khong hop le | Moi chon lai." << endl;
				continue;
			}
			break;
		}
		case 10: {
			TimHangBanNhieuNhatItNhat(root);
			break;
		}
		case 11: {
			XuLySapXep(l, root);
			break;
		}
		case 12: {
			if (root == NULL) {
				cout << "Hien tai danh sach rong! Khong the in ra file." << endl;
				break;
			}
			int xuat;
			Menu_XuatFile();
			cout << "Chon kieu xuat: ";
			cin >> xuat;
			cout << "Nhap ten file can luu: ";
			cin >> filename;

			int kq = 0;
			if (xuat >= 1 && xuat <= 3) {
				kq = LuuVaoFile(filename, root, xuat);
			}
			else if (xuat == 4) {
				kq = XuatSoDoCayVaoFile(root, filename);
			}
			else {
				cout << "Tuy chon khong hop le!" << endl;
				break;
			}
			if (kq == 1)
				cout << "Luu file thanh cong!" << endl;
			else if (kq == 0)
				cout << "Loi: Khong the tao hoac mo file de ghi!" << endl;
			break;
		}
		case 13: {
			if (root == NULL) {
				cout << "Danh sach rong, khong co du lieu de tinh!" << endl;
				break;
			}
			int chon5;
			Menu_TongGiaBan();
			cout << "Chon chuc nang: ";
			cin >> chon5;
			double tong = 0;
			if (chon5 == 1) {
				tong = TinhTongGiaBan(root);
				cout << "Tong gia ban tat ca dien thoai: " << fixed << setprecision(0) << tong << " VND" << endl;
			}
			else if (chon5 == 2) {
				tong = TinhTongGiaBanTheoTrangThai(root, true);
				cout << "Tong gia ban cac dien thoai da ban: " << fixed << setprecision(0) << tong << " VND" << endl;
			}
			else if (chon5 == 3) {
				tong = TinhTongGiaBanTheoTrangThai(root, false);
				cout << "Tong gia ban cac dien thoai ton kho: " << fixed << setprecision(0) << tong << " VND" << endl;
			}
			else {
				cout << "Chon khong hop le | Moi chon lai." << endl;
				continue;
			}
			break;
		}
		case 14: {
			if (root == NULL) {
				cout << "Danh sach rong, khong co du lieu de tim!" << endl;
				break;
			}
			double giaMin, giaMax;
			stt = 1;
			cout << "Nhap gia thap nhat (VND): ";
			cin >> giaMin;
			cout << "Nhap gia cao nhat (VND): ";
			cin >> giaMax;
			if (giaMin > giaMax) {
				cout << "Loi: Gia thap nhat phai nho hon hoac bang gia cao nhat!" << endl;
				break;
			}
			double tongGiaKhoang = 0;
			TimDienThoaiTheoKhoangGia(root, giaMin, giaMax, stt);
			if (stt == 1)
				cout << "Khong tim thay dien thoai nao trong khoang gia tu " << fixed << setprecision(0) << giaMin << " den " << giaMax << " VND." << endl;
			else
				cout << "==> Tong so dien thoai tim duoc: " << (stt - 1) << endl;
			break;
		}
		case 0:
			cout << "THOAT CHUONG TRINH." << endl;
			break;
		default:
			cout << "Chuc nang vua chon khong hop le. Vui long chon lai!." << endl;
			system("pause");
			continue;
		}
		system("pause");
	} while (chose != 0);
}


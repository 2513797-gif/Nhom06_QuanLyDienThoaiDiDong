#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <limits>

using namespace std;

struct DienThoai {
	char maDT[15];
	char tenDT[30];
	char hangDT[20];
	int namSX;
	double giaBan;
	bool tinhTrang;
};
struct tagNode {
	DienThoai data;
	tagNode* left;
	tagNode* right;
};
typedef tagNode Node;
typedef Node* Tree;
void Init(Tree& root) {
	root = NULL;
}
int IsEmpty(Tree& root) {
	return root == NULL;
}
Node* CreateNode(DienThoai dt) {
	Node* newNode = new Node();
	if (newNode != NULL) {
		newNode->data = dt;
		newNode->left = NULL;
		newNode->right = NULL;
	}
	return newNode;
}
int InsertNode(Tree& root, DienThoai dt) {
	if (root == NULL) {
		root = CreateNode(dt);
		return (root != NULL) ? 1 : 0;
	}
	int cmp = strcmp(dt.maDT, root->data.maDT);
	if (cmp == 0)
		return 0;
	if (cmp < 0)
		return InsertNode(root->left, dt);
	return InsertNode(root->right, dt);
}
void RemoveTree(Tree& root) {
	if (root != NULL) {
		RemoveTree(root->left);
		RemoveTree(root->right);
		delete root;
		root = NULL;
	}
}
void xuatTieuDe() {
	cout << setfill('=') << setw(90) << "" << setfill(' ') << endl;
	cout << left
		<< setw(3) << "STT" << "||"
		<< setw(10) << "Ma DT" << "||"
		<< setw(23) << "Ten DT" << "||"
		<< setw(10) << "Hang" << "||"
		<< setw(8) << "Nam SX" << "||"
		<< setw(10) << "Gia Ban" << "||"
		<< setw(12) << "Trang Thai" << "||" << endl;
	cout << setfill('-') << setw(90) << "" << setfill(' ') << endl;
}

void xuatDienThoai(DienThoai dt, int stt) {
	cout << left
		<< setw(3) << stt << "||"
		<< setw(10) << dt.maDT << "||"
		<< setw(23) << dt.tenDT << "||"
		<< setw(10) << dt.hangDT << "||"
		<< setw(8) << dt.namSX << "||"
		<< fixed << setprecision(0) << setw(10) << dt.giaBan << "||"
		<< setw(12) << (dt.tinhTrang ? "Da ban" : "Ton kho") << "||" << endl;
	cout << setfill('-') << setw(90) << "" << setfill(' ') << endl;
}
void XuatDanhSach(Tree root, int& stt) {
	if (stt == 1)
		xuatTieuDe();
	xuatDienThoai(root->data, stt++);
}
int DocTuFile(const char* filename, Tree& root) {
	ifstream input(filename);
	if (!input)
		return 0;
	RemoveTree(root);
	Init(root);

	DienThoai dt;
	int tt;
	while (input >> dt.maDT >> dt.tenDT >> dt.hangDT >> dt.namSX >> dt.giaBan >> tt) {
		dt.tinhTrang = (tt == 1);
		InsertNode(root, dt);
	}
	input.close();
	return 1;
}
int DemTongNode(Tree root) {
	if (root == NULL)
		return 0;
	return 1 + DemTongNode(root->left) + DemTongNode(root->right);
}
void Duyet_LNR(Tree root, int& stt) {
	if (root != NULL) {
		Duyet_LNR(root->left, stt);
		XuatDanhSach(root, stt);
		Duyet_LNR(root->right, stt);
	}
}
void Duyet_NLR(Tree root, int& stt) {
	if (root != NULL) {
		XuatDanhSach(root, stt);
		Duyet_NLR(root->left, stt);
		Duyet_NLR(root->right, stt);
	}
}
void Duyet_RLN(Tree root, int& stt) {
	if (root != NULL) {
		Duyet_RLN(root->right, stt);
		Duyet_RLN(root->left, stt);
		XuatDanhSach(root, stt);
	}
}
void GhiNode(Tree root, ofstream& out) {
	out << root->data.maDT << " "
		<< root->data.tenDT << " "
		<< root->data.hangDT << " "
		<< root->data.namSX << " "
		<< fixed << setprecision(0) << root->data.giaBan << " "
		<< (root->data.tinhTrang ? 1 : 0) << "\n";
}
void GhiNode_NLR(Tree root, ofstream& out) {
	if (root != NULL) {
		GhiNode(root, out);
		GhiNode_NLR(root->left, out);
		GhiNode_NLR(root->right, out);
	}
}
void GhiNode_LNR(Tree root, ofstream& out) {
	if (root != NULL) {
		GhiNode_LNR(root->left, out);
		GhiNode(root, out);
		GhiNode_LNR(root->right, out);
	}
}
void GhiNode_RLN(Tree root, ofstream& out) {
	if (root != NULL) {
		GhiNode_RLN(root->right, out);
		GhiNode_RLN(root->left, out);
		GhiNode(root, out);
	}
}
int LuuVaoFile(const char* filename, Tree root, int n) {
	if (root == NULL) {
		return -1;
	}
	ofstream out(filename);
	if (!out) {
		return 0;
	}
	if (n == 1) {
		GhiNode_NLR(root, out);
		out.close();
		return 1;
	}
	else if (n == 2) {
		GhiNode_LNR(root, out);
		out.close();
		return 1;
	}
	else if (n == 3) {
		GhiNode_RLN(root, out);
		out.close();
		return 1;
	}
	out.close();
	return -1;
}
void ChuyenInHoa(char* str) {
	for (int i = 0; str[i] != '\0'; i++) {
		str[i] = toupper(str[i]);
	}
}
bool KiemTraTrungMa(Tree root, const char* maDT) {
	if (root == NULL)
		return false;
	int cmp = strcmp(maDT, root->data.maDT);
	if (cmp == 0)
		return true;
	if (cmp < 0)
		return KiemTraTrungMa(root->left, maDT);
	return KiemTraTrungMa(root->right, maDT);
}
void ThemDienThoaiThuCong(Tree& root) {
	DienThoai dt;
	cout << "\n================ THEM DIEN THOAI MOI ================\n";

	char MaDT[15];
	cout << "Nhap Ma DT: ";
	cin >> MaDT;

	ChuyenInHoa(MaDT);
	while (KiemTraTrungMa(root, MaDT)) {
		cout << "\n>> LOI: Ma dien thoai '" << MaDT << "' da ton tai tren cay!" << endl;
		cout << "Moi ban nhap lai maDT." << endl;
		cout << "Nhap maDT: ";
		cin >> MaDT;
		ChuyenInHoa(MaDT);
	}
	strcpy_s(dt.maDT, sizeof(dt.maDT), MaDT);
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Nhap Ten DT: ";
	cin.getline(dt.tenDT, sizeof(dt.tenDT));

	cout << "Nhap Hang DT: ";
	cin.getline(dt.hangDT, sizeof(dt.hangDT));

	cout << "Nhap Nam san xuat: ";
	cin >> dt.namSX;

	cout << "Nhap Gia ban (VND): ";
	cin >> dt.giaBan;

	dt.tinhTrang = 0;

	int ketQua = InsertNode(root, dt);
	if (ketQua == 1) {
		cout << "\n>> THEM DIEN THOAI THANH CONG!" << endl;
	}
	else {
		cout << "\n>> LOI: Khong the chen vao cay (bo nho day hoac loi he thong)!" << endl;
	}
}
Node* TimNodeTheoMa(Tree root, const char* maCanTim, int& stt) {
	if (root == NULL)
		return 0;
	int cmp = strcmp(maCanTim, root->data.maDT);
	if (cmp == 0) {
		return root;
	}
	else if (cmp < 0)
		return TimNodeTheoMa(root->left, maCanTim, stt);
	return TimNodeTheoMa(root->right, maCanTim, stt);
}
void TimKiemTheoTen(Tree root, const char* tenCanTim, int& stt) {
	if (root != NULL) {
		TimKiemTheoTen(root->left, tenCanTim, stt);
		if (_stricmp(root->data.tenDT, tenCanTim) == 0) {
			if (stt == 1)
				xuatTieuDe();
			xuatDienThoai(root->data, stt++);
		}
		TimKiemTheoTen(root->right, tenCanTim, stt);
	}
}
void TimKiemTheoHang(Tree root, const char* hangCanTim, int& stt) {
	if (root != NULL) {
		TimKiemTheoHang(root->left, hangCanTim, stt);
		if (_stricmp(root->data.hangDT, hangCanTim) == 0) {
			if (stt == 1)
				xuatTieuDe();
			xuatDienThoai(root->data, stt++);
		}
		TimKiemTheoHang(root->right, hangCanTim, stt);
	}
}
void TimKiemTheoNamSX2(Tree root, int namSXCanTim, int& stt) {
	if (root == NULL)
		return;
	TimKiemTheoNamSX2(root->left, namSXCanTim, stt);
	if (root->data.namSX <= namSXCanTim) {
		if (stt == 1)
			xuatTieuDe();
		xuatDienThoai(root->data, stt++);
	}
	TimKiemTheoNamSX2(root->right, namSXCanTim, stt);
}
void TimNodeThayThe(Node*& Xoa, Node*& ThayThe) {
	if (ThayThe->left != NULL) {
		TimNodeThayThe(Xoa, ThayThe->left);
	}
	else {
		Xoa->data = ThayThe->data;
		Xoa = ThayThe;
		ThayThe = ThayThe->right;
	}
}
int XoaNodeTheoMa(Tree& root, const char* maCanXoa) {
	if (root == NULL)
		return 0;
	int cmp = strcmp(maCanXoa, root->data.maDT);
	if (cmp < 0)
		return XoaNodeTheoMa(root->left, maCanXoa);
	else if (cmp > 0)
		return XoaNodeTheoMa(root->right, maCanXoa);
	Node* Xoa = root;
	if (root->left == NULL && root->right == NULL) {
		root = NULL;
	}
	else if (root->left == NULL)
		root = root->right;
	else if (root->right == NULL)
		root = root->left;
	else
		TimNodeThayThe(Xoa, root->right);
	delete Xoa;
	return 1;
}
Node* TimNodeTheoTen(Tree root, const char* tenCanTim) {
	if (root == NULL)
		return NULL;
	if (_stricmp(root->data.tenDT, tenCanTim) == 0)
		return root;
	Node* p = TimNodeTheoTen(root->left, tenCanTim);
	if (p != NULL)
		return p;
	return TimNodeTheoTen(root->right, tenCanTim);
}
int XoaTatCaNodeTheoTen(Tree& root, const char* tenCanXoa) {
	if (root == NULL)
		return 0;
	int count = 0;
	while (true) {
		Node* p = TimNodeTheoTen(root, tenCanXoa);
		if (p == NULL)
			break;
		XoaNodeTheoMa(root, p->data.maDT);
		count++;
	}
	return count;
}
Node* TimNodeTheoHang(Tree root, const char* hangCanTim) {
	if (root == NULL)
		return NULL;
	if (_stricmp(root->data.hangDT, hangCanTim) == 0)
		return root;
	Node* p = TimNodeTheoHang(root->left, hangCanTim);
	if (p != NULL)
		return p;
	return TimNodeTheoHang(root->right, hangCanTim);
}
int XoaTatCaNodeTheoHang(Tree& root, const char* hangCanXoa) {
	if (root == NULL)
		return 0;
	int count = 0;
	while (true) {
		Node* p = TimNodeTheoHang(root, hangCanXoa);
		if (p == NULL)
			break;
		XoaNodeTheoMa(root, p->data.maDT);
		count++;
	}
	return count;
}
bool DaXuatHienTruoc(Tree root, const char* hang, const char* maHienTai) {
	if (root == NULL)
		return false;
	if (strcmp(root->data.maDT, maHienTai) < 0 && _stricmp(root->data.hangDT, hang) == 0)
		return true;
	return DaXuatHienTruoc(root->left, hang, maHienTai) || DaXuatHienTruoc(root->right, hang, maHienTai);
}

void DuyetVaInHang(Tree root, Tree goc, int& soHang) {
	if (root == NULL) return;

	DuyetVaInHang(root->left, goc, soHang);
	if (!DaXuatHienTruoc(goc, root->data.hangDT, root->data.maDT)) {
		soHang++;
		cout << " " << soHang << ". " << root->data.hangDT << endl;
	}

	DuyetVaInHang(root->right, goc, soHang);
}

void ThongKeCacHangDT(Tree root) {
	if (IsEmpty(root)) {
		cout << "Cay rong, khong co du lieu!" << endl;
		return;
	}

	int soHang = 0;
	cout << "\n===== DANH SACH CAC HANG DIEN THOAI =====" << endl;
	DuyetVaInHang(root, root, soHang);
	cout << "-----------------------------------------" << endl;
	cout << "==> Tong cong co: " << soHang << " hang dien thoai." << endl;
}
double TimGiaMax(Tree root) {
	if (root == NULL) return 0;
	double maxGia = root->data.giaBan;

	if (root->left != NULL) {
		double leftMax = TimGiaMax(root->left);
		if (leftMax > maxGia) maxGia = leftMax;
	}
	if (root->right != NULL) {
		double rightMax = TimGiaMax(root->right);
		if (rightMax > maxGia) maxGia = rightMax;
	}
	return maxGia;
}
void XuatDienThoaiGiaMax(Tree root, double maxGia, int& stt) {
	if (root == NULL) return;

	XuatDienThoaiGiaMax(root->left, maxGia, stt);
	if (root->data.giaBan == maxGia) {
		if (stt == 1) xuatTieuDe();
		xuatDienThoai(root->data, stt++);
	}
	XuatDienThoaiGiaMax(root->right, maxGia, stt);
}
double TimGiaThapNhat(Tree root) {
	if (root == NULL) return 0;
	double minGia = root->data.giaBan;

	if (root->left != NULL) {
		double leftMin = TimGiaThapNhat(root->left);
		if (leftMin < minGia) minGia = leftMin;
	}
	if (root->right != NULL) {
		double rightMin = TimGiaThapNhat(root->right);
		if (rightMin < minGia) minGia = rightMin;
	}
	return minGia;
}
void XuatDienThoaiGiaMin(Tree root, double minGia, int& stt) {
	if (root == NULL) return;

	XuatDienThoaiGiaMin(root->left, minGia, stt);
	if (root->data.giaBan == minGia) {
		if (stt == 1) xuatTieuDe();
		xuatDienThoai(root->data, stt++);
	}
	XuatDienThoaiGiaMin(root->right, minGia, stt);
}
void XuatDienThoaiTheoTrangThai(Tree root, bool trangThai, int& stt) {
	if (root == NULL)
		return;
	XuatDienThoaiTheoTrangThai(root->left, trangThai, stt);
	if (root->data.tinhTrang == trangThai) {
		if (stt == 1)
			xuatTieuDe();
		xuatDienThoai(root->data, stt++);
	}
	XuatDienThoaiTheoTrangThai(root->right, trangThai, stt);
}
int DemSoLuongDienThoaiTheoTrangThai(Tree root, bool trangThai) {
	if (root == NULL)
		return 0;
	int count = DemSoLuongDienThoaiTheoTrangThai(root->left, trangThai);
	if (root->data.tinhTrang == trangThai)
		count++;
	count += DemSoLuongDienThoaiTheoTrangThai(root->right, trangThai);
	return count;
}
int DemSoLuongBanTheoHang(Tree root, const char* tenHang) {
	if (root == NULL)
		return 0;

	int count = (_stricmp(root->data.hangDT, tenHang) == 0 && root->data.tinhTrang == true) ? 1 : 0;

	return count + DemSoLuongBanTheoHang(root->left, tenHang)
		+ DemSoLuongBanTheoHang(root->right, tenHang);
}
void DuyetVaThongKeBanTheoHang(Tree root, Tree goc, int& soHang,
	int& maxBan, int& minBan, int& tongDaBan) {
	if (root == NULL) return;

	DuyetVaThongKeBanTheoHang(root->left, goc, soHang, maxBan, minBan, tongDaBan);

	if (!DaXuatHienTruoc(goc, root->data.hangDT, root->data.maDT)) {
		soHang++;
		int soLuongBan = DemSoLuongBanTheoHang(goc, root->data.hangDT);
		tongDaBan += soLuongBan;

		cout << left << setw(6) << soHang << "||"
			<< setw(20) << root->data.hangDT << "||"
			<< setw(18) << soLuongBan << "||" << endl;

		if (soHang == 1) {
			maxBan = minBan = soLuongBan;
		}
		else {
			if (soLuongBan > maxBan) maxBan = soLuongBan;
			if (soLuongBan < minBan) minBan = soLuongBan;
		}
	}

	DuyetVaThongKeBanTheoHang(root->right, goc, soHang, maxBan, minBan, tongDaBan);
}
void InCacHangTheoMucBan(Tree root, Tree goc, int mucBan, bool& first) {
	if (root == NULL) return;

	InCacHangTheoMucBan(root->left, goc, mucBan, first);

	if (!DaXuatHienTruoc(goc, root->data.hangDT, root->data.maDT)) {
		if (DemSoLuongBanTheoHang(goc, root->data.hangDT) == mucBan) {
			if (!first) cout << ", ";
			cout << root->data.hangDT;
			first = false;
		}
	}

	InCacHangTheoMucBan(root->right, goc, mucBan, first);
}
void TimHangBanNhieuNhatItNhat(Tree root) {
	if (IsEmpty(root)) {
		cout << "Cay rong, khong co du lieu de thong ke!" << endl;
		return;
	}

	cout << "\n================ BANG THONG KE SO LUONG DA BAN THEO HANG ================\n";
	cout << left << setw(6) << "STT" << "||"
		<< setw(20) << "Ten Hang" << "||"
		<< setw(18) << "So Luong Da Ban" << "||" << endl;
	cout << setfill('-') << setw(48) << "" << setfill(' ') << endl;

	int soHang = 0;
	int maxBan = 0, minBan = 0;
	int tongDaBan = 0;

	DuyetVaThongKeBanTheoHang(root, root, soHang, maxBan, minBan, tongDaBan);
	cout << setfill('-') << setw(48) << "" << setfill(' ') << endl;

	if (soHang == 0) return;

	if (tongDaBan == 0) {
		cout << "\n>> THONG BAO: Chua co bat ky dien thoai nao duoc ban trong he thong!" << endl;
		return;
	}
	cout << "\n>> Hang BAN DUOC NHIEU NHAT (" << maxBan << " san pham): ";
	bool first = true;
	InCacHangTheoMucBan(root, root, maxBan, first);
	cout << endl;

	cout << ">> Hang BAN DUOC IT NHAT   (" << minBan << " san pham): ";
	first = true;
	InCacHangTheoMucBan(root, root, minBan, first);
	cout << endl;
}
void GhiNhanhCay2DFile(Tree root, ofstream& out, string prefix, bool isLeft, bool isRoot) {
	if (root == NULL)
		return;

	if (root->right != NULL) {
		GhiNhanhCay2DFile(root->right, out, prefix + (isLeft ? "|   " : "    "), false, false);
	}

	out << prefix;
	if (isRoot) {
		out << "[GOC] ";
	}
	else if (isLeft) {
		out << "\\--- (L) ";
	}
	else {
		out << "/--- (R) ";
	}
	out << root->data.maDT << "\n";

	if (root->left != NULL) {
		GhiNhanhCay2DFile(root->left, out, prefix + (isLeft ? "    " : "|   "), true, false);
	}
}
int XuatSoDoCayVaoFile(Tree root, const char* filename) {
	if (IsEmpty(root)) {
		return -1;
	}

	ofstream out(filename);
	if (!out) {
		return 0;
	}

	out << "================ SO DO PHAN CAP CAY NHI PHAN ================\n\n";
	GhiNhanhCay2DFile(root, out, "", true, true);
	out << "\n==============================================================\n";

	out.close();
	return 1;
}
double TinhTongGiaBan(Tree root) {
	if (root == NULL)
		return 0;
	return root->data.giaBan + TinhTongGiaBan(root->left) + TinhTongGiaBan(root->right);
}
double TinhTongGiaBanTheoTrangThai(Tree root, bool trangThai) {
	if (root == NULL)
		return 0;
	double tong = (root->data.tinhTrang == trangThai) ? root->data.giaBan : 0;
	return tong + TinhTongGiaBanTheoTrangThai(root->left, trangThai)
		+ TinhTongGiaBanTheoTrangThai(root->right, trangThai);
}
void TimDienThoaiTheoKhoangGia(Tree root, double giaMin, double giaMax, int& stt) {
	if (root == NULL)
		return;
	TimDienThoaiTheoKhoangGia(root->left, giaMin, giaMax, stt);
	if (root->data.giaBan >= giaMin && root->data.giaBan <= giaMax) {
		if (stt == 1)
			xuatTieuDe();
		xuatDienThoai(root->data, stt++);
	}
	TimDienThoaiTheoKhoangGia(root->right, giaMin, giaMax, stt);
}


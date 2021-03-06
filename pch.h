
#ifndef PCH_H
#define PCH_H

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std; 

class Sach
{
protected: 
	string MaSach; 
	string TenSach; 
	string TacGia;
	string NhaXuatBan; 
	long GiaSach; 
public:
	Sach() {};
	virtual ~Sach() {};
	virtual void nhap(); 
	virtual void xuat(); 
	virtual void docFile(string chuoi); 
	virtual void xuatFile(); 
	virtual void xuatFile(string tenfile) { cout << "xuat file co tham so: ";  };
	virtual void ghiFilePhieuMuon(string tenfile);
	virtual string getMaSach()
	{
		return MaSach;
	}
	virtual void ghiPhieu()
	{
		cout << "\nMa Sach: " << MaSach << ", Ten sach: " << TenSach << ", Tac gia: " << TacGia << endl;
	}
	
};
class SachTiengViet : public Sach
{
public: 
	SachTiengViet() {};
	~SachTiengViet() {};
	void nhap();
	void xuat();
	void xuatFile();
	void xuatFile(string tenfile);
	void docFile(string chuoi);
};

class SachNgoaiVan : public Sach
{
	string ISBN; 
public: 
	SachNgoaiVan() {};
	//SachNgoaiVan(string newISBN, string newMS, string newTen, string newNXB, long GiaS)
	~SachNgoaiVan() {};

	void nhap(); 
	void xuat(); 
	void xuatFile();
	void xuatFile(string tenfile);
	void docFile(string chuoi);
};

class ThuVien : public Sach
{
	vector <Sach*> BookList; 
public: 
	ThuVien() {};
	~ThuVien() {
		for (int i = 0; i < BookList.size(); i++)
			delete BookList[i];
	};
	void Them();
	void Xoa();
	void Sua();
	void TimKiem(); 
	void CapNhat(); 
	void docFile();
	int kiemtra(string IDSach);
	void menu();
	Sach* getSachbyMaSach(string inMaSach);
};

class MyDate
{
public:
	int day; 
	int month;
	int year; 
	MyDate() { day = 1; month = 1; year = 1900; };
	MyDate(int nday, int nmonth, int nyear)
	{
		day = nday;
		month = nmonth;
		year = nyear; 
	}
	~MyDate() {};
	
};
//__________
int tinhNamNhuan(MyDate d);
int tinhNgay(MyDate ngaydau, MyDate ngaycuoi);
int ngayHopLe(int ngay, int thang, int nam);
//__________

class NguoiMuon : public Sach, public ThuVien
{
protected: 
	string ID; 
	string HoTen;
	MyDate NgayMuon; 

	int sosach; 
	vector <Sach*> SachDangMuon; 
public:
	NguoiMuon() {};
	~NguoiMuon()
	{
		for (int i = 0; i < SachDangMuon.size(); i++)
			delete SachDangMuon[i]; 
	}
	void nhapPhieuMuon(); 
	void nhapthongtin();
	void xuatFile();
	void xuatFile(string tenfile);
	void docFile(string chuoi);
	void hienthi();
	
	string getTenDocGia()
	{
		return HoTen;
	}
	string getID()
	{
		return ID; 
	}
};
class DanhSachNguoiMuon: public NguoiMuon
{
	vector <NguoiMuon*> DanhSachDocGia;
public: 
	DanhSachNguoiMuon() {};
	~DanhSachNguoiMuon() {
		for (int i = 0; i < DanhSachDocGia.size(); i++)
			delete DanhSachDocGia[i];
	}
	void docFileDocGia();
	//void docFilePhieuMuon();
	void Them();
	void SuaDocGia();
	void Xoa();
	void menu();
	void capnhat();
	void timkiemdocgia();

};

class Phieu : public NguoiMuon, public Sach, public ThuVien
{
protected:
	NguoiMuon docgia;
	int soSach;
	string MaSoPhieu;
	vector <Sach*> ListSach;
	MyDate ngayLapPhieu;
public:
    Phieu() {};
	virtual ~Phieu()
	{
		for (int i = 0; i < ListSach.size(); i++)
			delete ListSach[i];
	}
	virtual void nhap();
//	virtual string getMaSoPhieu() { return MaSoPhieu; };
	virtual void hienthi();
	virtual void setNgayLapPhieu(int ngay, int thang, int nam)
	{
		ngayLapPhieu.day = ngay;
		ngayLapPhieu.month = thang;
		ngayLapPhieu.year = nam;
	}
	virtual void xuatfile(string tenfile,string tenfilenho);
	virtual void docfilephieu(string tenfile) {
		cout << "Ham ao";
	};
	virtual MyDate getNgayLapPhieu() {
		return ngayLapPhieu;
	}
	virtual string getMaSoPhieu()
	{
		return MaSoPhieu;
	}
	//virtual void docPhieuDon(string tenchuoi); // doc tung phieu mot
	//void virtual themphieu(string tenfile);
	virtual void ghifileIDvaNgayMuon(string tenfilenho);
};
struct scanIDNgayMuon
{
	string MaPhieu;
	MyDate NgayMuon;
};
class DanhSachPhieuMuon : public Phieu
{
	vector <Phieu*> ListMuon;
	vector <scanIDNgayMuon*> ListScan; 
public:
	DanhSachPhieuMuon() {};
	~DanhSachPhieuMuon() {
		for (int i = 0; i < ListMuon.size(); i++)
			delete ListMuon[i];
	}
	void docfilephieu(string tenfile) {};
	void themphieu(string tenfile);
	void docfileIDvsNgaymuon();
	int kiemtraID(string maso);
	MyDate layngaytuID(string maso);

//	string getMaSoPhieu() {};
//	MyDate getNgayLapPhieu() {};
};
class DanhSachPhieuTra :public Phieu, public DanhSachPhieuMuon
{
	vector <Phieu*> ListTra; 
	vector <scanIDNgayMuon*> ListScanTra;

public:
	DanhSachPhieuTra() {};
	~DanhSachPhieuTra() {
		for (int i = 0; i < ListTra.size(); i++)
			delete ListTra[i];
	}
//	void nhap(); 
//	void docfilephieu(string tenfile);
	void themphieu(string tenfile);

	void docfileIDvsNgayTra();
	void lietkeListQuaHan(); 
}; 
void Menu();

#endif //PCH_H

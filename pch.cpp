

#include "pch.h"


/// ham tinh ngay: 
int tinhNamNhuan(MyDate d)
{
	int nam = d.year;
	if (d.month <= 2)
		nam--;
	return nam / 4 - nam / 100 + nam / 400;
}
int tinhNgay(MyDate ngaydau, MyDate ngaycuoi)
{
	const int monthDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	long int n1 = ngaydau.year*365+ngaydau.day;
	for (int i = 0; i < ngaydau.month-1; i++)
	{
		n1 += monthDays[i];
	}
	n1 += tinhNamNhuan(ngaydau);

	long int n2 = ngaycuoi.year*365+ngaycuoi.day;
	for (int i = 0; i < ngaycuoi.month-1; i++)
	{
		n2 += monthDays[i];
	}
	n2 += tinhNamNhuan(ngaycuoi);
	return (n2 - n1);
} 
int ngayHopLe(int ngay, int thang, int nam)
{
	int ngaymax;
	if (nam < 0 || thang < 0 || thang> 12 || ngay < 0 || ngay> 31)
	{
		return -1; // khong hop le 
	}
	else
	{
		switch (thang)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			ngaymax = 31;
			break;
		case 2:
			if ((nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0))
				ngaymax = 29;
			else
				ngaymax = 28;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			ngaymax = 30;
			break;
		}
		if (ngay <= ngaymax)
		{
			return 1; // hop le; 
		}
		else
		{
			return -1; // KHONG hop le
		}
	}
}

////

void Sach::nhap()
{
	cin.ignore();
	cout << "\n-Nhap Ma Sach: "; 
//	cin.ignore(); 
	getline(cin, MaSach);
	cout << "-Nhap ten sach: ";
//	cin.ignore();
	getline(cin, TenSach);
	cout << "-Nhap tac gia: "; 
//	cin.ignore();
	getline(cin, TacGia);
	cout << "-Nhap NXB: ";
//	cin.ignore();
	getline(cin, NhaXuatBan);
	cout << "-Nhap gia sach: ";
	cin >> GiaSach; 
	
}
void Sach::xuat()
{
	cout << "\nMa Sach__Ten Sach___Tac Gia___NXB____GiaSach: \n"; 
	cout << MaSach << "_" << TenSach << "_" << TacGia << "_" << NhaXuatBan << "_" << GiaSach << "\n";

}
void Sach::xuatFile()
{
	fstream fout; 
	fout.open("ThongTinSach.txt", ios::out|ios::app);
	fout << "\n" << MaSach << "," << TenSach << "," << TacGia << "," << NhaXuatBan << "," << GiaSach << endl;
	fout.close();
} 
void SachNgoaiVan::nhap()
{
	cout << "Nhap tt cho sach ngoai van: ";
	Sach::nhap();
	cin.ignore();
	cout << "-Nhap so ISBN: ";
	getline(cin, ISBN);
}
void SachNgoaiVan::xuat()
{
	//cout << "\nNgoaiVan_ISBN_Ma Sach__Ten Sach___Tac Gia___NXB____GiaSach: ";
	cout << "\nNgoaiVan"<<", ISBN: "<<ISBN<<", Ma Sach:" << MaSach << ", Ten Sach: " << TenSach << ", Tac Gia:" 
		<< TacGia << ", NXB: " << NhaXuatBan << ", Gia: " << GiaSach << "VND";
}
void SachNgoaiVan::xuatFile()
{
	fstream fout;
	fout.open("ThongTinSach.txt", ios::out | ios::app);
	fout << "NgoaiVan" << "," << ISBN <<"," <<MaSach << "," << TenSach << "," << TacGia << "," << NhaXuatBan << "," << GiaSach<<endl;
	fout.close();
}
void SachTiengViet::nhap()
{
	cout << "Nhap tt cho sach tieng viet: ";
	Sach::nhap();
}
void SachTiengViet::xuat()
{
	//cout << "\nTiengViet_ISBN_Ma Sach__Ten Sach___Tac Gia___NXB____GiaSach:";
	cout << "\nTiengViet"<<", Ma Sach: "<<MaSach << ", Ten Sach: " << TenSach 
		<< ", Tac Gia: " << TacGia << ", NXB: " << NhaXuatBan << ", Gia:" << GiaSach << "VND";
}
void SachTiengViet::xuatFile()
{
	fstream fout;
	fout.open("ThongTinSach.txt", ios::out | ios::app);
	fout << "TiengViet" << "," << MaSach << "," << TenSach << "," << TacGia << "," << NhaXuatBan << "," << GiaSach << endl;
	fout.close();
}
void ThuVien::Them()
{
	this->docFile();
	int choice; 
	cout << "-Them sach ngoai van: nhap 1 \n-Them sach Tieng Viet: nhap 2 \n -->>lua chon:  "; 
	cin >> choice; 
	while ((choice < 1) && (choice > 2))
	{
		cout << "\Nhap sai, nhap lai: ";
		cin >> choice;
	}
	int n = BookList.size();
	BookList.resize(n + 1);
	if (choice == 1)
	{
		BookList[n] = new  SachNgoaiVan;
	}
	else if (choice == 2)
	{

		BookList[n] = new SachTiengViet;

	}
	BookList[n]->nhap();
	BookList[n]->xuatFile();
	cout << "\n So sach sau khi them: " << BookList.size();
	BookList.resize(n);
}
void ThuVien::Xoa()
{
	this->docFile();
	string chuoixoa; 
	cout << "\nNhap ma sach can xoa: "; 
	cin >> chuoixoa; 
	for (int i = 0; i < BookList.size(); i++)
	{
		if (BookList[i]->getMaSach() == chuoixoa)
			BookList.erase(BookList.begin() + i);
		else
			cout << "\nKhong tim thay sach can xoa !";
	}

}
void ThuVien::Sua()
{
	this->docFile();
	string sua; 
	cout << "\Nhap ma sach can sua: ";
	cin >> sua; 
	for (int i = 0; i < BookList.size(); i++)
	{
		if (BookList[i]->getMaSach() == sua)
		{
			cout << "\nDa tim thay, moi ban nhap lai cac thong tin !";
			BookList[i]->nhap();
		}
		else
			cout << "\nKhong tim thay sach can xoa !";
	}
}
void ThuVien::TimKiem()
{
	this->docFile();
	string timkiem;
	cout << "\Nhap ma sach can tim kiem: ";
	cin >> timkiem;
	for (int i = 0; i < BookList.size(); i++)
	{
		if (BookList[i]->getMaSach() == timkiem)
		{
			cout << "\nDa tim thay, moi ban xem thong tin !";
			BookList[i]->xuat();
		}
		else
			cout << "\nKhong tim thay sach can xoa !";
	}
}
int ThuVien::kiemtra(string IDSach)
{
	this->docFile();
	int flag = 0;
	for (int i = 0; i < BookList.size(); i++)
	{
		if (BookList[i]->getMaSach() == IDSach)
		{
			flag = 1;
		}

	}
	return flag;
}
void ThuVien::CapNhat()
{
	fstream fout;
	fout.open("ThongTinSach.txt", ios::out);
	for (int i = 0; i < BookList.size(); i++)
	{
		BookList[i]->xuatFile();
	}
	fout.close();
} 
void ThuVien::docFile()
{
	ifstream filein;
	filein.open("ThongTinSach.txt",ios::in);
	//BookList.erase(BookList.begin() + BookList.size());
	BookList.erase(BookList.begin(), BookList.end());
	while (!filein.eof())
	{

		string line; 
		while (getline(filein,line))
		{
			
			string buff; 
			istringstream linestream(line);
			getline(linestream, buff, ',');
		//	cout << " \n+++buff cuoi: " << buff <<"end"; 
			if (buff == "") break;
			int n = BookList.size();
			BookList.resize(n + 1);
		//	cout << "\n::buff-177:" << buff << ":::";
			if (buff == "NgoaiVan")
			{
				BookList[n] = new SachNgoaiVan;
	//			cout << "\n::buff0ngoaivan::"<<buff<<":::";
				//BookList[n]->docFile(chuoi);
			}
			else if (buff=="TiengViet")
			{
				BookList[n] = new SachTiengViet;
	//			cout << "\n::buff0tiengviet:"<< buff<<":::";
				//BookList[n]->docFile(chuoi);
			}
			BookList[n]->docFile(line);
		//	cout << "\n::buff-189 so luong:" << buff <<"___" << n << ":::";
		}
	}
	filein.close();

}
Sach* ThuVien::getSachbyMaSach(string inMaSach)
{
	this->docFile();
	for (int i = 0; i < BookList.size(); i++)
	{
		if (BookList[i]->getMaSach() == inMaSach)
		{
			//cout << "\nDa tim thay, moi ban xem thong tin !";
			return BookList[i];
		}
	}
}


void ThuVien::menu()
{
	cout << "\n********Menu Thu Vien********";
	cout << "\n >>>>de thuan tien, lam phien ban tra cuu ma sach dan o cua so \nde thuan tien cho viec tim kiem !";
	cout << "\n+Xem tat ca sach hien co: nhan 1";
	cout << "\n+Them sach: nhan 2";
	cout << "\n+Tim kiem thong tin sach: nhan 3"; 
	cout << "\n+Xoa sach: nhan 4"; 
	cout << "\n+Sua thong tin sach: nhan 5"; 
	cout << "\n+Thoat: nhan 0 \n ";
	int choice; 
	cin >> choice;
	if (choice == 0) return; 
	while (choice != 0) {
		while ((choice < 0) || (choice > 5))
		{
			cout << "\NHap Sai, moi ban nhap lai";
			cin >> choice;
		}
		switch (choice)
		{
		case 1:
			cout << "\n>>>>Tat ca sach: ";
			//cout << "Ssso sach: " << BookList.size();
			//BookList.erase(BookList.begin(),BookList.end());
			this->docFile();
			cout << "\ndoc file xong, so sach hien co: " << BookList.size();
			for (int i = 0; i < BookList.size(); i++)
			{
				cout << "\n"<< i+1 << "/ ";
				BookList[i]->xuat();
			}
			break;
		case 2:
			cout << "\n**Them \n";
			ThuVien::Them();
			//ThuVien::CapNhat();
			break;
		case 3:
			cout << "\n**Tim Kiem \n";
			ThuVien::TimKiem();
			ThuVien::CapNhat();
			break;
		case 4:
			cout << "\n**Xoa Sach\n";
			ThuVien::Xoa();
			cout << "\nDa Xoa";
			ThuVien::CapNhat();
			cout << "\nDa cap nhat";
			break;
		case 5:
			cout << "\n**Sua\n";
			ThuVien::Sua();
			ThuVien::CapNhat();
			break;
		case 0:
			break;
		}
		cout << "\n\n>>>> Lua chon tiep trong menu de thuc hien cong viec: ";
		cout << "\n>>>>>Menu Thu Vien<<<<<";
		cout << "\n >>>>de thuan tien, lam phien ban tra cuu ma sach dan o cua so \nde thuan tien cho viec tim kiem !";
		cout << "\n+Xem tat ca sach hien co: nhan 1";
		cout << "\n+Them sach: nhan 2";
		cout << "\n+Tim kiem thong tin sach: nhan 3";
		cout << "\n+Xoa sach: nhan 4";
		cout << "\n+Sua thong tin sach: nhan 5";
		cout << "\n+Thoat: nhan 0 \n ";
		cin >> choice; 
	}
} 
void Sach::docFile(string chuoi)
{
	cout << "ham ao";
}
void Sach::ghiFilePhieuMuon(string tenfile)
{
	fstream fout;
	fout.open(tenfile, ios::out | ios::app);
	fout << "Ma Sach: " << MaSach << ", Ten sach: " << TenSach << ", Tac gia: " << TacGia << endl;
	fout.close();
}
void SachNgoaiVan::docFile(string chuoi)
{
	string temp1;
	istringstream iss(chuoi);
	string token;
	string a[7];
	int ind = 0;
	while (getline(iss, token, ','))
	{
		a[ind] = token;
	//	cout << "\n>>>>" << a[ind] << " ind" << ind;
		ind++;
	};
	this->ISBN = a[1];
	this->MaSach = a[2];
	this->TenSach = a[3];
	this->TacGia = a[4];
	this->NhaXuatBan = a[5];
	this->GiaSach = stol(a[6], nullptr, 10);
	//cout << "\n DOC FILE NV XONG \n";
}
void SachTiengViet::docFile(string chuoi)
{
	string temp1;
	istringstream iss(chuoi);
	string token;
	//string *a = new string;
	string a[6];
	int ind = 0;
	while (getline(iss, token, ','))
	{
	    a[ind] = token;
	//	cout << "\n>>>>" << a[ind] <<" ind" << ind;
		ind++;
	};

	this->MaSach = a[1];
	this->TenSach = a[2];
	this->TacGia = a[3];
	this->NhaXuatBan = a[4];
	this->GiaSach = stol(a[5], nullptr, 10);
	//cout << "\n DOC FILE TV XONG \n";
	//delete a;
}

void SachNgoaiVan::xuatFile(string tenfile)
{
	fstream fout;
	fout.open(tenfile, ios::out | ios::app);
	fout << "NgoaiVan" << "," << ISBN << "," << MaSach << "," << TenSach << "," << TacGia << "," << NhaXuatBan << "," << GiaSach << endl;
	fout.close();
}
void SachTiengViet::xuatFile(string tenfile)
{
	fstream fout;
	fout.open(tenfile, ios::out | ios::app);
	fout << "TiengViet" << "," << MaSach << "," << TenSach << "," << TacGia << "," << NhaXuatBan << "," << GiaSach << endl;
	fout.close();
}


void NguoiMuon::nhapPhieuMuon()
{
	 
	cout << "\n-Nhap Ten:  ";
	cin.ignore(); 
	getline(cin, HoTen);
	cout << "-\n-Nhap ID thu vien: ";
	//	cin.ignore();
	getline(cin, ID);
	int sosach; 
	cout << "\n Nhap so sach dang muon: ";
	cin >> sosach;
	cout << "\n-Nhap sach dang muon (toi da 3 quyen):  ";
	while ((sosach > 3) || (sosach < 0)) { cout << "\n Nhap lai so sach: "; cin >> sosach; }
	SachDangMuon.resize(sosach);
	for (int i = 0; i < sosach; i++)
	{
		int choice;
		cout << "-Them sach ngoai van: nhap 1 \n-Them sach Tieng Viet: nhap 2 \n -->>lua chon:  ";
		cin >> choice;
		while ((choice < 1) && (choice > 2))
		{
			cout << "\Nhap sai, nhap lai: ";
			cin >> choice;
		}

		if (choice == 1)
		{
			SachDangMuon[i] = new  SachNgoaiVan;
		}
		else if (choice == 2)
		{

			SachDangMuon[i] = new SachTiengViet;

		}
		SachDangMuon[i]->nhap();
	}
} 
void NguoiMuon::nhapthongtin()
{
	//cin.ignore();
	cout << "\n-Nhap Ten:  ";
	//	cin.ignore(); 
	getline(cin, HoTen);
	cout << "-Nhap ID thu vien: ";
	//	cin.ignore();
	getline(cin, ID);
}
void NguoiMuon::docFile(string chuoi)
{
	string temp1;
	istringstream iss(chuoi);
	string token;
	string a[2];
	int ind = 0;
	getline(iss, token, ':');
	while (getline(iss, token, ','))
	{
		a[ind] = token;
		//	cout << "\n>>>>" << a[ind] << " ind" << ind;
		ind++;
	};
	this->HoTen = a[0];
	this->ID = a[1];
}
void NguoiMuon::xuatFile()
{
	fstream fout;
	fout.open("ThongTinDocGia.txt", ios::out | ios::app);
	fout <<"Ten:"<< HoTen << "," << ID << endl; 
/*	for (int i = 0; i < SachDangMuon.size(); i++)
	{
		SachDangMuon[i]->xuatFile("DanhSachNguoiMuon.txt");
	}*/
	fout.close();
}
void NguoiMuon::xuatFile(string tenfile)
{
	fstream fout;
	fout.open(tenfile, ios::out | ios::app);
	fout << "Ten:" << HoTen << "," << ID << endl;
	/*	for (int i = 0; i < SachDangMuon.size(); i++)
		{
			SachDangMuon[i]->xuatFile("DanhSachNguoiMuon.txt");
		}*/
	fout.close();
}

void NguoiMuon::hienthi()
{
	cout << "Ten:" << HoTen << "," << ID << endl;
} 

void DanhSachNguoiMuon::docFileDocGia()
{
	ifstream filein;
	filein.open("ThongTinDocGia.txt", ios::in);
	//BookList.erase(BookList.begin() + BookList.size());
	DanhSachDocGia.erase(DanhSachDocGia.begin(), DanhSachDocGia.end());
	while (!filein.eof())
	{

		string line;
		while (getline(filein, line))
		{

			string buff;
			istringstream linestream(line);
			getline(linestream, buff, ':');
			//	cout << " \n+++buff cuoi: " << buff <<"end"; 
			if (buff == "") break;
			int n = DanhSachDocGia.size();
			DanhSachDocGia.resize(n + 1);
			//	cout << "\n::buff-177:" << buff << ":::";
			if (buff == "Ten")
			{
				DanhSachDocGia[n] = new NguoiMuon;
			}
			
			DanhSachDocGia[n]->docFile(line);
		}
	}
	filein.close();
}
void DanhSachNguoiMuon::Them()
{
	this->docFile("ThongTinDocGia.txt");
	cout << "\nThem thong tin doc gia: \n ";
	cin.ignore();
	int n = DanhSachDocGia.size();
	DanhSachDocGia.resize(n + 1);
		DanhSachDocGia[n] = new NguoiMuon;

	DanhSachDocGia[n]->nhapthongtin();
	DanhSachDocGia[n]->xuatFile();
	cout << "\n So doc gia sau khi them: " << DanhSachDocGia.size();
	DanhSachDocGia.resize(n);
}
void DanhSachNguoiMuon::Xoa()
{
	this->docFileDocGia();
	string chuoixoa;
	cout << "\nNhap ma so thu vien cua doc gia can xoa: ";
	cin >> chuoixoa;
	int flag = 0;
	for (int i = 0; i < DanhSachDocGia.size(); i++)
	{
		if (DanhSachDocGia[i]->getID() == chuoixoa)
		{
			flag = 1;
			DanhSachDocGia.erase(DanhSachDocGia.begin() + i);
		}
	
	}
	if (flag == 0) cout <<"\nKhong tim thay ma so cua doc gia can xoa !";
}
void DanhSachNguoiMuon::capnhat()
{

	fstream fout;
	fout.open("ThongTinDocGia.txt", ios::out);
	for (int i = 0; i < DanhSachDocGia.size(); i++)
	{
		DanhSachDocGia[i]->xuatFile();
	}
	fout.close();
}
void DanhSachNguoiMuon::timkiemdocgia()
{
	this->docFileDocGia();
	string chuoixoa;
	cout << "\nNhap ma so thu vien cua doc gia can tim kiem: ";
	cin >> chuoixoa;
	int flag = 0;
	for (int i = 0; i < DanhSachDocGia.size(); i++)
	{
		if (DanhSachDocGia[i]->getID() == chuoixoa)

		{
			flag = 1;
			cout << "\nDa tim thay moi ban xem thong tin: "; 
			DanhSachDocGia[i]->hienthi();
		}

	}
	if (flag == 0) cout << "\nKhong tim thay ma so cua doc gia can tim kiem !";
}
void DanhSachNguoiMuon::SuaDocGia()
{
	this->docFileDocGia();
	string chuoixoa;
	cout << "\nNhap ma so thu vien cua doc gia can tim kiem: ";
	cin >> chuoixoa;
	int flag = 0;
	for (int i = 0; i < DanhSachDocGia.size(); i++)
	{
		if (DanhSachDocGia[i]->getID() == chuoixoa)

		{
			flag = 1;
			cout << "\nDa tim thay moi ban sua thong tin: ";
			DanhSachDocGia[i]->nhapthongtin();
		}
	}
	if (flag == 0) cout << "\nKhong tim thay ma so cua doc gia can sua !";
}
void DanhSachNguoiMuon::menu()
{
	cout << "\n********Menu Doc Gia********";
	//cout << "\n >>>>de thuan tien, lam phien ban tra cuu ma sach dan o cua so \nde thuan tien cho viec tim kiem !";
	cout << "\n+Xem tat ca doc hien co: nhan 1";
	cout << "\n+Them doc gia: nhan 2";
	cout << "\n+Tim kiem thong tin doc gia: nhan 3";
	cout << "\n+Xoa doc gia: nhan 4";
	cout << "\n+Sua thong tin sach: nhan 5";
	cout << "\n+Thoat: nhan 0 \n ";
	int choice;
	cin >> choice;
	if (choice == 0) return;
	while (choice != 0) {
		while ((choice < 0) || (choice > 5))
		{
			cout << "\NHap Sai, moi ban nhap lai";
			cin >> choice;
		}
		system("cls");
		switch (choice)
		{
		case 1:
			cout << "\n>>>>Tat ca doc gia <Ho Ten>,<Ma so Thu Vien>: ";
			this->docFileDocGia();
			cout << "\ndoc file xong, so doc gia hien co: " << DanhSachDocGia.size();
			for (int i = 0; i < DanhSachDocGia.size(); i++)
			{
				cout << "\n" << i + 1 << "/ ";
				DanhSachDocGia[i]->hienthi();
			}
			break;
		case 2:
			cout << "\n**Them doc gia \n";
			DanhSachNguoiMuon::Them();
			//ThuVien::CapNhat();
			break;
		case 3:
			DanhSachNguoiMuon::TimKiem();
			break;
		case 4:
			cout << "\n Xoa doc gia theo ma so thu vien\n";
			DanhSachNguoiMuon::Xoa();
			DanhSachNguoiMuon::capnhat();
			cout << "\nDa Cap Nhat";
			break;
		case 5:
			cout << "\n Sua thong tin doc gia: " << endl; 
			DanhSachNguoiMuon::SuaDocGia();
			DanhSachNguoiMuon::capnhat();
			cout << "\Da cap nhat";
			break;
		}
		cout << "\n\n>>>> Lua chon tiep trong menu de thuc hien cong viec: ";
		cout << "\n********Menu Doc Gia********";
		//cout << "\n >>>>de thuan tien, lam phien ban tra cuu ma sach dan o cua so \nde thuan tien cho viec tim kiem !";
		cout << "\n+Xem tat ca doc hien co: nhan 1";
		cout << "\n+Them doc gia: nhan 2";
		cout << "\n+Tim kiem thong tin doc gia: nhan 3"; 
		cout << "\n+Xoa doc gia: nhan 4";
		cout << "\n+Sua thong tin sach: nhan 5";
		cout << "\n+Thoat: nhan 0 \n ";
		cin >> choice;
	}
} 

void Phieu::nhap()
{
	cout << "Nhap Ma So Phieu: ";
	getline(cin, MaSoPhieu);
	docgia.nhapthongtin();
	cout << "\nNhap so sach da muon (toi da 3): ";
	cin >> soSach;
	while ((soSach > 3) || (soSach < 0))
	{
		cout << "\nThu vien quy dinh cho muon toi da 3 cuon! nhap lai so sach";
		cin >> soSach;
	} 
	ListSach.resize(soSach);
	cout << "\nVi nhieu sach trung ten nen de thuan tien,ban tra cuu ma sach roi nhap, xin cam on! ";
	for (int i = 0; i < soSach; i++)
	{
		cin.ignore();
		cout << "\nNhap ma sach, \nneu nhap roi ma enter van hien ra con tro thi bam enter lan nua: ";
		string buffmasach; 
		getline(cin, buffmasach);
		//cin >> buffmasach;
		while (ThuVien::kiemtra(buffmasach) != 1)
		{
			cout << "\nNhap sai, nhap lai ma sach: ";
			getline(cin, buffmasach);
		}
		ListSach[i] = ThuVien::getSachbyMaSach(buffmasach);
	} 
	int ngay, thang, nam;
	cout << "\nNhap ngay lap phieu <ngay thang nam> (vd: 26 7 1998):";
	cin >> ngay >> thang >> nam; 
	while (ngayHopLe(ngay, thang, nam) != 1)
	{
		cout << "\nNgay nhap khong hop le, nhap lai!";
		cout << "\nNhap ngay muon <ngay thang nam> (vd: 26 7 1998):";
		cin >> ngay >> thang >> nam;
	}
	this->setNgayLapPhieu(ngay, thang, nam);
}
void Phieu::hienthi()
{
	docgia.hienthi();
	cout << "\nMa so phieu Muon: " << MaSoPhieu;
	cout << "\nSo Sach muon: " << soSach;
	for (int i = 0; i < ListSach.size(); i++)
	{
		ListSach[i]->ghiPhieu();
	}
	cout << "Ngay lap phieu <dd mm yy>: " << NgayMuon.day << " " << NgayMuon.month << " " << NgayMuon.year << endl;
}
void Phieu::ghifileIDvaNgayMuon(string tenfilenho)
{
	fstream fout;
	fout.open(tenfilenho, ios::out | ios::app);
	fout <<MaSoPhieu<<"," <<ngayLapPhieu.day << "/" << ngayLapPhieu.month << "/" << ngayLapPhieu.year<< endl;
	fout.close();
}
void Phieu::xuatfile(string tenfile, string tenfilenho)
{
	fstream fout;
	fout.open(tenfile, ios::out | ios::app);
	fout << "Ma So Phieu:" << MaSoPhieu << endl;
	docgia.xuatFile(tenfile);
	fout << "So Sach: "<< soSach << endl; 
	for (int i = 0; i < ListSach.size(); i++)
	{
		ListSach[i]->ghiFilePhieuMuon(tenfile);
	}
	fout <<"Ngay)"<< ngayLapPhieu.day << "/" << ngayLapPhieu.month << "/" << ngayLapPhieu.year << endl;
	fout << "***" << endl;
	Phieu::ghifileIDvaNgayMuon(tenfilenho);
	fout.close();
}; 


void DanhSachPhieuMuon::themphieu(string tenfile)
{
	cout << "\n>>>>Them thong tin phieu muon: \n";
	int n = ListMuon.size();
	ListMuon.resize(n + 1);
	ListMuon[n] = new Phieu;
	ListMuon[n]->nhap();
	ListMuon[n]->xuatfile(tenfile,"ID_NGAYMUON.txt");
	//cout << "\n So phieu sau khi them: " << ListMuon.size();
	ListMuon.resize(n);
} 
void DanhSachPhieuMuon::docfileIDvsNgaymuon()
{
	ifstream filein;
	filein.open("ID_NGAYMUON.txt", ios::in);
	//BookList.erase(BookList.begin() + BookList.size());
	ListScan.erase(ListScan.begin(), ListScan.end());
	while (!filein.eof())
	{
		string line;
		while (getline(filein, line))
		{
			string buff;
			istringstream linestream(line);
			getline(linestream, buff, ',');
			if (buff == "") break;
			int n = ListScan.size();

			ListScan.resize(n + 1);
			ListScan[n] = new scanIDNgayMuon;
			ListScan[n]->MaPhieu = buff;
			 
			getline(linestream, buff, '/');
			ListScan[n]->NgayMuon.day = stol(buff,nullptr,10); 

			getline(linestream, buff, '/');			 
			ListScan[n]->NgayMuon.month = stol(buff, nullptr, 10);

			getline(linestream, buff);
			ListScan[n]->NgayMuon.year = stol(buff, nullptr, 10);
			/*cout <<"ma phieu"<< ListScan[n]->MaPhieu <<" Ngay: "<< ListScan[n]->NgayMuon.day
			<<" thang "	<< ListScan[n]->NgayMuon.month
			<< "nam "	<< ListScan[n]->NgayMuon.year;*/
		}
	}

} 
int DanhSachPhieuMuon::kiemtraID(string maso)
{
this->docfileIDvsNgaymuon();
	int flag = 0;
	for (int i = 0; i < ListScan.size(); i++)
	{
		if (ListScan[i]->MaPhieu == maso)
			flag = 1;
	}
	return flag; 
};

MyDate DanhSachPhieuMuon::layngaytuID(string maso)
{
	this->docfileIDvsNgaymuon();
	//int flag = 0;
	for (int i = 0; i < ListScan.size(); i++)
	{
		if (ListScan[i]->MaPhieu == maso)
			return ListScan[i]->NgayMuon;
	}
	//return flag;
}
void DanhSachPhieuTra::themphieu(string tenfile)
{
	cout << "\n>>>>Them thong tin phieu tra: \n";
	int n = ListTra.size();
	ListTra.resize(n + 1);
	ListTra[n] = new Phieu;
	ListTra[n]->nhap();
	while (DanhSachPhieuMuon::kiemtraID(ListTra[n]->getMaSoPhieu()) != 1)
	{
		cout << "\nMa so phieu nay chua dang ky muon nen khong the tra, nhap lai cho dung !";
		cin.ignore();
		ListTra[n]->nhap();
	}
	ListTra[n]->xuatfile(tenfile,"ID_NGAYTRA.txt");
	cout << "\n So phieu sau khi them: " << ListTra.size();
	ListTra.resize(n);
}

void DanhSachPhieuTra::docfileIDvsNgayTra()
{
	ifstream filein;
	filein.open("ID_NGAYTRA.txt", ios::in);
	//BookList.erase(BookList.begin() + BookList.size());
	ListScanTra.erase(ListScanTra.begin(), ListScanTra.end());
	while (!filein.eof())
	{
		string line;
		while (getline(filein, line))
		{
			string buff;
			istringstream linestream(line);
			getline(linestream, buff, ',');
			if (buff == "") break;
			int n = ListScanTra.size();

			ListScanTra.resize(n + 1);
			ListScanTra[n] = new scanIDNgayMuon;
			ListScanTra[n]->MaPhieu = buff;

			getline(linestream, buff, '/');
			ListScanTra[n]->NgayMuon.day = stol(buff, nullptr, 10);

			getline(linestream, buff, '/');
			ListScanTra[n]->NgayMuon.month = stol(buff, nullptr, 10);

			getline(linestream, buff);
			ListScanTra[n]->NgayMuon.year = stol(buff, nullptr, 10);
			/*cout <<"ma phieu"<< ListScan[n]->MaPhieu <<" Ngay: "<< ListScan[n]->NgayMuon.day
			<<" thang "	<< ListScan[n]->NgayMuon.month
			<< "nam "	<< ListScan[n]->NgayMuon.year;*/
		}
	}
}

void DanhSachPhieuTra::lietkeListQuaHan()
{
	DanhSachPhieuTra::docfileIDvsNgayTra();

	cout << "\nDanh Sach Ma Phieu Tra Tre Han:  ";
	for (int i = 0; i < ListScanTra.size(); i++)
	{
		MyDate tempMuon;
		int khoang;
		tempMuon=DanhSachPhieuMuon::layngaytuID(ListScanTra[i]->MaPhieu);
		khoang = tinhNgay(tempMuon, ListScanTra[i]->NgayMuon); 
		if (khoang > 7) cout << ListScanTra[i]->MaPhieu << endl;
	}
}

void Menu()
{
	cout << "\n>>>>QUAN LI THU VIEN: <<<<\n";
	int choice;
	cout << "\nNhan 1: Vao menu Thu Vien de xem, sua, xoa, tim kiem Sach" << endl;
	cout << "\nNhan 2: Vao menu Doc Gia de xem, sua, xoa, tim kiem doc gia da dang ki o thu vien" << endl;
	cout << "\nNhan 3: Them phieu muon sach " << endl;
	cout << "\nNhan 4: Them phieu tra sach" << endl;
	cout << "\nNhan 5: Xem cac phieu tra Tre Han" << endl;
	cout << "\nNhan 0: Thoat" << endl;
	cout << "\n****lua chon: ";
	cin >> choice;
	while ((choice < 0) || (choice > 5))
	{
		cout << "\nLua chon sai, nhap lai: ";
		cin >> choice;
	}
	if (choice == 0) return;
	while (choice != 0)
	{
		system("cls");
		if (choice == 1) {
			ThuVien mod1;
			mod1.menu();
			break;
		}
		else if (choice == 2) {
			DanhSachNguoiMuon mod2;
			mod2.menu();
			break;
		}
		else if (choice == 3) {
			DanhSachPhieuMuon mod3;
			mod3.themphieu("DanhSachPhieuMuon.txt");
			break;
		}
		else if (choice == 4) {
			DanhSachPhieuTra mod4;
			mod4.themphieu("DanhSachPhieuTra.txt");
			break;
		}
		else if (choice == 5) {
			DanhSachPhieuTra mod4;
			mod4.lietkeListQuaHan();
			break;
		}
	}
	system("cls");
	cout << "\nXong roi,Lua chon tiep ";
	cout << "\nNhan 1: Vao menu Thu Vien de xem, sua, xoa, tim kiem Sach" << endl;
	cout << "\nNhan 2: Vao menu Doc Gia de xem, sua, xoa, tim kiem doc gia da dang ki o thu vien" << endl;
	cout << "\nNhan 3: Them phieu muon sach " << endl;
	cout << "\nNhan 4: Them phieu tra sach" << endl;
	cout << "\nNhan 5: Xem cac phieu tra Tre Han" << endl;
	cout << "\nNhan 0: Thoat" << endl;
	cout << "\n****lua chon: ";
	cin >> choice;
}


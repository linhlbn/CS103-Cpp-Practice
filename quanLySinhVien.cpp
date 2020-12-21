/**
 * 2059025 - Pham Thai Linh
 * Created at 18/12/2020
 * Develop struct Student
*/
#include <iostream>
#include <string>
#define MAX 100
using namespace std;
// Define Student Structure
typedef struct SinhVien{
    int     mssv;
    string  hoTen;
    float   diemToan;
    float   diemGiaoTiep;
    float   diemLapTrinh;

    float   diemTrungBinh;
} SINHVIEN;

// List of Prototypes of SINHVIEN
SINHVIEN Nhap();
void Xuat(const SINHVIEN sv);

// List of Prototype of DanhSachSinhVien
void NhapDanhSachSinhVien(SINHVIEN dsSinhVien[], int& soLuong);
void XuatDanhSachSinhVien(const SINHVIEN dsSinhVien[], const int soLuong);
void ThemSinhVien(SINHVIEN dsSinhVien[], int& soLuong, const SINHVIEN sv);
void XoaSinhVien(SINHVIEN dsSinhVien[], int& soLuong, const int mssv);
void CapNhatSinhVien(SINHVIEN dsSinhVien[], const int soLuong, const int mssv);
int TimViTriSinhVien(const SINHVIEN dsSinhVien[], const int soLuong, const int mssv);
// List of Prototype MENU
int ShowMenu();
int main()
{
    system("clear"); // system("cls");

    SINHVIEN dsSinhVien[MAX];
    int soLuong = 0;

    int mssv;
    int iChon = 0;
    do
    {
        iChon = ShowMenu();

        switch (iChon)
        {
            case 1:
            {
                NhapDanhSachSinhVien(dsSinhVien, soLuong);
                break;
            }
            case 2:
                cout << "-- DANH SACH SINH VIEN --" << endl;
                cout << "MSSV \tHo va ten\tD.Toan\tD.Giao Tiep\tD.Lap Trinh\tD.Trung Binh" << endl;
                XuatDanhSachSinhVien(dsSinhVien, soLuong);
                break;
            case 3:
            {
                SINHVIEN sv = Nhap();
                ThemSinhVien(dsSinhVien, soLuong, sv);
                break;
            }
            case 4:
            {
                cout << "-- Xoa Sinh Vien --" << endl;
                cout << "Nhap MSSV can xoa: ";
                cin >> mssv;
                XoaSinhVien(dsSinhVien, soLuong, mssv);
                break;
            }
            case 5:
            {
                cout << "-- Cap nhat thong tin moi cho Sinh Vien --" << endl;
                cout << "Nhap MSSV can cap nhat: ";
                cin >> mssv;
                CapNhatSinhVien(dsSinhVien, soLuong, mssv);
                break;
            }
            case 6:
            {
                cout << "-- Tim thong tin Sinh Vien --" << endl;
                cout << "Nhap MSSV can tim: ";
                cin >> mssv;
                int vitri = TimViTriSinhVien(dsSinhVien, soLuong, mssv);
                if(vitri != -1)
                    Xuat(dsSinhVien[vitri]);
                else
                    cout << "KHONG tim thay Sinh Vien co MSSV la " << mssv << " trong danh sach" << endl;
                break;
            }
        }

    } while (iChon != 0);

    return 0;
}

// Implement functions for Student struture
SINHVIEN Nhap()
{
    SINHVIEN sv;
    cout << "-- Nhap thong tin sinh vien --" << endl;

    cout << "MSSV: ";
    cin >> sv.mssv;

    cout << "Ho va ten: ";
    cin.ignore();
    getline(cin, sv.hoTen);

    cout << "Diem mon Toan: ";
    cin >> sv.diemToan;

    cout << "Diem mon Giao Tiep: ";
    cin >> sv.diemGiaoTiep;

    cout << "Diem mon Lap Trinh: ";
    cin >> sv.diemLapTrinh;

    sv.diemTrungBinh = (sv.diemToan + sv.diemGiaoTiep + sv.diemLapTrinh) / 3.0;

    return sv;
}

void Xuat(const SINHVIEN sv)
{
    cout << sv.mssv << "\t" << sv.hoTen << "\t\t";
    cout << sv.diemToan << "\t\t" << sv.diemGiaoTiep << "\t\t" << sv.diemLapTrinh << "\t\t";
    cout << sv.diemTrungBinh << endl;
}

// Implement functions for StudentList
void NhapDanhSachSinhVien(SINHVIEN dsSinhVien[], int& soLuong)
{
    cout << "-- Nhap danh sach sinh vien --" << endl;
    cout << "Nhap so luong sinh vien: ";
    cin >> soLuong;

    for(int i = 0; i < soLuong; i++)
        dsSinhVien[i] = Nhap();
}

void XuatDanhSachSinhVien(const SINHVIEN dsSinhVien[], const int soLuong)
{
    if (soLuong <=0) {
        return ;
    }

//
//    Xuat(dsSinhVien[soLuong-1]);
//
//    XuatDanhSachSinhVien(dsSinhVien, soLuong-1);

    for(int i = 0; i < soLuong; i++)
        Xuat(dsSinhVien[i]);

    cout << endl;
}

void ThemSinhVien(SINHVIEN dsSinhVien[], int& soLuong, const SINHVIEN sv)
{
    if(soLuong < MAX)
    {
        dsSinhVien[soLuong++] = sv;
        cout << "Thong tin sinh vien moi da duoc them THANH CONG!" << endl;
    }
    else
    {
        cout << "# Loi: Khong thuc hien them moi Sinh vien vao danh sach vi Danh sach da DAY(MAX)" << endl;
    }

}

void XoaSinhVien(SINHVIEN dsSinhVien[], int& soLuong, const int mssv){
    int vitri = TimViTriSinhVien(dsSinhVien, soLuong, mssv);
    if(vitri != -1) {
        for(int i = vitri; i < soLuong - 1; i++)
            dsSinhVien[i] = dsSinhVien[i + 1];
        soLuong--;
        cout << "Da thuc hien xoa THANH CONG thong tin Sinh vien co MSSV " << mssv << endl;
    }
    else
    {
        cout << "# Loi: Khong tim thay sinh vien co MSSV" << mssv << " trong danh sach nen KHONG thuc hien duoc lenh XOA" << endl;
    }
}

void CapNhatSinhVien(SINHVIEN dsSinhVien[], const int soLuong, const int mssv)
{
    int vitri = TimViTriSinhVien(dsSinhVien, soLuong, mssv);
    if(vitri != -1)
    {
        cout << "-- Thuc hien cap nhat thong tin moi cho Sinh vien co MSSV " << mssv << " --" << endl;

        cout << "Ho va ten: ";
        cin.ignore();
        getline(cin, dsSinhVien[vitri].hoTen);

        cout << "Diem mon Toan: ";
        cin >> dsSinhVien[vitri].diemToan;

        cout << "Diem mon Giao Tiep: ";
        cin >> dsSinhVien[vitri].diemGiaoTiep;

        cout << "Diem mon Lap Trinh: ";
        cin >> dsSinhVien[vitri].diemLapTrinh;

        dsSinhVien[vitri].diemTrungBinh = (dsSinhVien[vitri].diemToan + dsSinhVien[vitri].diemGiaoTiep + dsSinhVien[vitri].diemLapTrinh) / 3.0;

        cout << "Da thuc hien cap nhat THANH CONG thong tin moi cho Sinh vien co MSSV " << mssv << endl;
    }
    else
    {
        cout << "# Loi: Khong tim thay sinh vien co MSSV" << mssv << " trong danh sach nen KHONG thuc hien duoc lenh CAP NHAT" << endl;
    }

}

// Neu tim khong co MSSV trong danh sach thi se return -1
int TimViTriSinhVien(const SINHVIEN dsSinhVien[], const int soLuong, const int mssv)
{
    int vitri = -1;
    for(int i = 0; i < soLuong; i++)
    {
        if(dsSinhVien[i].mssv == mssv)
        {
            vitri = i;
            break;
        }
    }
    return vitri;
}

// Implement Menu
int ShowMenu()
{
    int iChon = 0;

    cout << "-------- MENU ---------" << endl;
    cout << "\t1. Nhap danh sach sinh vien" << endl;
    cout << "\t2. Xuat danh sach sinh vien" << endl;
    cout << "\t3. Them sinh vien vao danh sach" << endl;
    cout << "\t4. Xoa sinh vien ra khoi danh sach" << endl;
    cout << "\t5. Cap nhat thong tin sinh vien" << endl;
    cout << "\t6. Tim thong tin cua sinh vien" << endl;
    cout << "\t0. Thoat chuong trinh" << endl;
    cout << "=> Chon: ";
    cin >> iChon;
    system("clear");
    return iChon;
}
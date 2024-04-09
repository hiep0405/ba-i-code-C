#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

// Khai báo cấu trúc SinhVien
struct SinhVien {
    char maSinhVien[10];
    char ten[10];
    float diemToan;
    float diemVan;
    float diemAnhVan;
};

// Khai báo các hàm
void nhapDanhSachSinhVien(struct SinhVien *danhSachSinhVien, int *soLuongSinhVien);
void timKiemSinhVienBangMaSV(struct SinhVien *danhSachSinhVien, int soLuongSinhVien);
void suaDoiThongTinSinhVien(struct SinhVien *danhSachSinhVien, int soLuongSinhVien);
void xoaThongTinSinhVien(struct SinhVien *danhSachSinhVien, int *soLuongSinhVien);
float tinhDiemTrungBinhCua1SV(float diemToan, float diemVan, float diemAnhVan);
float tinhDiemTrungBinhToanBoSV(struct SinhVien *danhSachSinhVien, int soLuongSinhVien);
void hienThiToanBoDanhSachSV(struct SinhVien *danhSachSinhVien, int soLuongSinhVien);
void luuDanhSachSinhVienVaoFile(struct SinhVien *danhSachSinhVien, int soLuongSinhVien, const char *tenTapTin);
void docDanhSachSinhVienTuFile(struct SinhVien *danhSachSinhVien, int *soLuongSinhVien, const char *tenTapTin);

int main() {
    int choice;
    bool thoat = false;
    struct SinhVien danhSachSinhVien[10]; 
    int soLuongSinhVien = 0;

    do {
        printf("Menu:\n");
        printf("1. Them sinh vien\n");
        printf("2. Tim kiem sinh vien bang ma SV\n");
        printf("3. Sua doi thong tin sinh vien\n");
        printf("4. Xoa thong tin sinh vien\n");
        printf("5. Tinh diem trung binh cua 1 SV\n");
        printf("6. Tinh diem trung binh toan bo SV\n");
        printf("7. Hien thi toan bo danh sach SV\n");
        printf("8. Luu vao file\n");
        printf("9. Doc danh sach tu file\n");
        printf("0. Thoat\n");
        printf("Lua chon chuc nang tu menu: ");
        scanf("%d", &choice);
        printf("\n");
//xử lý choice
        switch (choice) {
            case 1:
                nhapDanhSachSinhVien(danhSachSinhVien, &soLuongSinhVien);
                break;
            case 2:
                timKiemSinhVienBangMaSV(danhSachSinhVien, soLuongSinhVien);
                break;
            case 3:
                suaDoiThongTinSinhVien(danhSachSinhVien, soLuongSinhVien);
                break;
            case 4:
                xoaThongTinSinhVien(danhSachSinhVien, &soLuongSinhVien);
                break;
            case 5:
                // Tạm thời chưa cần gọi hàm này trong menu
                break;
            case 6:
                printf("Diem trung binh toan bo SV: %.2f\n", tinhDiemTrungBinhToanBoSV(danhSachSinhVien, soLuongSinhVien));
                break;
            case 7:
                hienThiToanBoDanhSachSV(danhSachSinhVien, soLuongSinhVien);
                break;
            case 8:
                luuDanhSachSinhVienVaoFile(danhSachSinhVien, soLuongSinhVien, "sinhvien.txt");
                break;
            case 9:
                docDanhSachSinhVienTuFile(danhSachSinhVien, &soLuongSinhVien, "sinhvien.txt");
                break;
            case 0:
                thoat = true;
                printf("Thoat Menu.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
                break;
        }
    } while (!thoat);

    return 0;
}

void nhapDanhSachSinhVien(struct SinhVien *danhSachSinhVien, int *soLuongSinhVien) {
    printf("Nhap so luong sinh vien: ");
    scanf("%d", soLuongSinhVien);

    for (int i = 0; i < *soLuongSinhVien; i++) {
        printf("Nhap thong tin cho sinh vien thu %d:\n", i + 1);
        printf("Ma sinh vien: ");
        scanf("%s", danhSachSinhVien[i].maSinhVien);
        printf("Ten: ");
        scanf("%s", danhSachSinhVien[i].ten);
        printf("Diem toan: ");
        scanf("%f", &danhSachSinhVien[i].diemToan);
        printf("Diem van: ");
        scanf("%f", &danhSachSinhVien[i].diemVan);
        printf("Diem anh van: ");
        scanf("%f", &danhSachSinhVien[i].diemAnhVan);
    }
}

void timKiemSinhVienBangMaSV(struct SinhVien *danhSachSinhVien, int soLuongSinhVien) {
    char maTimKiem[10];
    printf("Nhap ma sinh vien can tim: ");
    scanf("%s", maTimKiem);

    bool timThay = false;
    for (int i = 0; i < soLuongSinhVien; i++) {
        if (strcmp(danhSachSinhVien[i].maSinhVien, maTimKiem) == 0) {
            printf("Tim thay sinh vien:\n");
            printf("Ma sinh vien: %s\n", danhSachSinhVien[i].maSinhVien);
            printf("Ten: %s\n", danhSachSinhVien[i].ten);
            printf("Diem toan: %.2f\n", danhSachSinhVien[i].diemToan);
            printf("Diem van: %.2f\n", danhSachSinhVien[i].diemVan);
            printf("Diem anh van: %.2f\n", danhSachSinhVien[i].diemAnhVan);
            timThay = true;
            break;
        }
    }

    if (!timThay) {
        printf("Khong tim thay sinh vien voi ma: %s\n", maTimKiem);
    }
}

void suaDoiThongTinSinhVien(struct SinhVien *danhSachSinhVien, int soLuongSinhVien) {
    char maSinhVien[10];
    printf("Nhap ma sinh vien can sua thong tin: ");
    scanf("%s", maSinhVien);

    bool timThay = false;
    for (int i = 0; i < soLuongSinhVien; i++) {
        if (strcmp(danhSachSinhVien[i].maSinhVien, maSinhVien) == 0) {
            printf("Nhap thong tin moi cho sinh vien:\n");
            printf("Ten: ");
            scanf("%s", danhSachSinhVien[i].ten);
            printf("Diem toan: ");
            scanf("%f", &danhSachSinhVien[i].diemToan);
            printf("Diem van: ");
            scanf("%f", &danhSachSinhVien[i].diemVan);
            printf("Diem anh van: ");
            scanf("%f", &danhSachSinhVien[i].diemAnhVan);
            printf("Thong tin sinh vien da duoc sua:\n");
            printf("Ma sinh vien: %s\n", danhSachSinhVien[i].maSinhVien);
            printf("Ten: %s\n", danhSachSinhVien[i].ten);
            printf("Diem toan: %.2f\n", danhSachSinhVien[i].diemToan);
            printf("Diem van: %.2f\n", danhSachSinhVien[i].diemVan);
            printf("Diem anh van: %.2f\n", danhSachSinhVien[i].diemAnhVan);
            timThay = true;
            break;
        }
    }

    if (!timThay) {
        printf("Khong tim thay sinh vien voi ma: %s\n", maSinhVien);
    }
}

void xoaThongTinSinhVien(struct SinhVien *danhSachSinhVien, int *soLuongSinhVien) {
    char maSinhVien[10];
    printf("Nhap ma sinh vien can xoa: ");
    scanf("%s", maSinhVien);

    bool timThay = false;
    for (int i = 0; i < *soLuongSinhVien; i++) {
        if (strcmp(danhSachSinhVien[i].maSinhVien, maSinhVien) == 0) {
            for (int j = i; j < *soLuongSinhVien - 1; j++) {
                strcpy(danhSachSinhVien[j].maSinhVien, danhSachSinhVien[j + 1].maSinhVien);
                strcpy(danhSachSinhVien[j].ten, danhSachSinhVien[j + 1].ten);
                danhSachSinhVien[j].diemToan = danhSachSinhVien[j + 1].diemToan;
                danhSachSinhVien[j].diemVan = danhSachSinhVien[j + 1].diemVan;
                danhSachSinhVien[j].diemAnhVan = danhSachSinhVien[j + 1].diemAnhVan;
            }
            (*soLuongSinhVien)--;
            timThay = true;
            printf("Da xoa sinh vien voi ma: %s\n", maSinhVien);
            break;
        }
    }

    if (!timThay) {
        printf("Khong tim thay sinh vien voi ma: %s\n", maSinhVien);
    }
}

float tinhDiemTrungBinhCua1SV(float diemToan, float diemVan, float diemAnhVan) {
    return (diemToan + diemVan + diemAnhVan) / 3;
}

float tinhDiemTrungBinhToanBoSV(struct SinhVien *danhSachSinhVien, int soLuongSinhVien) {
    float tongDiem = 0.0;

    for (int i = 0; i < soLuongSinhVien; i++) {
        tongDiem += (danhSachSinhVien[i].diemToan + danhSachSinhVien[i].diemVan + danhSachSinhVien[i].diemAnhVan);
    }

    return tongDiem / (soLuongSinhVien * 3);
}

void hienThiToanBoDanhSachSV(struct SinhVien *danhSachSinhVien, int soLuongSinhVien) {
    printf("Danh sach sinh vien:\n");
    for (int i = 0; i < soLuongSinhVien; i++) {
        printf("Sinh vien thu %d:\n", i + 1);
        printf("Ma sinh vien: %s\n", danhSachSinhVien[i].maSinhVien);
        printf("Ten: %s\n", danhSachSinhVien[i].ten);
        printf("Diem toan: %.2f\n", danhSachSinhVien[i].diemToan);
        printf("Diem van: %.2f\n", danhSachSinhVien[i].diemVan);
        printf("Diem anh van: %.2f\n", danhSachSinhVien[i].diemAnhVan);
    }
}

void luuDanhSachSinhVienVaoFile(struct SinhVien *danhSachSinhVien, int soLuongSinhVien, const char *tenTapTin) {
    FILE *file = fopen(tenTapTin, "w");

    if (file == NULL) {
        printf("Khong the mo hoac tao file.\n");
        return;
    }

    for (int i = 0; i < soLuongSinhVien; i++) {
        fprintf(file, "%s %s %.2f %.2f %.2f\n", danhSachSinhVien[i].maSinhVien, danhSachSinhVien[i].ten, danhSachSinhVien[i].diemToan, danhSachSinhVien[i].diemVan, danhSachSinhVien[i].diemAnhVan);
    }

    fclose(file);
}

void docDanhSachSinhVienTuFile(struct SinhVien *danhSachSinhVien, int *soLuongSinhVien, const char *tenTapTin) {
    FILE *file = fopen(tenTapTin, "r");

    if (file == NULL) {
        printf("Khong the mo file.\n");
        return;
    }

    *soLuongSinhVien = 0;
    while (fscanf(file, "%s %s %f %f %f", danhSachSinhVien[*soLuongSinhVien].maSinhVien, danhSachSinhVien[*soLuongSinhVien].ten, &danhSachSinhVien[*soLuongSinhVien].diemToan, &danhSachSinhVien[*soLuongSinhVien].diemVan, &danhSachSinhVien[*soLuongSinhVien].diemAnhVan) != EOF) {
        (*soLuongSinhVien)++;
    }

    fclose(file);
}

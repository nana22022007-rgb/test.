#include <stdio.h>
#include <string.h>

// Khai báo c?u trúc d? li?u sinh viên
typedef struct {
    int maSV;
    char hoTen[50];
    int namSinh;
    float diemTB;
} SinhVien;

// Hàm ki?m tra và tr? v? x?p lo?i theo di?m trung bình
const char* layXepLoai(float diemTB) {
    if (diemTB >= 8.0f) {
        return "Gioi";
    } else if (diemTB >= 6.5f) {
        return "Kha";
    } else if (diemTB >= 5.0f) {
        return "Trung binh";
    } else {
        return "Yeu";
    }
}

// Hàm tìm sinh viên theo mã (Tr? v? ch? s? index trong m?ng, ho?c -1 n?u không tìm th?y)
int timSinhVienTheoMa(SinhVien ds[], int n, int ma) {
    for (int i = 0; i < n; i++) {
        if (ds[i].maSV == ma) {
            return i;
        }
    }
    return -1;
}

// Hàm in tiêu d? b?ng danh sách
void inTieuDeBang() {
    printf("%-10s %-25s %-10s %-10s %-12s\n", "Ma", "Hoten", "Namsinh", "DiemTB", "Xeploai");
}

// Hàm in thông tin m?t sinh viên
void inSinhVien(SinhVien sv) {
    printf("%-10d %-25s %-10d %-10.2f %-12s\n", 
           sv.maSV, sv.hoTen, sv.namSinh, sv.diemTB, layXepLoai(sv.diemTB));
}

// Ch?c nang 1: Thêm sinh viên
void themSinhVien(SinhVien ds[], int *n) {
    if (*n >= 50) {
        printf("Danh sach da day\n");
        return;
    }

    int ma;
    printf("Nhap ma sinh vien: ");
    scanf("%d", &ma);

    if (ma <= 0) {
        printf("Ma sinh vien khong hop le\n");
        return;
    }

    if (timSinhVienTheoMa(ds, *n, ma) != -1) {
        printf("Ma sinh vien da ton tai\n");
        return;
    }

    SinhVien svMoi;
    svMoi.maSV = ma;

    // Ð?c ký t? newline còn l?i trong b? d?m tru?c khi dùng fgets
    getchar();

    printf("Nhap ho ten: ");
    fgets(svMoi.hoTen, sizeof(svMoi.hoTen), stdin);
    // Xóa ký t? xu?ng dòng '\n' ? cu?i chu?i n?u có
    size_t len = strlen(svMoi.hoTen);
    if (len > 0 && svMoi.hoTen[len - 1] == '\n') {
        svMoi.hoTen[len - 1] = '\0';
    }

    printf("Nhap nam sinh (1950 - 2010): ");
    scanf("%d", &svMoi.namSinh);
    while (svMoi.namSinh < 1950 || svMoi.namSinh > 2010) {
        printf("Nam sinh khong hop le, nhap lai: ");
        scanf("%d", &svMoi.namSinh);
    }

    printf("Nhap diem trung binh (0 - 10): ");
    scanf("%f", &svMoi.diemTB);
    while (svMoi.diemTB < 0.0f || svMoi.diemTB > 10.0f) {
        printf("Diem trung binh khong hop le, nhap lai: ");
        scanf("%f", &svMoi.diemTB);
    }

    ds[*n] = svMoi;
    (*n)++;
    printf("Them sinh vien thanh cong\n");
}

// Ch?c nang 2: Hi?n th? danh sách sinh viên
void hienThiDanhSach(SinhVien ds[], int n) {
    if (n == 0) {
        printf("Danh sach rong\n");
        return;
    }

    inTieuDeBang();
    for (int i = 0; i < n; i++) {
        inSinhVien(ds[i]);
    }
}

// Ch?c nang 3: C?p nh?t sinh viên theo mã
void capNhatSinhVien(SinhVien ds[], int n) {
    if (n == 0) {
        printf("Danh sach rong\n");
        return;
    }

    int ma;
    printf("Nhap ma sinh vien can sua: ");
    scanf("%d", &ma);

    int pos = timSinhVienTheoMa(ds, n, ma);
    if (pos == -1) {
        printf("Khong tim thay sinh vien\n");
        return;
    }

    getchar(); // Ð?c ký t? '\n' còn th?a

    printf("Nhap ho ten moi: ");
    fgets(ds[pos].hoTen, sizeof(ds[pos].hoTen), stdin);
    size_t len = strlen(ds[pos].hoTen);
    if (len > 0 && ds[pos].hoTen[len - 1] == '\n') {
        ds[pos].hoTen[len - 1] = '\0';
    }

    printf("Nhap nam sinh moi (1950 - 2010): ");
    scanf("%d", &ds[pos].namSinh);
    while (ds[pos].namSinh < 1950 || ds[pos].namSinh > 2010) {
        printf("Nam sinh khong hop le, nhap lai: ");
        scanf("%d", &ds[pos].namSinh);
    }

    printf("Nhap diem trung binh moi (0 - 10): ");
    scanf("%f", &ds[pos].diemTB);
    while (ds[pos].diemTB < 0.0f || ds[pos].diemTB > 10.0f) {
        printf("Diem trung binh khong hop le, nhap lai: ");
        scanf("%f", &ds[pos].diemTB);
    }

    printf("Cap nhat thanh cong\n");
}

// Ch?c nang 4: Xóa sinh viên theo mã
void xoaSinhVien(SinhVien ds[], int *n) {
    if (*n == 0) {
        printf("Danh sach rong\n");
        return;
    }

    int ma;
    printf("Nhap ma sinh vien can xoa: ");
    scanf("%d", &ma);

    int pos = timSinhVienTheoMa(ds, *n, ma);
    if (pos == -1) {
        printf("Khong tim thay sinh vien\n");
        return;
    }

    for (int i = pos; i < *n - 1; i++) {
        ds[i] = ds[i + 1];
    }
    (*n)--;

    printf("Xoa thanh cong\n");
}

// Ch?c nang 5: Tìm sinh viên theo tên
void timSinhVienTheoTen(SinhVien ds[], int n) {
    if (n == 0) {
        printf("Danh sach rong\n");
        return;
    }

    char tuKhoa[50];
    printf("Nhap chuoi can tim: ");
    getchar(); // Ð?c '\n' th?a
    fgets(tuKhoa, sizeof(tuKhoa), stdin);
    size_t len = strlen(tuKhoa);
    if (len > 0 && tuKhoa[len - 1] == '\n') {
        tuKhoa[len - 1] = '\0';
    }

    int timThay = 0;
    for (int i = 0; i < n; i++) {
        if (strstr(ds[i].hoTen, tuKhoa) != NULL) {
            if (!timThay) {
                inTieuDeBang();
                timThay = 1;
            }
            inSinhVien(ds[i]);
        }
    }

    if (!timThay) {
        printf("Khong tim thay sinh vien\n");
    }
}

// Ch?c nang 6: S?p x?p theo di?m gi?m d?n (Stable Insertion Sort d? gi? th? t? tuong d?i)
void sapXepTheoDiemGiamDan(SinhVien ds[], int n) {
    if (n == 0) {
        printf("Danh sach rong\n");
        return;
    }

    for (int i = 1; i < n; i++) {
        SinhVien key = ds[i];
        int j = i - 1;
        while (j >= 0 && ds[j].diemTB < key.diemTB) {
            ds[j + 1] = ds[j];
            j--;
        }
        ds[j + 1] = key;
    }

    printf("Sap xep thanh cong\n");
    hienThiDanhSach(ds, n);
}

// Ch?c nang 7: Th?ng kê k?t qu? h?c t?p
void thongKeKetQuaHocTap(SinhVien ds[], int n) {
    if (n == 0) {
        printf("Danh sach rong\n");
        return;
    }

    float tongDiem = 0.0f;
    int demGioi = 0, demKha = 0, demTrungBinh = 0, demYeu = 0;
    int indexMaxTB = 0;

    for (int i = 0; i < n; i++) {
        tongDiem += ds[i].diemTB;

        if (ds[i].diemTB >= 8.0f) {
            demGioi++;
        } else if (ds[i].diemTB >= 6.5f) {
            demKha++;
        } else if (ds[i].diemTB >= 5.0f) {
            demTrungBinh++;
        } else {
            demYeu++;
        }

        if (ds[i].diemTB > ds[indexMaxTB].diemTB) {
            indexMaxTB = i;
        }
    }

    printf("Diem trung binh ca danh sach: %.2f\n", tongDiem / n);
    printf("So luong sinh vien Gioi: %d\n", demGioi);
    printf("So luong sinh vien Kha: %d\n", demKha);
    printf("So luong sinh vien Trung binh: %d\n", demTrungBinh);
    printf("So luong sinh vien Yeu: %d\n", demYeu);

    printf("\nDanh sach sinh vien phai hoc lai:\n");
    if (demYeu == 0) {
        printf("Khong co sinh vien phai hoc lai\n");
    } else {
        inTieuDeBang();
        for (int i = 0; i < n; i++) {
            if (ds[i].diemTB < 5.0f) {
                inSinhVien(ds[i]);
            }
        }
    }

    printf("\nSinh vien co diem trung binh cao nhat:\n");
    inTieuDeBang();
    inSinhVien(ds[indexMaxTB]);
}

// Hàm main di?u khi?n menu
int main() {
    SinhVien ds[50];
    int n = 0;
    int luaChon;

    do {
        printf("\n===== QUAN LY SINH VIEN =====\n");
        printf("1. Them sinh vien\n");
        printf("2. Hien thi danh sach sinh vien\n");
        printf("3. Cap nhat sinh vien theo ma\n");
        printf("4. Xoa sinh vien theo ma\n");
        printf("5. Tim sinh vien theo ten\n");
        printf("6. Sap xep theo diem giam dan\n");
        printf("7. Thong ke ket qua hoc tap\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");

        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                themSinhVien(ds, &n);
                break;
            case 2:
                hienThiDanhSach(ds, n);
                break;
            case 3:
                capNhatSinhVien(ds, n);
                break;
            case 4:
                xoaSinhVien(ds, &n);
                break;
            case 5:
                timSinhVienTheoTen(ds, n);
                break;
            case 6:
                sapXepTheoDiemGiamDan(ds, n);
                break;
            case 7:
                thongKeKetQuaHocTap(ds, n);
                break;
            case 0:
                printf("Tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le\n");
                break;
        }
    } while (luaChon != 0);

    return 0;
}

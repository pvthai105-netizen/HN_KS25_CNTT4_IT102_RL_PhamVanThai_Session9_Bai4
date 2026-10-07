#include <stdio.h>
#include <string.h>

struct HanhKhach {
    char maPNR[15];
    char hoTen[50];
    char hangVe[15];
    float canNangHanhLy;
    float phiHanhLy;
};

int main(void) {
    struct HanhKhach danhSach[100];
    int soLuong = 0;
    int luaChon;
    int i;
    int found;
    int viTri;
    int soBusiness;
    float kgMienPhi;
    float tongDoanhThu;

    do {
        printf("\n=== HE THONG CHECK-IN HANG KHONG ===\n");
        printf("1. Them hanh khach check-in\n");
        printf("2. Hien thi danh sach hanh khach\n");
        printf("3. Cap nhat hanh ly theo ma PNR\n");
        printf("4. Thong ke chuyen bay\n");
        printf("5. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);

        while (getchar() != '\n');

        switch (luaChon) {
            case 1:
                if (soLuong == 100) {
                    printf("Bo nho day, khong the them hanh khach!\n");
                    break;
                }

                printf("\nNhap ma PNR: ");
                scanf("%14s", danhSach[soLuong].maPNR);

                while (getchar() != '\n');

                printf("Nhap ho ten: ");
                fgets(danhSach[soLuong].hoTen,
                      sizeof(danhSach[soLuong].hoTen), stdin);

                danhSach[soLuong].hoTen[
                    strcspn(danhSach[soLuong].hoTen, "\n")
                ] = '\0';

                printf("Nhap hang ve (Business/Deluxe/Eco): ");
                fgets(danhSach[soLuong].hangVe,
                      sizeof(danhSach[soLuong].hangVe), stdin);

                danhSach[soLuong].hangVe[
                    strcspn(danhSach[soLuong].hangVe, "\n")
                ] = '\0';

                printf("Nhap so kg hanh ly ky gui: ");
                scanf("%f", &danhSach[soLuong].canNangHanhLy);

                if (strcmp(danhSach[soLuong].hangVe, "Business") == 0) {
                    kgMienPhi = 30.0f;
                } else if (strcmp(danhSach[soLuong].hangVe, "Deluxe") == 0) {
                    kgMienPhi = 20.0f;
                } else {
                    kgMienPhi = 0.0f;
                }

                if (danhSach[soLuong].canNangHanhLy > kgMienPhi) {
                    danhSach[soLuong].phiHanhLy =
                        (danhSach[soLuong].canNangHanhLy - kgMienPhi) * 50000.0f;
                } else {
                    danhSach[soLuong].phiHanhLy = 0.0f;
                }

                printf("Them hanh khach thanh cong! Phi hanh ly qua cuoc: %.0f VND\n",
                       danhSach[soLuong].phiHanhLy);

                soLuong++;
                break;

            case 2:
                if (soLuong == 0) {
                    printf("Danh sach hanh khach hien dang rong!\n");
                    break;
                }

                tongDoanhThu = 0.0f;

                printf("\n----------------------------------------------------------------------------------------------------\n");
                printf("%-5s %-10s %-25s %-12s %-14s %-18s\n",
                       "STT", "Ma PNR", "Ho va Ten", "Hang ve",
                       "Hanh ly (kg)", "Phi Qua Cuoc (VND)");
                printf("----------------------------------------------------------------------------------------------------\n");

                for (i = 0; i < soLuong; i++) {
                    printf("%-5d %-10s %-25s %-12s %-14.1f %-18.0f\n",
                           i + 1,
                           danhSach[i].maPNR,
                           danhSach[i].hoTen,
                           danhSach[i].hangVe,
                           danhSach[i].canNangHanhLy,
                           danhSach[i].phiHanhLy);

                    tongDoanhThu += danhSach[i].phiHanhLy;
                }

                printf("----------------------------------------------------------------------------------------------------\n");
                printf("Tong doanh thu phi qua cuoc: %.0f VND\n", tongDoanhThu);
                break;

            case 3:
                if (soLuong == 0) {
                    printf("Danh sach hanh khach hien dang rong!\n");
                    break;
                }

                printf("\nNhap ma PNR can cap nhat: ");
                scanf("%14s", danhSach[100].maPNR);

                found = 0;

                for (i = 0; i < soLuong; i++) {
                    if (strcmp(danhSach[i].maPNR, danhSach[100].maPNR) == 0) {
                        found = 1;
                        viTri = i;
                        break;
                    }
                }

                if (found == 0) {
                    printf("Ma PNR khong ton tai trong he thong!\n");
                } else {
                    printf("Tim thay hanh khach: %s\n",
                           danhSach[viTri].hoTen);

                    printf("Nhap so kg hanh ly ky gui moi: ");
                    scanf("%f", &danhSach[viTri].canNangHanhLy);

                    if (strcmp(danhSach[viTri].hangVe, "Business") == 0) {
                        kgMienPhi = 30.0f;
                    } else if (strcmp(danhSach[viTri].hangVe, "Deluxe") == 0) {
                        kgMienPhi = 20.0f;
                    } else {
                        kgMienPhi = 0.0f;
                    }

                    if (danhSach[viTri].canNangHanhLy > kgMienPhi) {
                        danhSach[viTri].phiHanhLy =
                            (danhSach[viTri].canNangHanhLy - kgMienPhi) * 50000.0f;
                    } else {
                        danhSach[viTri].phiHanhLy = 0.0f;
                    }

                    printf("Cap nhat thanh cong! Phi hanh ly moi: %.0f VND\n",
                           danhSach[viTri].phiHanhLy);
                }
                break;

            case 4:
                if (soLuong == 0) {
                    printf("Danh sach hanh khach hien dang rong!\n");
                    break;
                }

                soBusiness = 0;
                tongDoanhThu = 0.0f;

                for (i = 0; i < soLuong; i++) {
                    if (strcmp(danhSach[i].hangVe, "Business") == 0) {
                        soBusiness++;
                    }

                    tongDoanhThu += danhSach[i].phiHanhLy;
                }

                printf("\n=== THONG KE CHUYEN BAY ===\n");
                printf("So luong hanh khach hang Business: %d\n", soBusiness);
                printf("Tong doanh thu phi qua cuoc: %.0f VND\n",
                       tongDoanhThu);
                break;

            case 5:
                printf("Cam on ban da su dung chuong trinh!\n");
                break;

            default:
                printf("Lua chon khong hop le! Vui long chon lai.\n");
        }

    } while (luaChon != 5);

    return 0;
}


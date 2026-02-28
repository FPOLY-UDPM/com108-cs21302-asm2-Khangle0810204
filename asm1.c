/******************************************************************************
 * Họ và tên: [ĐIỀN TÊN TẠI ĐÂY]
 * MSSV:      [ĐIỀN MSSV TẠI ĐÂY]
 * Lớp:       [ĐIỀN LỚP TẠI ĐÂY]
 *****************************************************************************/

// Tạo file asm2.c và hoàn thiện nội dung Assignment từ nội dung file asm1.c


// Danh sách các chức năng trong ASM1:
// 1. Chức năng số 1: Kiểm tra số nguyên
// 2. Chức năng số 2. Tìm Ước số chung và bội số chung của 2 số 
// 3. Chức năng số 3: Chương trình tính tiền cho quán Karaoke
// 4. Chức năng số 4: Tính tiền điện 
// 5. Chức năng số 5: Chức năng đổi tiền 
// 6. Chức năng số 6: Xây dựng chức năng tính lãi suất vay ngân hàng vay trả góp 
// 7. Chức năng số 7: Xây dựng chương trình vay tiền mua xe
// 8. Chức năng số 8: Sắp xếp thông tin sinh viên
// 9. Chức năng số 9: Xây dựng game FPOLY-LOTT
// 10. Chức năng số 10: Xây dựng chương trình tính toán phân số 
// Viết chương trình C thực hiện các chức năng trên

#include <stdio.h>
#include <math.h>


void chucNang1() {
    float x;
    printf("\n--- KIEM TRA SO NGUYEN ---\n");
    printf("Nhap vao so x: ");
    scanf("%f", &x);

 
    if (x == (int)x) {
        printf("%.0f la so nguyen.\n", x);
        int n = (int)x;

       
        int count = 0;
        if (n < 2) count = 1;
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) count++;
        }
        if (count == 0) printf("%d la so nguyen to.\n", n);
        else printf("%d khong phai la so nguyen to.\n", n);

        int cp = sqrt(n);
        if (cp * cp == n) printf("%d la so chinh phuong.\n", n);
        else printf("%d khong phai la so chinh phuong.\n", n);
    } else {
        printf("%.2f khong phai la so nguyen.\n", x);
    }
}


void chucNang2() {
    int a, b;
    printf("\n--- TIM UC VA BC ---\n");
    printf("Nhap so nguyen x: "); scanf("%d", &a);
    printf("Nhap so nguyen y: "); scanf("%d", &b);
    
    int x = abs(a), y = abs(b);
    int tich = x * y;
    
    while (x != y) {
        if (x > y) x -= y;
        else y -= x;
    }
    int ucln = x;
    int bcnn = tich / ucln;
    
    printf("Uoc so chung lon nhat: %d\n", ucln);
    printf("Boi so chung nho nhat: %d\n", bcnn);
}


void chucNang3() {
    int gioBD, gioKT;
    printf("\n--- TINH TIEN KARAOKE ---\n");
    printf("Nhap gio bat dau (12h-23h): "); scanf("%d", &gioBD);
    printf("Nhap gio ket thuc: "); scanf("%d", &gioKT);

    
    if (gioBD < 12 || gioKT > 23 || gioBD > gioKT) {
        printf("Quan chi hoat dong trong khoang 12h den 23h!\n");
        return;
    }

    int thoiGian = gioKT - gioBD;
    double tongTien = 0;

 
    if (thoiGian <= 3) {
        tongTien = thoiGian * 150000;
    } else {
        tongTien = 3 * 150000 + (thoiGian - 3) * 150000 * 0.7;
    }

    
    if (gioBD >= 14 && gioBD <= 17) {
        tongTien *= 0.9;
    }
    printf("So tien can thanh toan: %.0f VND\n", tongTien);
}


void chucNang4() {
    float kwh, tien = 0;
    printf("\n--- TINH TIEN DIEN ---\n");
    printf("Nhap so kWh su dung: "); scanf("%f", &kwh);

    
    if (kwh <= 50) tien = kwh * 1678;
    else if (kwh <= 100) tien = 50 * 1678 + (kwh - 50) * 1734;
    else if (kwh <= 200) tien = 50 * 1678 + 50 * 1734 + (kwh - 100) * 2014;
    else if (kwh <= 300) tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + (kwh - 200) * 2536;
    else if (kwh <= 400) tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + (kwh - 300) * 2834;
    else tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + 100 * 2834 + (kwh - 400) * 2927;

    printf("So tien dien phai tra: %.0f VND\n", tien);
}


void chucNang5() {
    int menhGia[] = {500, 200, 100, 50, 20, 10, 5, 2, 1}; 
    int soTien;
    printf("\n--- DOI TIEN ---\n");
    printf("Nhap so tien can doi: "); scanf("%d", &soTien);

    printf("Ket qua doi tien:\n");
    for (int i = 0; i < 9; i++) {
        int soTo = soTien / menhGia[i];
        if (soTo > 0) {
            printf("%d to menh gia %d\n", soTo, menhGia[i]);
        }
        soTien %= menhGia[i];
    }
}


void chucNang6() {
    double vay, conLai;
    double laiSuat = 0.05; /
    int kyHan = 12;        
    printf("\n--- LAI SUAT VAY TRA GOP ---\n");
    printf("Nhap so tien muon vay: "); scanf("%lf", &vay);

    double gocPhaiTra = vay / kyHan;
    conLai = vay;


    printf("\n%-10s %-15s %-15s %-15s %-15s\n", "Ky han", "Lai phai tra", "Goc phai tra", "So tien tra", "Con lai");
    for (int i = 1; i <= kyHan; i++) {
        double laiPhaiTra = conLai * laiSuat;
        double tongTra = gocPhaiTra + laiPhaiTra;
        conLai -= gocPhaiTra;
        if (conLai < 0) conLai = 0;
        printf("%-10d %-15.0f %-15.0f %-15.0f %-15.0f\n", i, laiPhaiTra, gocPhaiTra, tongTra, conLai);
    }
}

int main() {
    int chonChucNang;
    do {
        printf("\n========== MENU ASM2 ==========\n");
        printf("1. Kiem tra so nguyen\n");
        printf("2. Tim UCLN va BCNN\n");
        printf("3. Tinh tien Karaoke\n");
        printf("4. Tinh tien dien\n");
        printf("5. Chuc nang doi tien\n");
        printf("6. Lai suat vay tra gop\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &chonChucNang);

        switch (chonChucNang) {
            case 1: chucNang1(); break;
            case 2: chucNang2(); break;
            case 3: chucNang3(); break;
            case 4: chucNang4(); break;
            case 5: chucNang5(); break;
            case 6: chucNang6(); break;
            case 0: printf("Thoat chuong trinh.\n"); break;
            default: printf("Lua chon khong hop le!\n");
        }
    } while (chonChucNang != 0);
    return 0;
}
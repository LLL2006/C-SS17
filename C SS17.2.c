#include <stdio.h>

void nhapChuoi(char **str) {
    char temp[100];
    printf("Nhap vao chuoi: ");
    getchar();
    fgets(temp, sizeof(temp), stdin);

    *str = (char *)malloc(strlen(temp) + 1);

    strcpy(*str, temp);
}

void inChuoi(char *str) {
        printf("Chuoi da nhap: %s\n", str);
}


void demChu(char *str) {
	int count = 0;
    for (char *ptr = str; *ptr != '\0'; ptr++) {
        if (isalpha(*ptr)) {
            count++;
        }
    }	
    printf("So luong chu cai trong chuoi la: %d\n", count);
}

void demSo(char *str) {
    int count = 0;
    for (char *ptr = str; *ptr != '\0'; ptr++) {
        if (isdigit(*ptr)) {
            count++;
        }
    }
    printf("So luong chu so trong chuoi la: %d\n", count);
}

void demDacBiet(char *str) {
    int count = 0;
    for (char *ptr = str; *ptr != '\0'; ptr++) {
        if (!isalnum(*ptr) && !isspace(*ptr)) { 
            count++;
        }
    }
    printf("So luong ky tu dac biet trong chuoi la: %d\n", count);
}

int main() {
    char *str;
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi\n");
        printf("3. Dem so luong chu cai trong chuoi va in ra\n");
        printf("4. Dem so luong chu so trong chuoi va in ra\n");
        printf("5. Dem so luong ky tu dac biet trong chuoi va in ra\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapChuoi(&str);
                break;
            case 2:
                inChuoi(str);
                break;
            case 3:
                demChu(str);
                break;
            case 4:
                demSo(str);
                break;
            case 5:
                demDacBiet(str);
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le, vui long thu lai!\n");
        }
    } while (choice != 6);

    free(str);
    
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void nhapChuoi(char **str);
void daoNguoc(char *input, char *reverse);
void demTu(char *input);
void soChuoi(char *input);
void inHoaChuoi(char *input);
void themChuoi(char **input);

int main() {
	char *input;
    char reverseString[100];
	int choice;
	
	do{
		printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi dao nguoc\n");
        printf("3. Dem so luong tu trong chuoi\n");
        printf("4. Nhap vao chuoi khac, so sanh chuoi do voi chuoi ban dau\n");
        printf("5. In hoa tat ca chu cai trong chuoi\n");
        printf("6. Nhap vao chuoi khac va them chuoi do vao chuoi ban dau\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                nhapChuoi(&input);
                break;
            case 2:
            	daoNguoc(input, reverseString);
                printf("Chuoi dao nguoc: %s \n", reverseString);
                break;
            case 3:
            	demTu(input);
                break;
            case 4:
                soChuoi(input);
                break;
            case 5:
                inHoaChuoi(input);
                break;
            case 6:
            	themChuoi(&input);
            	break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le, vui long thu lai!\n");
        }
    } while (choice != 7);
	
	free(input);
    
    return 0;
}

void nhapChuoi(char **str) {
    char temp[100];
    printf("Nhap vao chuoi: ");
    getchar();
    fgets(temp, sizeof(temp), stdin);

    *str = (char *)malloc(strlen(temp) + 1);

    strcpy(*str, temp);
}

void daoNguoc(char *input, char *reverse) {
	int length = strlen(input);
	char*end = input + length - 1;
	
	while(end >= input) {
		*reverse = *end;
		reverse++;
		end--;
	}
	*reverse = '\0';
}

void demTu(char *input) {
	int tu = 1;
	

    printf("Chuoi ban da khai bao: %s\n", input);

    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == ' ') {
            tu++;
        }
    }

    printf("So tu trong chuoi: %d\n", tu);

}

void soChuoi(char *input) {
	char tempString[100];
    printf("Nhap vao chuoi khac: ");
    fgets(tempString, sizeof(tempString), stdin);
    tempString[strcspn(tempString, "\n")] = '\0';

    if (strlen(tempString) > strlen(input)) {
        printf("Chuoi moi dai hon chuoi ban dau.\n");
    } else if (strlen(tempString) < strlen(input)) {
        printf("Chuoi moi ngan hon chuoi ban dau.\n");
    } else {
        printf("Chuoi moi co do dai bang chuoi ban dau.\n");
    }
}

void inHoaChuoi(char *input) {
    char *ptr = input;
    while (*ptr) {
        *ptr = toupper(*ptr);
        ptr++;
    }
    printf("Chuoi sau khi in hoa: %s\n", input);
}

void themChuoi(char **input) {
    char tempString[100];
    printf("Nhap vao chuoi khac: ");
    fgets(tempString, sizeof(tempString), stdin);
    tempString[strcspn(tempString, "\n")] = '\0';

    *input = (char *)realloc(*input, strlen(*input) + strlen(tempString) + 1);
    
    strcat(*input, tempString);
    printf("Chuoi sau khi them: %s\n", *input);
}

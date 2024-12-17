#include <stdio.h>

void nhapMang(int *arr, int size);
void inMang(int *arr, int size);
int tinhTong(int *arr, int size);
int timMax(int *arr, int size);

int main() {
	int choice;
	int arr[100];
	int size=0;
	do{
		printf("\n MENU \n");
		printf("1. Nhap vao so phan tu va tung phan tu \n");
		printf("2. Hien thi cac so phan tu trong mang \n");
		printf("3. Tinh do dai mang \n");
		printf("4. Tinh tong cac phan tu trong mang \n");
		printf("5. Hien thi phan tu lon nhat \n");
		printf("6. Thoat \n");
		printf("Hay chon chuc nang: ");
		scanf("%d",&choice);
		switch(choice){
			case 1: 
				printf("Nhap so phan tu cho mang: ");
				scanf("%d", &size);
	
				nhapMang( arr, size);
				break;
			case 2: 
				inMang( arr, size);
				break;
			case 3: 
				printf("Do dai mang hien tai la: %d\n", size);
				break;
			case 4: 
				printf("Tong cac phan tu trong mang la: %d\n", tinhTong(arr, size));
				break;
			case 5: 
				printf("Phan tu lon nhat trong mang la: %d\n", timMax(arr, size));
				break;
			case 6: 
			printf("Thoat chuong trinh");
				break;	
			default:
				printf("Du lieu khong hop le");					
		}
	}while(choice!=6);
	
	return 0;
}

 nhapMang(int *arr, int size) {
	
	for(int i=0; i < size; i++) {
		printf("Nhap phan tu thu %d: ", i + 1);
		scanf("%d", &arr[i]);
		}
	}
	
	
 inMang(int *arr, int size) {
	printf("Cac phan tu trong mang la: \n");
	for(int i=0; i<size; i++){
		printf("arr[%d] = %d \n", i, *(arr+i));
		}
	}

 int tinhTong(int *arr, int size) {
 	int sum =0;
 	for(int i=0; i< size; i++){
 		sum += arr[i];
	 }
	 return sum;
 }
 
 int timMax(int *arr, int size) {
 	int max = arr[0];
 	for(int i=1; i<size; i++) {
 		if(arr[i] > max){
 			max = arr[i];
		 }
	 }
	 return max;
 }

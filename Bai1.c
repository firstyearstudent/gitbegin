#include<stdio.h>

enum{Red = 0, White = 1, Blue = 2}; //Định nghĩa màu
//Hàm nhập dãy màu
void ColorInserting(int arr[], int n){
    printf("Nhap day mau: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        if(arr[i] < Red || arr[i] > Blue){
            printf("\nCo mau khong hop le \n");
            return;
        }
    }
}
//Hàm sắp xếp màu
void ColorSorting(int arr[], int n){
    int temp;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
//Hàm hiển thị dãy màu đã sắp xếp
void DisplaySortedColor(int arr[], int n){
    printf("\nDay mau da duoc sap xep: \n");
    for(int i = 0; i < n; i++){
        switch(arr[i]){
            case Red:
            printf("Red ");
            break;
            case White:
            printf("White ");
            break;
            case Blue:
            printf("Blue ");
            break;
        }
    }
    printf("\n");
}

int main(){
    printf("Nhap so mau: ");
    int n; //Số màu trong dãy
    scanf("%d", &n);
    int arr[n]; //Khai báo dãy màu
    ColorInserting(arr, n);
    ColorSorting(arr, n);
    DisplaySortedColor(arr, n);
    return 0;
}
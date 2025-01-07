#include<stdio.h>
void input(int *array,int *size){
	for(int i=0;i<*size;i++){
		printf("moi ban nhap phan tu %d la: ",i+1);
		scanf("%d",&*(array+i));
	}
}
void printfEven(int *array,int *size){
	printf("cac phan tu chan la: ");
	for(int i=0;i<*size;i++){
		if(array[i]%2==0){
		printf("%d ",*(array+i));
	    }
	}
	printf("\n");
}
int isPrime(int n){
	if(n<2){
		return 0;
	}
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			return 0;
		}
	}
	return 1;
}
void printfIsPrime(int *array,int *size){
	int check=1;
	printf("cac so nguyen to la: ");
	for(int i=0;i<*size;i++){
		if(isPrime(*(array+i))){
			printf("%d ",*(array+i));
			check=0;
		}
	}
	printf("\n");
	if(check){
		printf("trong mang khong co so nguyen to\n");
	}
}
void printfReverse(int *array,int *size){
	int sizeMax=*size;
	for(int i=0;i<*size/2;i++){
		int temp=*(array+i);
		*(array+i)=*(array+sizeMax-1);
		*(array+sizeMax-1)=temp;
		sizeMax--;
	}
	for(int j=0;j<*size;j++){
		printf("%d ",*(array+j));
	}
	printf("\n");
}
void tangDan(int *array,int size){
	for(int i=0;i<size-1;i++){
		for(int j=0;j<size-1-i;j++){
			if(*(array+j)>*(array+j+1)){
				int temp=*(array+j);
				*(array+j)=*(array+j+1);
				*(array+j+1)=temp;
			}
		}
	}
	printf("mang duoc sap xep tang dan la: ");
	for(int i=0;i<size;i++){
		printf("%d ",*(array+i));
	}
	printf("\n");
}
void giamDan(int *array,int size){
	for(int i=0;i<size-1;i++){
		for(int j=0;j<size-1-i;j++){
			if(*(array+j)<*(array+j+1)){
				int temp=*(array+j);
				*(array+j)=*(array+j+1);
				*(array+j+1)=temp;
			}
		}
	}
	printf("mang duoc sap xep giam dan la: ");
	for(int i=0;i<size;i++){
		printf("%d ",*(array+i));
	}
	printf("\n");
}
void searchValue(int *array,int *size,int *search){
	int check=1;
	for(int i=0;i<*size;i++){
		if(array[i]==*search){
		printf("phan tu %d nam o vi tri %d trong mang",*search,i);
		check=0;
		break;
	    }
	}
	if(check){
		printf("phan tu %d khong nam trong mang",search);
	}
	printf("\n");
}
int main(){
	int chose=0,array[100],size,check=1;
	do{
	printf("-----------MENU------------\n");
	printf("1. Nhap vao so phan tu va tung phan tu\n");
	printf("2. In ra cac phan tu la so chan\n");
	printf("3. In ra cac phan tu la so nguyen to\n");
	printf("4. Dao nguoc mang\n");
	printf("5. Sap xep mang\n");
	printf("6. Nhap vao mot phan tu va tim kiem phan tu trong mang\n");
	printf("7. Thoat\n");
	printf("Lua chon cua ban: ");
	scanf("%d",&chose);
		switch(chose){
			case 1:
				printf("moi ban nhap so phan tu: \n");
            	scanf("%d",&size);
				input(array,&size);
				check=0;
				break;
			case 2:
				if(check){
					printf("moi ban nhap phan tu: \n");
				}else{
					printfEven(array,&size);
				}
				break;
			case 3:
				if(check){
					printf("moi ban nhap phan tu: \n");
				}else{
					printfIsPrime(array,&size);
				}
				break;
			case 4:
				if(check){
					printf("moi ban nhap phan tu: \n");
				}else{
					printfReverse(array,&size);
				}
				break;
			case 5:
				int choose;
				if(check){
					printf("moi ban nhap phan tu: \n");
				}else{
					printf("1. Tang dan\n");
					printf("2. Giam dan\n");
					printf("3. thoat\n");
					printf("lua chon cua ban: ");
					scanf("%d",&choose);
					switch(choose){
						case 1:
							tangDan(array,size);
							break;
						case 2:
							giamDan(array,size);
							break;
					}
				}
				break;
			case 6:
				int search;
				if(check){
					printf("moi ban nhap phan tu: \n");
				}else{
					printf("moi ban nhap phan tu de tim: ");
					scanf("%d",&search);
					searchValue(array,&size,&search);
				}
				break;
			
		}
	}while(chose!=7);
	return 0;
}

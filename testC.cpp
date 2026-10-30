#include<stdio.h>

#define MAX_SIZE 50

int main(){
	int stock[MAX_SIZE] = {10, 25, 30, 15, 40};
	int n = 5;
	int pos, choice, value, newValue, target;
	int i,count;
	
	do{
		printf("\n========================================\n");
        printf("   CHUONG TRINH QUAN LY TON KHO\n");
        printf("========================================\n");
        printf("1. Them so luong ton kho\n");
        printf("2. Sua so luong ton kho\n");
        printf("3. Xoa so luong ton kho\n");
        printf("4. Tim kiem so luong ton kho\n");
        printf("0. Thoat chuong trinh\n");
        printf("========================================\n");
        
        printf("Vui long nhap lua chon: ");
        scanf("%d",&choice);
        
		switch(choice){
			case 1:
				if(n== MAX_SIZE){
		        	printf("Mang da day");
		        	break;
				}
				
				printf("Nhap so muon chen: ");
				scanf("%d",&value);
				
				printf("Nhap vi tri muon chen: ");
				scanf("%d",&pos);
				
				if(pos < 1 || pos >n){
					printf("vi tri k hop le");
					break;
				}
				
				for(i = n; i>= pos; i--){
					stock[i] = stock[i-1];
				}
				
				stock[pos - 1] = value;
				n++;
				
				printf ("Mang sau khi them la: ");
				for(i=0; i<n; i++){
					printf("%d",stock[i]);
					
					if(i<n-1){
						printf(",");
					}
				}
				break;
			case 2:
				printf("Nhap vi tri muon sua: ");
				scanf("%d",&pos);
				
				if(pos < 1 || pos >n+1){
					printf("vi tri k hop le");
					break;
				}
				printf("Nhap gia tri moi: ");
				scanf("%d",&newValue);
				if(newValue<0){
					printf("So luong ton kho khong hop le!");
					break;
				}
				
				stock[pos -1] = newValue;
				
				printf("Mang sau khi sua la: ");
				for(i=0; i<n; i++){
					printf("%d", stock[i]);
					
					if(i<n-1){
						printf(",");
					}
				}
				break;
			case 3:
				if(n== 0){
					printf("Mang trong");
					break;
				}
				printf("Nhap vi tri can xoa: ");
                scanf("%d", &pos);

                if (pos < 1 || pos > n) {
                    printf("Vi tri xoa khong hop le!\n");
                    break;
                }
				
				for(i=pos -1; i<n-1; i++){
					stock[i]= stock[i+1];
				}
				
				n--;
				for(i=0; i<n; i++){
					printf("%d", stock[i]);
					
					if(i<n-1){
						printf(",");
					}
				}

				break;
			case 4:
				printf("Nhap so can tim: ");
				scanf("%d",&target);
				count = 0;
				for(i=0; i<n; i++){
					if(stock[i]== target){
						printf("%d",i+1);
						count ++;
					}
				}
				if(count == 0){
					printf("Khong tim thay");
				}else{
					printf("So lan xuat hien la: %d",count);
				}
				
				break;
			case 0: 
				printf("Thoát chuong trinh thanh cong!");
				break;
			default:
				printf("Lua chon khong hop le");
		}
	}while(choice != 0);
}


//
// ATM Program:
// 1. Login:
//		Username: hungcd
//		Password: 1a@
// 2. Withdraw
// 3. Tranfer
// 4. Check
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Login(char username[], char password[]);
void Menu();
int Withdraw(int Balance, int num);
int Transfer(int id, int num, int Balance);

int main() {
	char username[10], password[10];
	int count1 = 0, count2 = 0;
	int opt = 0;
	int num1;
	int num2, Balance = 50000000;
	int id, num3;
	char ch;
	Login:
	while(count1<3){
		printf("\nUsername: ");												
		scanf("%s", username);
		printf("Password: ");
		scanf("%s", password);
		if(Login(username, password)==1)
			count1++;
		else{
			printf("Your ID: 123456\n");
			do{
				Menu();
				printf("\nNhap lua chon: ");
				scanf("%d", &opt);
				switch(opt){
					case 1:
						count2=0;
						printf("\nSo tien can rut: ");
						scanf("%d", &num1);
						Balance = Withdraw(Balance, num1);
						break;
					case 2:
						count2=0;
						printf("\nNhap ID nguoi nhan: ");
						scanf("%d", &id);
						printf("\nNhap so tien can chuyen: ");
						scanf("%d", &num3);
						Balance = Transfer(id, num3, Balance);
						break;
					case 3:
						count2=0;
						printf("So du: %d", Balance);
						break;
					case 4:
						exit(0);
					default:
						printf("\nLua chon khong dung!");
						count2++;
						break;
				}
				if(count2<3){
					printf("\n\nTiep tuc giao dich! (Y/N): ");
					fflush(stdin);
					ch = getchar();
					system("cls");
				}
				else{
					printf("\n\nNhap sai 3 lan!\nVui long dang nhap lai...\n");
					goto Login;
				}
			}while(ch == 'Y' || ch == 'y');
			printf("\nXin cam on hen gap lai quy khach!");
			break;
		}
	}
	if(count1 == 3){
		printf("\nNhap sai qua 3 lan! vui long lien he CSKH.");
	}

	return 0;
}

// Login function
int Login(char username[], char password[]){
	if(strcmp(username,"hungcd") != 0|| strcmp(password,"1a@") != 0){
		printf("\nTai khoan hoac mat khau khong dung!\nVui long nhap lai...\n");
		return 1;
	}
	else return 0;
}

// Menu function
void Menu(){
	printf("\n1. Rut tien\n2. Chuyen khoan\n3. Kiem tra so du\n4. Exit\n");
}

// Withdraw function
int Withdraw(int Balance, int num){
	if(num>Balance)
		printf("\nVuot qua so du!");
	else if(num > 3000000)
		printf("\nSo tien rut phai nho hon 3.000.000");
	else if(num%50000 != 0)
		printf("\nBan phai nhap so tien la boi cua 50.000");
	else{
		printf("\n\tVui long nhan tien tai khay dung ben duoi\n");
		Balance -= num;
		printf("\nSo du: %d", Balance);
	}
	return Balance;
}

// Transfer function
int Transfer(int id, int num, int Balance){
	if(num>Balance){
		printf("\nVuot qua so du!");
	}
	else{
		Balance -= num;
		printf("\nID %d: +%d", id, num);
		printf("\nID 123456: -%d", num);
		printf("\nSo du: %d", Balance);
	}
	return Balance;
}



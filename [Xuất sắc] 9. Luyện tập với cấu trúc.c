#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct information {
    int id;
    char name[50];
    int age;
    char phone[20];
};
void infDelete();
void infPrint();
void infAdd();
void infChang();
void infFind();
void infArg();

struct information *studen;
int main(void){
    studen = (struct information*) malloc(5 *sizeof(struct information));
    if (studen == NULL) {
        return 0;
    }
    strcpy(studen[0].name, "Nguyen van A"); studen[0].age = 18; strcpy(studen[0].phone, "84+ 123 321 534");
    strcpy(studen[1].name, "Nguyen van B"); studen[1].age = 19; strcpy(studen[1].phone, "84+ 865 767 534");
    strcpy(studen[2].name, "Nguyen van C"); studen[2].age = 20; strcpy(studen[2].phone, "84+ 435 322 456");
    strcpy(studen[3].name, "Nguyen van D"); studen[3].age = 22; strcpy(studen[3].phone, "84+ 657 321 089");
    strcpy(studen[4].name, "Nguyen van E"); studen[4].age = 19; strcpy(studen[4].phone, "84+ 435 321 767");

    int i = 0;
    int menu, menu2;;
    int pos;
    while(studen[i].name[0] != '\0') {
        studen[i].id = i + 1;
        i++;
    }
  do {
      printf("1.Hien thi danh sach sinh vien\n");
      printf("2.Them sinh vien\n");
      printf("3.Sua thong tin sinh vien\n");
      printf("4.Xoa sinh vien\n");
      printf("5.Tim kiem sinh vien\n");
      printf("6.Sap xep danh sach sinh vien theo ten\n");
      printf("7.Thoat\n");
      printf("Enter your number: ");
      scanf("%d", &menu);
      switch (menu) {
          case 1:
              if( i < 1) {
                  printf("Empty!!!!!!\n");
              }
              infPrint(studen);
          goto menu1;
          case 2:
              printf("nhap vi tri muon them: ");
              scanf("%d", &pos);
              infAdd(studen, pos, i);
              goto menu1;
          case 3:
              printf("nhap vi tri muon Sua: ");
              scanf("%d", &pos);
            infChang(studen, pos);
              goto menu1;
          case 4:
              printf("nhap vi tri muon xoa: ");
              scanf("%d", &pos);
              infDelete(studen, pos);
              i--;
              goto menu1;
          case 5:
              printf("nhap ID sinh vien can tim: ");
              scanf("%d", &pos);
              infFind(studen, pos);
              goto menu1;
          case 6:
              infArg(studen, pos);
              goto menu1;

          default:
              if(menu == 7) {
                  printf("Da thoat");
                  return 0;
              }
              printf("Invalid\n");
          menu1:
          do {
              printf("\n");
              printf("1.Back to menu\n");
              printf("2.Exit\n");
              scanf("%d", &menu2);
          }while (menu2 != 1 && menu2 != 2);
          if (menu2 == 2) {
              free(studen);
              return 0;
          }
              break;
      }
  }while (menu !=  7);

    free(studen);
    return 0;
}
void infDelete(struct information studen[], int pos) {
    int i = 0;
    while (studen[i].name[0] != '\0') {
        if (studen[i].id == pos) {
            while (studen[i].name[0] != '\0') {
                studen[i].id = studen[i + 1].id;
                strcpy(studen[i].name, studen[i + 1 ].name);
                studen[i].age = studen[i + 1].age;
                strcpy(studen[i].phone, studen[i + 1].phone);
                i++;
            }
            break;
        }
        i++;
    }
}

void infPrint(struct information studen[]) {
    int i = 0;
    while(studen[i].name[0] != '\0') {
        printf("___________________________________________________\n");
        printf("ID: %d\t|", studen[i].id);
        printf("Name: %s\t|", studen[i].name);
        printf("Age: %d\t|", studen[i].age);
        printf("Phone: %s\t|\n", studen[i].phone);
        i++;
    }
}

void infAdd(struct information studen[], int pos, int num){
    for(int i = num; i >= pos; i--){
        studen[i + 1].id = studen[i].id;
        strcpy(studen[i + 1].name, studen[i].name);
        studen[i + 1].age = studen[i].age;
        strcpy(studen[i + 1].phone, studen[i].phone);
    }
    studen[pos].id = num + 1;
    fflush(stdin);
    printf("Nhap ten Ten: ");
    fgets(studen[pos].name, sizeof(studen[pos].name), stdin);
    studen[pos].name[strlen(studen[pos].name) - 1] = '\0';
    fflush(stdin);
    printf("nhap Tuoi ");
    scanf("%d", &studen[pos].age);
    getchar();
    printf("Nhap SDT: ");
    fgets(studen[pos].phone, sizeof(studen[pos].phone), stdin);
    studen[pos].phone[strlen(studen[pos].phone) - 1] = '\0';
    fflush(stdin);
}
void infChang(struct information studen[], int pos) {
    fflush(stdin);
    printf("Nhap ten Ten: ");
    fgets(studen[pos].name, sizeof(studen[pos].name), stdin);
    studen[pos].name[strlen(studen[pos].name) - 1] = '\0';
    fflush(stdin);
    printf("nhap Tuoi ");
    scanf("%d", &studen[pos].age);
    getchar();
    printf("Nhap SDT: ");
    fgets(studen[pos].phone, sizeof(studen[pos].phone), stdin);
    studen[pos].phone[strlen(studen[pos].phone) - 1] = '\0';
    fflush(stdin);
}
void infFind(struct information studen[], int pos) {
    int i = 0;
    while(studen[i].name[0] != '\0') {
        if(studen[i].id == pos) {
            printf("Da tim thay tai vi tri %d trong danh sach", i + 1);
        }
        i++;
    }
}

void infArg(struct information studen[]) {
    int i = 1;
    while(studen[i].name[0] != '\0') {
        int j = 0;
        while(studen[j].name[0] != '\0') {
            if(strcmp(studen[i].name, studen[j].name) < 0) {
                char tempName[50];
                strcpy(tempName, studen[i].name);
                strcpy(studen[i].name, studen[j].name);
                strcpy(studen[j].name, tempName);
            }
            j++;
        }
        i++;
    }
}

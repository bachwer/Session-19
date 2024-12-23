#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct information {
    int id;
    char name[50];
    int age;
    char phone[20];
};
void infArg();
void infPrint();
struct information *studen;
int main(void){
    studen = (struct information*) malloc(5 *sizeof(struct information));
    if (studen == NULL) {
        return 0;
    }
    strcpy(studen[0].name, "Nguyen van A"); studen[0].age = 18; strcpy(studen[0].phone, "84+ 123 321 534");
    strcpy(studen[1].name, "Nguyen van s"); studen[1].age = 19; strcpy(studen[1].phone, "84+ 865 767 534");
    strcpy(studen[2].name, "Nguyen van B"); studen[2].age = 20; strcpy(studen[2].phone, "84+ 435 322 456");
    strcpy(studen[3].name, "Nguyen van D"); studen[3].age = 22; strcpy(studen[3].phone, "84+ 657 321 089");
    strcpy(studen[4].name, "Nguyen van C"); studen[4].age = 19; strcpy(studen[4].phone, "84+ 435 321 767");
    int i = 0;
    int mot;
    while(studen[i].name[0] != '\0') {
        studen[i].id = i + 1;
        i++;
    }
        infPrint(studen);
    do {
        printf("Nhap phim '1' de xap xep: ");
        scanf("%d", &mot);
    }while (mot != 1);
        infArg(studen);
        infPrint(studen);
        free(studen);
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

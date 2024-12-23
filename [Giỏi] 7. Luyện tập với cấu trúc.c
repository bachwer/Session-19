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
struct information *studen;
int main(void){
    studen = (struct information*) malloc(5 *sizeof(struct information));
    if (studen == NULL) {
        return 0;
    }
    strcpy(studen[0].name, "Nguyen van A"); studen[0].id = 18; strcpy(studen[0].phone, "84+ 123 321 534");
    strcpy(studen[1].name, "Nguyen van B"); studen[1].id = 19; strcpy(studen[1].phone, "84+ 865 767 534");
    strcpy(studen[2].name, "Nguyen van C"); studen[2].id = 20; strcpy(studen[2].phone, "84+ 435 322 456");
    strcpy(studen[3].name, "Nguyen van D"); studen[3].id = 22; strcpy(studen[3].phone, "84+ 657 321 089");
    strcpy(studen[4].name, "Nguyen van E"); studen[4].id = 19; strcpy(studen[4].phone, "84+ 435 321 767");
    int i = 0;
    int pos;
    while(studen[i].name[0] != '\0') {
        studen[i].id = i + 1;
        i++;
    }
        printf("Enter the ID of studen to delete: ");
    do {
        scanf("%d", &pos);
        if(pos < 1 || pos > i) {
            printf("invalid!!");
        }
    }while (pos < 1 || pos > i);
        infDelete(studen, pos);
        infPrint(studen);
    free(studen);
}
void infDelete(struct information studen[], int pos) {
    int i = 0;
    while (studen[i].name[0] != '\0') {
        if (studen[i].id == pos) {
            // Shift subsequent elements to the left
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
        printf("ID: %d\t|", studen[i].age);
        printf("Phone: %s\t|\n", studen[i].phone);
        i++;
    }
}

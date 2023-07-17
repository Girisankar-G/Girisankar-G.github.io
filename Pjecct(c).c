#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Mobile {
    int imei;
    char name[50],brand[50];
    float price;
}mobile1[10000];
int count=0,choice=0;
void add(struct Mobile *mobile1,int *count){
    struct Mobile mobile2;
    printf("\nEnter mobile IMEI:");
    scanf("%ld",&mobile2.imei);
    printf("\nEnter the mobile brand:");
    scanf("%s",mobile2.brand);
    printf("\nEnter the model name:");
    scanf("%s",mobile2.name);
    printf("\nEnter mobile price:");
    scanf("%f",&mobile2.price);
    mobile1[*count]=mobile2;
    (*count)+=1;
    printf("\nMobile added successfully!");
}
int edit(struct Mobile *mobile1,int count){
    int imei,i;
    printf("\nEnter mobile ID to edit:");
    scanf("%ld",&imei);
    for (i=0;i<count;i++){
        if (mobile1[i].imei==imei) {
            printf("\nEnter new mobile brand:");
            scanf("%s",mobile1[i].brand);
            printf("\nEnter new model name:");
            scanf("%s",mobile1[i].name);
            printf("\nEnter new mobile price:");
            scanf("%f",&mobile1[i].price);
            printf("\nMobile information updated!");
            return 0;
        }
    }
    printf("\nMobile not found!");
}
void display(struct Mobile *mobile1, int count){
    int i;
    for (i=0;i<count;i++) {
        printf("\nMobile %d:",(i+1));
        printf("\nIMEI:%ld\nBrand:%s\nModel:%s\nPrice:%0.2f", mobile1[i].imei, mobile1[i].brand,mobile1[i].name,mobile1[i].price);
    }
}
int search(struct Mobile *mobile1,int count){
    int i,imei;
    printf("\nEnter IMEI no to search:");
    scanf("%ld",imei);
    printf("Search Results:\n");
    for(i=0;i<count;i++){
        if(imei==mobile1.imei){
            printf("\nMobile %d:",(i+1));
            printf("\nIMEI:%ld\nBrand:%s\nModel:%s\nPrice:%0.2f", mobile1[i].imei, mobile1[i].brand,mobile1[i].name,mobile1[i].price);
            return 0;
        }
    }
    printf("No mobile found with the given name.\n");
}
void del(struct Mobile *mobile1,int *count) {
    int imei,i,found=0;
    printf("\nEnter the mobile IMEI number:");
    scanf("%ld",&imei);
    for (i=0;i<*count;i++) {
        if (mobile1[i].imei==imei){
            found=1;
            break;
        }
    }
    if(found==1){
        for (i=0;i<(*count);i++){
            mobile1[i]=mobile1[i+1];
        }
        (*count)-=1;
        printf("Mobile deleted successfully!\n");
    } 
    else{
        printf("Mobile not found!\n");
    }
}
int main() {
    printf("\nMobile Shop Management System");
    printf("\n1.Add Mobile");
    printf("\n2.Edit Mobile");
    printf("\n3.Display Mobile");
    printf("\n4.Search Mobile");
    printf("\n5.Delete Mobile");
    printf("\n6.Exit");
    printf("\nEnter your choice:");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            add(mobile1,&count);
            break;
        case 2:
            edit(mobile1,count);
            break;
        case 3:
            display(mobile1,count);
            break;
        case 4:
            search(mobile1,count);
            break;
        case 5:
            del(mobile1,&count);
            break;
        case 6:
            printf("\nExiting the program...");
            return 0;
        default:
            printf("\nInvalid choice! Please try again.");
            break;
    }
    main();
}

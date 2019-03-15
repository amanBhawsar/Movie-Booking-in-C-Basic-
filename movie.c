#include<stdio.h>
#include<stdlib.h>

struct book
{
    char code[20];
    char name[20];
    char date[20];
    int cost;
} b;

int seat = 60 ;
void insert_details();
void viewAll();
void find();
void book_ticket();
void old_record();

void main(){
    int ch;
    do{
        printf("\n====================================================================");
        printf("\n");
        printf("\t Movie Ticket booking ");
        printf("\n");
        printf("\n====================================================================");

        printf("\nPress <1> Insert Movie");
        printf("\nPress <2> View All Movie");
        printf("\nPress <3> Find Movie ");
        printf("\nPress <4> Book Ticket");
        printf("\nPress <5> View All Transactions");
        printf("\nPress <0> Exit ");

        printf("\nEnter your Choice :");
        scanf("%d",&ch);

        switch (ch){
        case 0:exit(0);break;
        case 1:insert_details();break;
        case 2:viewAll();break;
        case 3:find();break;
        case 4:book_ticket();break;
        case 5:old_record();break;
        default:
            printf("Invalid option");
            break;
        }
    }
    while(ch!=0);
}


void insert_details()
{

    FILE *fp;
    struct book b;
    printf("Enter the Movie Code :- ");
    scanf("%s",b.code);
    printf("Enter Movie Name :- ");
    scanf("%s",b.name);
    printf("Enter Release Date :- ");
    scanf("%s",b.date);
    printf("Enter Ticket Price :- ");
    scanf("%d",&b.cost);

    fp=fopen("MovieMetadata.txt","a");

    if(fp == NULL){
        printf("File not Found");
    }
    else{
        fprintf(fp,"%s %s %s %d \n",b.code,b.name,b.date,b.cost);
        printf("\nRecord insert Successful\n");
    }
    printf("\n");
    fclose(fp);
}
void find(){
    struct book b;
    FILE *fp;
    char ch[20];
    printf("Enter movie code :");
    scanf("%s",ch);
    fp = fopen("MovieMetadata.txt","r");
    if(fp == NULL){
        printf("File Not Found !");
        exit(1);
    }
    else{
        while((getc(fp)) != EOF){
            fscanf(fp,"%s %s %s %d",b.code,b.name,b.date,&b.cost);
            if(strcmp(b.code,ch) == 0){
                printf("\n Record Found\n");
                printf("\n\t\tCode ::%s",b.code);
                printf("\n\t\tmovie name ::%s",b.name);
                printf("\n\t\tmovie date ::%s",b.date);
                printf("\n\t\tprice of ticket ::%d",b.cost);
                break;
            }
        }
    }
    fclose(fp);
}
void viewAll(){
    char ch;
    FILE *fp;
    fp = fopen("MovieMetadata.txt","r");
    if(fp == NULL){
        printf("File Not Found!");
        exit(1);
    }
    else{
        if((ch = fgetc(fp) )== EOF){
            printf("\n\tNo Movies are available right now\n");
        }
        else{
            printf("%c",ch);
        }
        while( ( ch = fgetc(fp) ) != EOF )
            printf("%c",ch);
    }
    fclose(fp);
}
void book_ticket(){
    struct book b;
    FILE *fp;
    FILE *mfp;
    int total_seat,mobile,total_amount;
    char name[20];
    char ch;
    char movie_code[20];
    fp = fopen("MovieMetadata.txt","r");
    if(fp == NULL){
        printf("File Not Found !");
        exit(1);
    }
    else{
        while( ( ch = fgetc(fp) ) != EOF )
            printf("%c",ch);
    }
    fclose(fp);
    printf("\n For Book ticket Choice Movie(Enter Movie Code First Letter Of Movie)\n");
    printf("\n Enter movie code :");
    scanf("%s",movie_code);
    fp = fopen("MovieMetadata.txt","r");
    if(fp == NULL){
        printf("File Not Found !");
        exit(1);
    }
    else{
        while(getc(fp) != EOF){
            fscanf(fp,"%s %s %s %d",b.code,b.name,b.date,&b.cost);
            if(strcmp(b.code,movie_code) == 0){
                printf("\n Record Found\n");
                printf("\n\t\tCode ::%s",b.code);
                printf("\n\t\tMovie name ::%s",b.name);
                printf("\n\t\tDate name ::%s",b.date);
                printf("\n\t\tPrice of ticket::%d",b.cost);
            }
        }
    }
    printf("\n* Fill Details  *");
    printf("\n Name :");
    scanf("%s",name);
    printf("\n Mobile Number :");
    scanf("%d",&mobile);
    printf("\n Total Number of Tickets :");
    scanf("%d",&total_seat);
    total_amount = b.cost * total_seat;
    printf("\n ******************** ENJOY MOVIE *******************\n");
    printf("\n\t\tname : %s",name);
    printf("\n\t\tmobile Number : %d",mobile);
    printf("\n\t\tmovie name : %s",b.name);
    printf("\n\t\tTotal seats : %d",total_seat);
    printf("\n\t\tcost per ticket : %d",b.cost);
    printf("\n\t\tTotal Amount : %d",total_amount);
    mfp=fopen("oldTransaction.txt","a");
    if(mfp == NULL){
        printf("File not Found");
    }
    else{
        fprintf(mfp,"%s %d %d %d %s %d \n",name,mobile,total_seat,total_amount,b.name,b.cost);
        printf("\n Record insert Successfully to the old transaction file");
    }
    printf("\n");
    fclose(mfp);
    fclose(fp);

}
void old_record(){
    char ch;
    FILE *fp;
    fp = fopen("oldTransaction.txt","r");
    if(fp == NULL){
        printf("File not Found !");
        exit(1);
    }
    else{
        if( ( ch = fgetc(fp) ) == EOF ){
            printf("\n\tNo transactions are Performed !\n");
        }
        else{
            printf("%c",ch);
        }
        while( ( ch = fgetc(fp) ) != EOF )
            printf("%c",ch);
    }
    fclose(fp);
}

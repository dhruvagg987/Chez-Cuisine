#include<stdio.h>//new
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
void menu();
void welcome();
void customer();
void bill(char[],int);
void bill_disp();
void chef(int);
void modify();
void insert();
void delet();
int emptycheck();
typedef struct FOOD
{
    //int no;
    char name[10];
    int price;
}Food;
typedef struct BIlling
{
    char name[10];
    int qty;
    int total;
}Billing;
void welcome()
{
    system("cls");
    printf("\n\n\n\n\n");Sleep(200);
printf("   \t\t\t\t\t                                                                       o  ");
printf(" \n\t\t\t\t\t            :: ::                                                  :: : : ::    ");
printf(" \n\t\t\t\t\t           ::   ::    ::    ::    :::::     :::::::              ''         ''  ");
printf(" \n\t\t\t\t\t          ::          ::    ::    ::            ::              ::           :: ");
printf(" \n\t\t\t\t\t          ::          ::    ::    ::           ::               ::           :: ");
printf(" \n\t\t\t\t\t          ::          ::::::::    ::::        ::                ::           :: ");
printf(" \n\t\t\t\t\t          ::          ::    ::    ::         ::                 ::           :: ");
printf(" \n\t\t\t\t\t           ::   ::    ::    ::    ::        ::                  ::           :: ");
printf(" \n\t\t\t\t\t            :: ::     ::    ::    ::::::   :::::::::         ::::::::::::::::::::::");
printf("\n\n\n");
printf("\n\t\t\t\t\t   :: :: ");
printf("\n\t\t\t\t\t  ::   ::  ::    ::   ::::::     :: ::    ::::::    :::      ::   :::::: ");
printf("\n\t\t\t\t\t ::        ::    ::     ::      ::   ::     ::      ::::     ::   ::     ");
printf("\n\t\t\t\t\t ::        ::    ::     ::       ::         ::      :: ::    ::   ::     ");
printf("\n\t\t\t\t\t ::        ::    ::     ::         ::       ::      ::   ::  ::   ::::   ");
printf("\n\t\t\t\t\t ::        ::    ::     ::           ::     ::      ::    :: ::   ::     ");
printf("\n\t\t\t\t\t  ::   ::  ::    ::     ::       ::   ::    ::      ::     ::::   ::     ");
printf("\n\t\t\t\t\t   :: ::    ::::::    ::::::      :::::   ::::::    ::       ::   :::::::");
printf("\n\n\n\n\n\n");

    int n;
    printf("\t\t1.CUSTOMER\n\n");
    printf("\t\t2.CHEF\n\n");
    printf("\t\t3.EXIT");Sleep(400);
    printf("\n\n\n    Enter : ");
    scanf("%d",&n);
    system("cls");
    switch(n)
    {
        case 1:customer();
         break;
        case 2:chef(0);
         break;
        case 3:system("cls");
                Sleep(400);
               printf("\n We Hope You Had A Great Experience With Us....\n\n");
                Sleep(900);
               printf(" HAVE A NICE DAY AHEAD :) !!\n\n\n");
                Sleep(1400);
               exit(0);
         break;
        default:system("cls");Sleep(300);
                printf("Invalid Choice");
                Sleep(400);
                welcome();
    }
}
void menu()
{
    system("cls");
    Food food;
    FILE* f=fopen("menu.txt","r");Sleep(500);
    printf("\n\n\t\t:::     :::  :::::  :::    ::  ::   :: \n");
    printf("\t\t::::   ::::  ::     ::::   ::  ::   :: \n");
    printf("\t\t:: :: :: ::  ::::   :: ::  ::  ::   :: \n");
    printf("\t\t::   ::  ::  ::     ::   ::::  ::   :: \n");
    printf("\t\t::       ::  :::::  ::    :::   :::::  \n\n\n\n");
    Sleep(400);
    printf("\t\t  DISH         PRICE\n\n");
    while(fread(&food,sizeof(Food),1,f))
    {
        Sleep(100);
        printf("\t\t  %-10s\t%-4d\n",food.name,food.price);
    }
    fclose(f);
}
void customer()
{
    menu();
    FILE*f=fopen("bill.txt","w");
    fclose(f);
    int n,qty;
    char c,fname[10];Sleep(500);
    printf("\n\nplace order ?(y/n)");
    scanf(" %c",&c);
    if(c=='n'||c=='N') welcome();
    while(c=='y'||c=='Y')
    {
        printf("\nDish : ");
        //scanf("%s",fname);
        getchar();
        gets(fname);
        printf("qty : ");
        scanf("%d",(int)&qty);
        bill(fname,qty);
        printf("\nDo you wish to order more dishes?(y/n)");
        scanf(" %c",&c);
    }
    printf("\nComfirm Order(y/n):");
    scanf(" %c",&c);
    if(c=='y'||c=='Y') bill_disp();
    else customer();
}
void bill(char fname[10],int qty)
{
    int mark=0;
    Food food;Billing billing;
    FILE *f=fopen("menu.txt","r");
    FILE *f2=fopen("bill.txt","a");
    while(fread(&food,sizeof(Food),1,f))
    {
        if(strncmp(fname,food.name,10)==0)
        {
            strcpy(billing.name,food.name);
            billing.qty=qty;
            billing.total=(food.price)*qty;
            fwrite(&billing,sizeof(Billing),1,f2);
            mark=1;
        }
    }
    if(mark==0) printf("no such dish");
    fclose(f);
    fclose(f2);
}
void bill_disp()
{
    system("cls");
    float total=0,temp;
    int i=1;
    Billing billing;
    FILE* f=fopen("bill.txt","r");Sleep(500);
    printf("\n\n\t\t  CHEZ\n      \t\t CUISINE\n\n\t   - - - - BILL - - - -\n");
    Sleep(100);
    printf("\n\tsno   Dish      Qty  Total\n");
    while(fread(&billing,sizeof(Billing),1,f))
    {
        total+=(float)billing.total;
        Sleep(100);
        printf("\n\t%d.   %-10s  %-2d   %d\n",i++,billing.name,billing.qty,billing.total);
    }
    Sleep(100);
    printf("\t               \t   ........   ");Sleep(100);
    printf("\n\n\t    Sub Total\t      %d\n",(int)total);Sleep(100);
    printf("\n\t    GST (@18)\t      %.2f",total*(0.18));Sleep(100);
    printf("\n\t    SGST(@9) \t      %.2f",total*(0.09));Sleep(100);
    printf("\n\t               \t   ........   ");
    total=total*(0.18)+total*(0.09)+total;Sleep(100);
    printf("\n\n\t   Grand Total\t    Rs %.2f\n",total);Sleep(100);
    printf("\t               \t   ........   ");Sleep(500);
    printf("\n\n\tThank YOU! Please Come Again.\n\n\n\n\n\n\n");
    fclose(f);
}
int password()
{
    int i;
    char c,pass[6],pas[6];
    printf("\n\n  Enter Password :- ");
    for(i=0;i<5;i++)
    {
        c=getch();
        pass[i]=c;
        printf("x");
    }
    //getch();
    pass[i]='\0';
    FILE* f=fopen("pass.txt","r");
    fgets(pas,6,f);
    fclose(f);
    if(strcmp(pass,pas)==0)
        return 1;
    else return 0;
}
void chef(int p)
{
   int n;
   while(p==0)
   {
    n=password();
    if(n==0)
    {
        system("cls");
        Sleep(400);
        printf("Password Not Matched.");
        Sleep(800);
        welcome();
    }
    else if(n==1)
    {
     system("cls");
     printf("\n  WELCOME CHEF");
     Sleep(600);p++;
    }
   }
     menu();
    printf("\n\n\t\t1.Modify\n\t\t2.Insert\n\t\t3.Delete\n\t\t4.Change Password\n\t\t5.Log Out\n\n");
    Sleep(500);
    printf("\t\tEnter Choice : ");
    scanf(" %d",&n);getchar();
    switch(n)
    {
        case 1:modify();
         break;
        case 2:insert();
         break;
        case 3:delet();
         break;
        case 4:
            system("cls");
            char pass[6];

            printf("Enter New 5 Character Password: ");
                //getchar();
            fgets(pass,6,stdin);
            FILE* f=fopen("pass.txt","w");
            fputs(pass,f);
            printf("\nPassword Changed Successfully !!");
            fclose(f);
            break;
        case 5:welcome();
         break;
        default:printf("Invalid Choice !!");
    }

}
int emptycheck()
{
    unsigned long l;
    FILE* f=fopen("menu.txt","r");
    fseek(f,0,SEEK_END);
    l=(unsigned long)ftell(f);
    if(l>0)
        return 1;
    else return 0;
    fclose(f);
}
void modify()
{
    system("cls");
    int n=emptycheck();
    if(n==0){ printf("\nFile Is Empty !!\n");Sleep(1000);chef(1);}
    else if(n==1)
    {
        menu();
        int mark=0;
        Food food;
        char fname[10];
        FILE* f2=fopen("temp.txt","w");
        FILE* f=fopen("menu.txt","r");
        printf("\n\nEnter Dish Name:");
        //scanf("%s",fname);
        gets(fname);
        //getchar();
        while(fread(&food,sizeof(Food),1,f))
        {
            if(strncmp(food.name,fname,10)==0)
            {
                printf("\nEnter Modified Details:\nName:");
                //scanf("%s",food.name);
                gets(food.name);
                printf("Price:");
                scanf("%d",&food.price);
                fwrite(&food,sizeof(Food),1,f2);
                mark=1;
            }
            else
            {
                fwrite(&food,sizeof(Food),1,f2);
            }
        }
        fclose(f);
        fclose(f2);
        if(mark==0) {system("cls");printf("\nNo Such Record Found !!");Sleep(1000);chef(1);}
        else
        {
         char ch;
         f=fopen("menu.txt","w");
         f2=fopen("temp.txt","r");
         while(fread(&food,sizeof(Food),1,f2))
         {
             fwrite(&food,sizeof(Food),1,f);
         }
         fclose(f);
         fclose(f2);
         printf("\nModified successfully !!");
        }
    }
    Sleep(1000);
    chef(1);
}
void insert()
{   menu();
    Food food;
    printf("\n\nDish:");
    //scanf("%s",food.name);
    gets(food.name);
    printf("Price:");
    scanf("%d",&food.price);
    FILE* f=fopen("menu.txt","a");
    fwrite(&food,sizeof(Food),1,f);
    fclose(f);
    printf("\nInserted successfully !!");
     Sleep(1000);
     chef(1);
}
void delet()
{
    menu();
    int n=emptycheck();
    if(n==0){ printf("\nFile Is Empty !!\n"); Sleep(1000);welcome();chef(1);}
    else if(n==1)
    {
        int mark=0;
        Food food;
        char fname[10];
        printf("\n\nEnter Name Of Dish To Be Removed:");
        //scanf("%s",fname);
        gets(fname);
        FILE* f=fopen("menu.txt","r");
        FILE* f2=fopen("temp.txt","w");
        while(fread(&food,sizeof(Food),1,f))
        {
            if(strncmp(food.name,fname,10)==0)
                mark=1;
            else
            {
                fwrite(&food,sizeof(Food),1,f2);
            }
        }
        fclose(f);
        fclose(f2);
        if(mark==0){ system("cls");printf("\n\nRecord Not Found !!\n"); Sleep(1000);chef(1);}
        else
        {
            char ch;
            f=fopen("menu.txt","w");
            f2=fopen("temp.txt","r");
            while(fread(&food,sizeof(Food),1,f2))
            {
                fwrite(&food,sizeof(Food),1,f);
            }
            fclose(f);
            fclose(f2);
            printf("\nRecord Deleted successfully !!");
            Sleep(1000);
            chef(1);
        }
    }
}
int main()
{
welcome();
return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include"conio2.h"
#include"my_math.h"
#define ENTER 13
void insert_record();
void display_record();
void search_record();
void delete_record();
void update_record();
void pswd();
typedef struct student{
   char roll[50];
   char name[50];
   int  marks;
   char sec[10];
   char grade[10];
}student;
 student s;
 struct password
    {
       char user_name[20];
       char pwd[20];
    };
 struct password p;
 int main()
{
    int ch,c;
    int i;

    FILE *Fp;
    clrscr();
    Fp=fopen("D:\\pdw.txt","ab+");
     if(Fp==NULL){
            printf("sorry! Cannot Open the File.");
            return 1;
          }
    while(c!=2){
    clrscr();
    textcolor(11);
    gotoxy(35,5);
    printf("\n********************************");
    textcolor(11);
    printf("$_LOGIN PAGE_$");
    printf("*********************************");
    gotoxy(35,10);
    printf("1.SIGN UP");
    gotoxy(35,11);
    printf("2.SIGN IN");
    gotoxy(35,15);
    printf("\n*******************************");
    textcolor(11);
    printf("$_LOGIN PAGE_$");
    printf("*********************************");
    textcolor(GREEN);
    printf("\n\n\n\t\t\t\t   SELECT: ");
    scanf("%d",&c);
    textcolor(11);

    switch(c)
    {
    case 1:
        {
            clrscr();
            gotoxy(35,5);
            textcolor(YELLOW);
            printf("#_SIGN UP PAGE_#\n");
            gotoxy(1,9);
            textcolor(11);
            for(i=0; i<80; i++)
            {
              printf("*");
            }
             gotoxy(1,16);
            for(i=0; i<80; i++)
           {
             printf("*");
           }
            i=0;
            gotoxy(35,11);
            printf("SET USER NAME: ");
            scanf("%s",p.user_name);
            gotoxy(35,12);
            printf("SET PASSWORD: ");
            fflush(stdin);
            while(1)
            {
               ch=getch();

             if(ch==13)
             {
                 break;
             }
             else if(ch==8)
             {
                 if(i>0)
                 {
                    i--;
                    printf("\b \b");
                 }
             }
             else if(ch==32)
                {
                  continue;
                }
             else
             {
                  p.pwd[i]=ch;
                  printf("%c",p.pwd[i]);
                  i++;
                  delay(1000);
                  printf("\b*");
             }
            }
            p.pwd[i]='\0';
            printf("\n%s",p.pwd);
            fwrite(&p,sizeof(struct password),1,Fp);
            fclose(Fp);
            gotoxy(30,19);
            textcolor(GREEN);

            printf("User Name And Password Saved Successfully.");
            break;
        }
    case 2:
        {
            pswd();
            break;
        }
    default:{
             gotoxy(80,20);
             printf("Wrong Choice!");
            }
      }
      textcolor(WHITE);
      gotoxy(40,20);
      printf("\n\t\tPress Any Key to Continue...");
      getch();

    }

      clrscr();
    while(ch!=7){
         clrscr();
        textcolor(YELLOW);
        printf("\t\t\t____________________________________\n\n\t\t\t****__WELCOME TO MY PROJECT__****\n\t\t\t___________________________________");
        textcolor(12);
        printf("\n\n\t\t\t##_STUDENT DATA MANAGEMENT SYSTEM_##\n\n");
        textcolor(GREEN);
        printf("\t\t\tFUNCTIONALITIES:\n");
        textcolor(WHITE);
        printf("\t\t\t1.Insert Student Record\n\t\t\t2.Display student Record\n\t\t\t3.Search student Record\n");
        printf("\t\t\t4.Delete student Record\n\t\t\t5.Update student Record\n\t\t\t6.Sort student Record\n\t\t\t7.Exit");
        textcolor(11);
        printf("\n\n\t\t\tEnter Your Choice:");
        scanf("%d",&ch);
        switch(ch){
          case 1:
                    insert_record();
                    break;

          case 2:
                    display_record();
                    break;

          case 3:
                    search_record();
                    break;

          case 4:  {
                    delete_record();
                    break;
                   }

          case 5:
                    update_record();
                    break;

          case 6:{
                    sort_record();
                    break;
                 }
          case 7:
                    exit(1);

          default:
                    printf("\n\t\tWrong choice!");
               }
               gotoxy(1,22);
               printf("\nPress Any Key to Continue...");
               getch();

        }
    return 0;
    }

void insert_record(){
          FILE *fp;
          char c;
          clrscr();
          fp=fopen("D:\\sturec.txt","ab+");
          if(fp==NULL){
            printf("sorry! Cannot Open the File.");
            return ;
          }
          textcolor(YELLOW);
          printf("\n\t\t\t\t\t***INSERT DETAILS***\n");
          printf("\t\t\t\t\t==================\n\n");
    do{
     textcolor(WHITE);
     printf("Enter the Enroll no. Of the student:");
      fflush(stdin);
     gets(s.roll);
     printf("Enter the Name of the Student:");
     fflush(stdin);
     gets(s.name);
     printf("Enter the Section of Student:");
     scanf("%s",&s.sec);
     printf("Enter the Grade of the Student:");
     scanf("%s",&s.grade);
     printf("Enter the Marks of the Student:");
     scanf("%d",&s.marks);
     printf("Do You Want to Continue:(Y/N)\n");
     fflush(stdin);
     scanf("%c",&c);
     fwrite(&s,sizeof(s),1,fp);
    }while(c=='Y');
    printf("Data Inserted and Saved Successfully.\n\n");
    fclose(fp);
    printf("Updated Record\n");
    display_record();
    fclose(fp);

  }
void display_record(){
    FILE *fp;
    int s_no=1,row;
    clrscr();
    fp=fopen("D:\\sturec.txt","rb");
    if(fp==NULL){
        printf("Sorry, Cannot Open File!");
        return 1;
    }
    textcolor(14);
    gotoxy(1,2);
    printf("Student Details Are as Follows:\n\n");
    textcolor(11);
    gotoxy(1,4);
    printf("S.No.");
    gotoxy(8,4);
    printf("ENROLL NO.");
    gotoxy(26,4);
    printf("NAME");
    gotoxy(50,4);
    printf("SECTION");
    gotoxy(62,4);
    printf("GRADE");
    gotoxy(73,4);
    printf("MARKS");
    row=5;
    textcolor(WHITE);
    while(fread(&s,sizeof(s),1,fp)==1)
      {
        gotoxy(1,row);
        printf("%d",s_no);
        gotoxy(8,row);
        printf("%s",s.roll);
        gotoxy(26,row);
        printf("%s",s.name);
        gotoxy(50,row);
        printf("%s",s.sec);
        gotoxy(62,row);
        printf("%s",s.grade);
        gotoxy(73,row);
        printf("%d",s.marks);
        row++;
        s_no++;
      }
      fclose(fp);

}

void search_record()
    {
    char temp[60],r[50];
    int c=0;
    FILE *fp;
    int i=0,row;
    clrscr();
    fp=fopen("D:\\sturec.txt","rb");
   if(fp==NULL)
    {
    printf("Sorry! Cannot open the file");
    return 1;
    }
   textcolor(11);
   printf("PRESS 1: To SEARCH ACCORDING TO NAME\nPRESS 2: TO SEARCH ACCORDING TO ROLL NO.\n");
   scanf("%d",&c);
   textcolor(WHITE);
   if(c==1){
             clrscr();
             printf("\nEnter the Name of the student,whose rec you want to display: ");
             fflush(stdin);
             gets(temp);
             textcolor(14);
             gotoxy(1,4);
             printf("Student Details Are as Follows:\n\n");
             textcolor(11);
             gotoxy(1,6);
             printf("ENROLL NO.");
             gotoxy(20,6);
             printf("NAME");
             gotoxy(45,6);
             printf("SECTION");
             gotoxy(58,6);
             printf("GRADE");
             gotoxy(69,6);
             printf("MARKS");
             row=7;
             textcolor(WHITE);



             while(fread(&s,sizeof(struct student),1,fp)==1)
              {
                 if(strcmp(temp,s.name)==0)
                 {
                    gotoxy(1,row);
                    printf("%s",s.roll);
                    gotoxy(20,row);
                    printf("%s",s.name);
                    gotoxy(45,row);
                    printf("%s",s.sec);
                    gotoxy(58,row);
                    printf("%s",s.grade);
                    gotoxy(69,row);
                    printf("%d",s.marks);
                    row++;

                   i=1;
                 }
              }
           }

    else if(c==2){
                      clrscr();
                      printf("\nEnter the Roll no. of the Student Whose Record You want to Display: ");
                      scanf("%s",r);
                      clrscr();
                      textcolor(14);
                      gotoxy(1,4);
                      printf("Student Details Are as Follows:\n\n");
                      textcolor(11);
                      gotoxy(1,6);
                      printf("ENROLL NO.");
                      gotoxy(20,6);
                      printf("NAME");
                      gotoxy(45,6);
                      printf("SECTION");
                      gotoxy(58,6);
                      printf("GRADE");
                      gotoxy(69,6);
                      printf("MARKS");
                      row=7;
                      textcolor(WHITE);
                     while(fread(&s,sizeof(s),1,fp)==1)
                      {
                        if(strcmp(r,s.roll)==0)
                          {
                              gotoxy(1,row);
                              printf("%s",s.roll);
                              gotoxy(20,row);
                              printf("%s",s.name);
                              gotoxy(45,row);
                              printf("%s",s.sec);
                              gotoxy(58,row);
                              printf("%s",s.grade);
                              gotoxy(69,row);
                              printf("%d",s.marks);
                              row++;
                              i=1;
                          }
                      }
                 }
  if(i==0)
  printf("\nRecord not found!");
  fclose(fp);
}
void delete_record(){
    FILE *fp;
    FILE *fp1;
    char str[60];
    unsigned flag=0;
    clrscr();
    fp=fopen("D:\\sturec.txt","rb");
    if(fp==NULL)
    {
    printf("Sorry! Cannot open the file");
    return 1;
    }
    textcolor(RED);
    printf("\n\t\t\t***_PREVIOUS STORED DATA_***\t\t\t\n");
    textcolor(WHITE);
    printf("\n\t\t\t#_Student Details Are as follows_#\n\n");
    textcolor(11);
    display_record();
    printf("\n\nEnter the Name of the Student which You Want to Delete:");
    fflush(stdin);
    gets(str);
    fp1=fopen("D:\\sturec1.txt","ab+");
    while(fread(&s,sizeof(s),1,fp)==1)
    {
        if(strcmp(str,s.name)!=0)
         fwrite(&s,sizeof(s),1,fp1);
        else
         flag=1;
    }
    fclose(fp);
    fclose(fp1);
    remove("D:\\sturec.txt");
    rename("D:\\sturec1.txt","D:\\sturec.txt");
    if(flag==0)
     printf("\n\t\tNO,Such Record Found");
    else{
          textcolor(GREEN);
          printf("\n\t\tRecord Deleted Successfully.");
          textcolor(WHITE);
          printf("\n\nUPDATED RECORD:");
          delay(3000);
          display_record();
        }


}
void update_record()
{
  int flag=0,row,i;
  char r[20];
  FILE *fp;
  clrscr();
  fp=fopen("D:\\sturec.txt","rb+");
  if(fp==NULL)
    {
    printf("Sorry! Cannot open the file");
    return 1;
    }
    textcolor(WHITE);
    printf("\nEnter Enroll Number of Student Whose Record You Want to Update: ");
    scanf("%s",&r);
    textcolor(11);
    printf("\n\t\t***PREVIOUSLY STORED RECORD OF GIVEN ROLL NUMBER***\n\n");
    while(fread(&s,sizeof(s),1,fp)==1)
    {
        if(strcmp(r,s.roll)==0)
       {
             flag=1;
             textcolor(14);
             gotoxy(1,6);
             printf("Student Details Are as Follows:\n\n");
             textcolor(11);
             gotoxy(1,8);
             printf("ENROLL NO.");
             gotoxy(20,8);
             printf("NAME");
             gotoxy(45,8);
             printf("SECTION");
             gotoxy(58,8);
             printf("GRADE");
             gotoxy(69,8);
             printf("MARKS");
             row=9;
             textcolor(WHITE);

                        if(strcmp(r,s.roll)==0)
                          {
                              gotoxy(1,row);
                              printf("%s",s.roll);
                              gotoxy(20,row);
                              printf("%s",s.name);
                              gotoxy(45,row);
                              printf("%s",s.sec);
                              gotoxy(58,row);
                              printf("%s",s.grade);
                              gotoxy(69,row);
                              printf("%d",s.marks);
                              i=1;
                          }
             textcolor(YELLOW);
             printf("\n\n\n\n\t\t***NOW ENTER THE NEW RECORD***\n\n");
             textcolor(WHITE);
             printf("Enter the Enroll no. Of the Updated student:");
             fflush(stdin);
             scanf("%s",&s.roll);
             printf("Enter the Name of the Updated Student:");
             fflush(stdin);
             gets(s.name);
             printf("Enter the Section of Updated Student:");
             scanf("%s",&s.sec);
             printf("Enter the Grade of the Updated Student:");
             scanf("%s",&s.grade);
             printf("Enter the Marks of the Updated Student:");
             scanf("%d",&s.marks);
             fseek(fp,-(long)sizeof(s),1);
             fwrite(&s,sizeof(s),1,fp);
             textcolor(GREEN);
             printf("\n\t\tRecord Updated Successfully.");
       }
    }
    if(flag==0)
        printf("\n\t\tError:Something Went Wrong.");

    fclose(fp);
}
void pswd()
{

    FILE *Fp;
    char un[20];
    char ps[20];

     int i=0;
    char ch;
    clrscr();
          Fp=fopen("D:\\pdw.txt","rb");
          if(Fp==NULL){
            printf("sorry! Cannot Open the File.");
            return 1;
          }
          gotoxy(1,4);
          textcolor(11);
          printf("####################################");
          textcolor(14);
          printf("_SIGN IN_");
          textcolor(11);
          printf("##################################");
           gotoxy(1,10);
          textcolor(11);
          printf("####################################");
          textcolor(14);
          printf("_SIGN IN_");
          textcolor(11);
          printf("##################################");
          gotoxy(28,6);
          printf("Enter the User Name: ");
          textcolor(WHITE);
          fflush(stdin);
          scanf("%s",&un);
          gotoxy(28,7);
          textcolor(11);
          printf("Enter the PassWord: ");
          textcolor(WHITE);

   while(1)
          {
             ch=getch();
             if(ch==ENTER)
             {
                 ps[i]='\0';
                 break;
             }
             else if(ch==8)
             {
                 if(i>0)
                 {
                    i--;
                    printf("\b \b");
                 }
             }
             else if(ch==32||ch==9)
                {
                  continue;
                }
             else
             {
                 ps[i]=ch;
                 printf("%c",ps[i]);
                  i++;
                 delay(1000);
                 printf("\b*");

             }
          }
          textcolor(GREEN);
          gotoxy(30,13);
          printf("Verifying the Password..PLease Wait");
          delay(3000);
          fread(&p,sizeof(struct password),1,Fp);
          if(strcmp(un,p.user_name)==0&&strcmp(ps,p.pwd)==0)
          {
               textcolor(7);
               gotoxy(40,15);
               printf("Password Verified!");
               textcolor(14);
          }
          else
          {

               gotoxy(28,16);
               textcolor(RED);
               printf("Wrong User name OR Password...Please Try Again!");
               delay(3000);
               main();
          }
    fclose(Fp);
}

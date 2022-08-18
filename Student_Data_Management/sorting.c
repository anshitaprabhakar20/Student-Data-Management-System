#include<stdio.h>
#include<string.h>
#include"my_math.h"
#include"conio2.h"
typedef struct student{
   char roll[50];
   char name[50];
   int marks;
   char sec[10];
   char grade[10];

}student;
student s;
void sort_record(){
 FILE *fp;
 student s;
 student arr[50];
 int row;
 int i,j,k=0;
 clrscr();
 fp=fopen("D:\\sturec.txt","rb");
 if(fp==NULL){
             printf("sorry! Cannot Open the File.");
             return 1;
             }
 i=0;
 while(fread(&arr[i],sizeof(struct student),1,fp))
 {
     i++;
     k++;
 }
 for(i=0;i<k;i++){
    for(j=i+1; j<k;j++){
          textcolor(YELLOW);
        if(strcmp((arr[i].roll),(arr[j].roll))==1)
        {
            s=arr[i];
            arr[i]=arr[j];
            arr[j]=s;

        }
    }
 }


             textcolor(14);
             gotoxy(1,3);
             printf("Student Details Are as Follows:\n");
             printf("===============================");
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

            for(i=0;i<k;i++){
                    gotoxy(1,row);
                    printf("%s",arr[i].roll);
                    gotoxy(20,row);
                    printf("%s",arr[i].name);
                    gotoxy(45,row);
                    printf("%s",arr[i].sec);
                    gotoxy(58,row);
                    printf("%s",arr[i].grade);
                    gotoxy(69,row);
                    printf("%d",arr[i].marks);
                    row++;
            }

fclose(fp);
}

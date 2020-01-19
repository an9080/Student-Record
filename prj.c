#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//Shahad fahad 437200437 , Anoud abdullah 437201069
void add();
void viewAll();
void search();
void edit();
void deleteR();
int c=0;

struct Record{
char name[20];
char email[20];
char phoneNum[20];
};

int main(){ 

time_t rawtime ;
int i=0;
printf("Enter password \n");
scanf("%d",&i);

while (i!=1234){
printf("Re-enter password \n ");
scanf("%d",&i);}

time(&rawtime);// date and time 
printf(" The Day and Time is : %s\n",ctime(&rawtime));
int p=0;

do{
printf("Enter Menu : \n 1-Add information of Record \n 2-View all Record \n 3-Search \n 4- Edit \n 5- Delete specific Record \n 6- Exit \n  ");
scanf("%d",&p);
if(!((p>0)&&(p<6))){
while(((p>0)&&(p<6))){
printf("Enter Menu : \n 1-Add information of Record \n 2-View all Record \n 3-Search \n 4- Edit \n 5- Delete specific Record \n 6-Exit \n  ");
scanf("%d",&p);
}}
switch (p) {
case 1 :add(); break;
case 2 :viewAll(); break ;
case 3 :search() ; break;
case 4 :edit() ; break ;
case 5 :deleteR(); break ;
}
}
while(p!=6);
}

void add(){//****************************** it good 
int num ;
struct Record R;
FILE*f;
f=fopen("records.txt","a+");
//printf("Enter the number :");
//scanf("%d",&num);
int k=1;
while(k!=0){
printf("Enter a name:");
scanf("%s",R.name);
printf("Enter a Email:");
scanf("%s",R.email);
printf("Enter a phoneNum:");
scanf("%s",R.phoneNum);
fwrite(&R,sizeof(struct Record),1,f);
if(fwrite != 0) { 
printf("A Record Added Successfully \n");}
printf("enter 1 to contunu and 0 if you want to stop  \n");
scanf("%d",&k);
c++;
}
fclose(f);
}


void viewAll(){//************ it's good 
struct Record r;
FILE *fpo;
fpo=fopen("records.txt","r");
if(fpo==NULL){
fprintf(stderr, "\n Error opend file\n"); 
exit (1);}
int i=0;
while(fread(&r, sizeof(struct Record), 1, fpo)==1){
printf("%s\t%s\t%s\t\n",r.name,r.email,r.phoneNum); } 
fclose (fpo);
}

void search(){//********* IT'S OKEY  
struct Record r;
FILE *fpo;
int k=1;
fpo=fopen("records.txt","r");
if(fpo==NULL){
fprintf(stderr,"\nError opend file\n"); 
exit (1);}
int count=0;
char sname[20]="";
printf("please enter the name "); 
scanf("%s",sname);
while(fread(&r, sizeof(struct Record), 1, fpo)==1){
if (strcmp(r.name,sname)==0){
printf("found it!\n");
printf("%s\t%s\t%s\t\n",r.name,r.email,r.phoneNum);
count++; 
} 
 fflush(fpo);  
}
if(count==0) {
printf("the matching not found");
printf("enter 1 to contunu and 0 if you want to stop  \n");
scanf("%d",&k);
if(k!=0) 
return search();
}
else{
printf("the number of matching record: %d \n",count);
printf("enter 1 to contunu and 0 if you want to stop  \n");
scanf("%d",&k);
if(k!=0) return search();
}

fclose(fpo); 
}


void edit(){//********************* good 
char sname [20];
   struct   Record r ;
   int c=0;
   FILE * op=fopen("records.txt","r+");
   FILE * fpo=fopen("new.txt","w+");
   if(op==NULL)
      {fprintf(stderr, "\nError opend file\n"); 
      exit(1);}
   if(fpo==NULL)
      {fprintf(stderr, "\nError opend file\n"); 
      exit(1);}
   printf("Enter The Name You Want To Edit: ");
   scanf("%s",sname);
   while(fread(&r,sizeof(struct Record),1,op)!=0)
      {if((strcmp(r.name,sname)==0 )&&c==0)
         {printf("Enter Your NEW Name: ");
         scanf("%s",r.name);
         printf("Enter Your NEW Email: ");
         scanf("%s",r.email);
         printf("Enter Your NEW Phone Number: ");
         scanf("%s",r.phoneNum);
         fwrite(&r, sizeof(struct Record),1,fpo); 
         c++;}
      else
         fwrite(&r, sizeof(struct Record),1,fpo);}
   if(c==0)
      printf("Does not exist\n");
   fclose(fpo);
   fclose(op);
   remove("records.txt");
   rename("new.txt","records.txt");
   if(&rename!=0&&c!=0)
      printf("Record Updated Successfully \n  ");
}



void deleteR(){//*******************  good 
FILE * op=fopen("records.txt","r+");
   FILE * fpo=fopen("newrecords.txt","w+");
   struct   Record R ;
   int c=0;
   char delename [20];
   
   
   if(op==NULL)
         {fprintf(stderr, "\nError opend file\n"); 
         exit(1);}
         
   if(fpo==NULL)
      {fprintf(stderr, "\nError opend file\n"); 
      exit(1);}
      
   printf("Enter the name you want to Delete : ");
   scanf("%s",delename);
   while(fread(&R,sizeof(struct Record),1,op)!=0)
      {if((strcmp(R.name,delename)==0 ))
         {c++; }
      else{
       fflush(fpo);  
         fwrite(&R, sizeof(struct Record),1,fpo);}}
   if(c==0)
   printf("Does not exist \n ");
   fclose(fpo);
   fclose(op);
   remove("records.txt");
   rename("newrecords.txt","records.txt");
   if(&rename !=0&&c!=0)
      printf("Record Deleted Successfully! \n");
}

//good job !! 

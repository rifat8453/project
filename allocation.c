#include<stdio.h>

typedef struct hostel{
    int rno;
    char name[30];
    char location [30];
    char gender[6];
    int room_no;
}hostel;
int lower=1, upper=20;
void create(){

    hostel h;
    FILE*fp=fopen("hostel.txt","a+");
    system("COLOR 3F");
    printf("\n\n\n\n\t\tENTER ROLL NUMBER:");
    scanf("%d",&h.rno);
    printf("\t\t ENTER NAME:");
    scanf("%s",h.name);
    printf("\t\tENTER LOCATION:");
    scanf("%s",h.location);
    printf("\t\tENTER GENDER:");
    scanf("%s",h.gender);
    h.room_no=getroomno((rand()%(upper-lower+1))+lower);
    if(h.room_no!=0)
    fwrite(&h,sizeof(hostel),1,fp);
    fclose(fp);
    printf("\n\n\n\n registration complete successfully and enter 2 for display \n\n\n\n");
    sleep(3);
    system("CLS");
}

int getroomno(int roomno){
    int allocated=0;
    FILE*fp=fopen("hostel.txt","r");
    hostel h1;
    while(fread(&h1,sizeof(hostel),1,fp)){
    if(h1.room_no==roomno){
    allocated=1;
    }
   }
   if(allocated==0)
    return roomno;
   else
    return getroomno(((rand()%(upper-lower+1))+lower));
   fclose(fp);

}
void display(){
    hostel h1;
    FILE*fp=fopen("hostel.txt","r");
    printf("\n----------------------------------------------------------------------------\n");
    printf("%-10s%-20s%-15s%-10s%-5s\n","ROLLNO","Name","Location","Gender","Room_No");
    printf("\n----------------------------------------------------------------------------\n");
    while(fread(&h1,sizeof(hostel),1,fp))
        printf("%-10d%-20s%-15s%-10s%-5d\n",h1.rno,h1.name,h1.location,h1.gender,h1.room_no);

  printf("\n\n\n Enter 1 for new registration and 0 to exit..\n\n");
}


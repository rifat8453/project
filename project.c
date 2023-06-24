 #include<stdio.h>
 #include"splash screen.c"
 #include"login and regestre.c"
 #include"allocation.c"

int main(void)

{
    system("COLOR 3F");
     // Call the function to display the splash screen
    showSplashScreen();


     int choice;
   printf("\n\n\t\t\t\t Welcome to registration and login system");
   printf("\n\n\n\n\nPress 1 for register \nPress 2 for login\n");
   scanf("%d",&choice);
   if(choice==1)
   {
       system("CLS");
       registe();
   }
   else if(choice==2)
   {
       system("CLS");
       login();
   }
   else
   {
    printf("Invalid choice");


    }
    int ch ;
    printf("\n\n\n\n\n welcome to room allocation service\n\n\n");
    do{
        printf("\n1.ALLOCATE NEW ROOM\n");
        printf("\n2.DISPLAY\n");
        printf("\n0.EXIT \n");
        printf("\nEnter you choice\n:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                system("CLS");
                create();
                break;
            case 2:
                                system("CLS");
                display();
                 break;
            case 0:printf("\n THANKS....\n");
        }
    }while(ch!=0);
    return 0;
}

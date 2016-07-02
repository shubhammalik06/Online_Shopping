
//AT ANY TIME IN THE PROGRAM ITME MENU PRESS 's' ON YOUR KEYBOARD TO GO BACK TO MAIN MENU

//Header Files

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<windows.h>
#include<time.h>

//Global variables

char ch;
int choice_E;
float total_Rs;

//************Functions For Conio.h**************

//gotoxy()
COORD coord= {0,0};
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

//Delay()
void delay(unsigned int a)
{
clock_t x = a+clock();
while(x > clock() );
}

//Rectangle
void window(int a,int b,int c,int d)
{
    int i;
    system("cls");
    gotoxy(20,2);

    for (i=1; i<=10; i++)
        printf("*");
    printf(" * SHOPSTOP.COM * ");
    for (i=1; i<=10; i++)
        printf("*");
    printf("\n\n");
    gotoxy(30,4);
    printf("Online Mega Store");

    for (i=a; i<=b; i++)
    {
        gotoxy(i,17);
        printf("\xcd");
        gotoxy(i,19);
        printf("\xcd");
        gotoxy(i,c);
        printf("\xcd");
        gotoxy(i,d);
        printf("\xcd");
    }

    gotoxy(a,17);
    printf("\xc9");
    gotoxy(a,18);
    printf("\xba");
    gotoxy(a,19);
    printf("\xc8");
    gotoxy(b,17);
    printf("\xbb");
    gotoxy(b,18);
    printf("\xba");
    gotoxy(b,19);
    printf("\xbc");

    for(i=c; i<=d; i++)
    {
        gotoxy(a,i);
        printf("\xba");
        gotoxy(b,i);
        printf("\xba");
    }
    gotoxy(a,c);
    printf("\xc9");
    gotoxy(a,d);
    printf("\xc8");
    gotoxy(b,c);
    printf("\xbb");
    gotoxy(b,d);
    printf("\xbc");

}


//************STRUCTURES********************

//Products
struct list
{
    int id;
    char item[20];
    float price;
};

//Customer
struct customer
{
    char c_name[30];
    char c_email[30];
    long double c_num;
};
struct customer cust;


//Item initialization in the structure List
struct list item[] =
{
//Mobile Phones
{1,"Asus Zenfone 5",9999.00,15},
{2,"Iphone 5S",55000.00,20},
{3,"Microsoft Lumia 635",12000.00,20},
{4,"Sony Xperia M",11200.00,20},
//Laptops
{5,"Lenovo Flex 2", 30000},
{6,"Dell Vostro 14", 31000},
{7,"Msi Titan", 210000},
{8,"HP 15r036TX", 35000},
//tv
{9,"VU 32K160", 16990},
{10,"LG 32LB", 28000},
{11,"Samsung UA40", 48000},
{12,"Samsung 55H6400", 110000},
//Computer Components{13,"BenQ 21' Monitor", 8000},
{14,"Intel Core i7 Processor", 35000},
{15,"MSI AMD R9 280x", 21000},
{16,"RAZER Hydra Water Cooler", 18000},
//Fiction Books
{17,"3 Mistakes of My Life", 140},
{18,"The Wise man's fear", 1240},
{19,"The Fourth Estate", 500},
{20,"And the mountains echoed", 450},
//Non Fiction books
{21,"Way of seeing", 300},
{22,"The story of art", 450},
{23,"Eminent victorians", 500},
{24,"The diaries of samuel pepys", 150},
//Health
{25,"Perfect Body and Nutrition", 350},
{26,"Fast exercise: Health and fitness", 200},
{27,"The Blue Zones Solution", 240},
{28,"The Whole30", 458},
//Academics
{29,"Let US C", 250},
{30,"Java For Dummies", 780},
{31,"Ethical Hacking", 2340},
{32,"Autodesk 3DS Max Official Guide", 3450},
//Mens Clothing
{33,"Levis Jeans", 2560},
{34,"FLU Jeans", 1590},
{35,"FOG Jeans", 700},
{36,"DENIM Jeans", 500},
//Female Clothing
{37,"French collection printed t-shirt", 560},
{38,"ICENSE ANARKALI CUT RED SUIT", 1590},
{39,"MAHARANI ZEVARI DESIGNER SALWAR SUIT", 2560},
{40,"INCENSE PRINTED KURTI SET", 1500},
//PC Games
{41,"GTA 5", 2400},
{42,"Mortal Kombat X", 999},
{43,"Strarship Citizen", 2900},
{44,"The Witcher 3", 1499},
//Console Games
{45,"Final Fantasy", 3500},
{46,"Xenoblade Chronicals X", 4500},
{47,"Bloodborne", 3200},
{48,"Persona 5", 2800},
//Paintings
{49,"Monalisa", 150000},
{50,"The Last Supper", 125000},
{51,"Generic Art", 50000},
{52,"Berlin art masterpiece", 200000}
};

int main()
{
    main_load();
    login();
    delay(1000);
    c_print();
    main_menu();
    return 0;
}

//Functions For the Interface
void main_menu()
{
    system("cls");
    window(25,50,20,32);
    gotoxy(33,18);
    printf("MAIN MENU");
    gotoxy(29,22);
    printf("1)View Total Amount");
    gotoxy(29,23);
    printf("2)Electronics");
    gotoxy(29,24);
    printf("3)Books");
    gotoxy(29,25);
    printf("4)Fashion");
    gotoxy(29,26);
    printf("5)Games And Paintings");
    gotoxy(29,27);
    printf("6)Contact Us");
    gotoxy(29,28);
    printf("7)Exit");
    gotoxy(29,29);
    printf("Enter Choice:");
    fflush(stdin);
    scanf("%c", &ch);
    switch(ch)
    {
        case '1'  :total();
                   break;
        case '2'  :interface_electronics();
                   break;
        case '3'  :interface_books();
                   break;
        case '4'  :interface_cloth();
                   break;
        case '5'  :interface_games();
                   break;
        case '6'  :contact();
                   break;
        case '7'  :end_program();
                   break;
    }
}

void interface_electronics()
{
    system("cls");
    fflush(stdin);
    window(3,77,20,40);

    gotoxy(35,18);
    printf("ELECTRONICS");

    gotoxy(10,22);
    printf("Mobile Phones");
    gotoxy(6,24);
    printf("0)Asus Zenfone 5      - RS 9999");
    gotoxy(6,25);
    printf("1)Iphone 5S           - Rs 55000");
    gotoxy(6,26);
    printf("2)Microsoft Lumia 635 - Rs 12000");
    gotoxy(6,27);
    printf("3)Sony Xperia M       - Rs11200");

    gotoxy(50,22);
    printf("Laptops");
    gotoxy(45,24);
    printf("4)Lenovo Flex 2    - RS 30000");
    gotoxy(45,25);
    printf("5)Dell Vostro      - Rs 31000");
    gotoxy(45,26);
    printf("6)Msi Titan        - Rs 210000");
    gotoxy(45,27);
    printf("7)HP 15r036TX      - Rs 35000");

    gotoxy(10,30);
    printf("Television");
    gotoxy(6,32);
    printf("8)VU 32K160         - RS 16990");
    gotoxy(6,33);
    printf("9)LG 32LB          - Rs 28000");
    gotoxy(6,34);
    printf("10)Samsung UA40     - Rs 48000");
    gotoxy(6,35);
    printf("11)Samsung 55H6400  - Rs 110000");

    gotoxy(50,30);
    printf("Computer Parts");
    gotoxy(45,32);
    printf("12)BenQ 21' Monitor   - RS 8000");
    gotoxy(45,33);
    printf("13)Intel i7 Processor - Rs 35000");
    gotoxy(45,34);
    printf("14)MSI R9 280x        - Rs 21000");
    gotoxy(45,35);
    printf("15)Razer Hydra        - Rs 18000");
    gotoxy(6,37);
    printf("Enter item seriel number to buy:");
    scanf("%d", &choice_E);

    switch(choice_E)
    {
    case 0  :  total_Rs=total_Rs+item[choice_E].price ;
               printf("\tAdded to cart");
               main_menu();
               break;
    case 1  :  total_Rs=total_Rs+item[choice_E].price ;
               printf("\tAdded to cart");
               main_menu();

               break;
    case 2  :  total_Rs=total_Rs+item[choice_E].price ;
               printf("\tAdded to cart");
               main_menu();
               break;
    case 3  :  total_Rs=total_Rs+item[choice_E].price ;
               printf("\tAdded to cart");
               main_menu();
               break;
    case 4  :  total_Rs=total_Rs+item[choice_E].price ;
               printf("\tAdded to cart");
               main_menu();
               break;
    case 5  :  total_Rs=total_Rs+item[choice_E].price ;
               printf("\tAdded to cart");
               main_menu();
               break;
    case 6  :  total_Rs=total_Rs+item[choice_E].price ;
               printf("\tAdded to cart");
               main_menu();
               break;
    case 7  :  total_Rs=total_Rs+item[choice_E].price ;
               printf("\tAdded to cart");
               main_menu();
               break;
    case 8  :  total_Rs=total_Rs+item[choice_E].price ;
               printf("\tAdded to cart");
               main_menu();
               break;
    case 9 :   total_Rs=total_Rs+item[choice_E].price ;
               printf("\tAdded to cart");
               main_menu();
               break;
    case 10 :  total_Rs=total_Rs+item[choice_E].price ;
               printf("\tAdded to cart");
               main_menu();
               break;
    case 11 :  total_Rs=total_Rs+item[choice_E].price ;
               printf("\tAdded to cart");
               main_menu();
               break;
    case 12 :  total_Rs=total_Rs+item[choice_E].price ;
               printf("\tAdded to cart");
               main_menu();
               break;
    case 13 :  total_Rs=total_Rs+item[choice_E].price ;
               printf("\tAdded to cart");
               main_menu();
               break;
    case 14 :  total_Rs=total_Rs+item[choice_E].price ;
               printf("\tAdded to cart");
               main_menu();
               break;
    case 15 :  total_Rs=total_Rs+item[choice_E].price ;
               printf("\tAdded to cart");
               main_menu();
               break;
    default :  main_menu();
               break;
    }

    gotoxy(5,50);

}

void interface_books()
{
    system("cls");
    fflush(stdin);
    window(3,77,20,40);

    gotoxy(35,18);
    printf("BOOKS");

    gotoxy(10,22);
    printf("Fiction");
    gotoxy(6,24);
    printf("16)3 Mistakes of My Life    - RS 450");
    gotoxy(6,25);
    printf("17)The Wise man's fear      - Rs 1240");
    gotoxy(6,26);
    printf("18)The Fourth Estate        - Rs 500");
    gotoxy(6,27);
    printf("19)And the mountains echoed - Rs 450");

    gotoxy(50,22);
    printf("Non Fiction");
    gotoxy(45,24);
    printf("20)Way of seeing         - RS 300");
    gotoxy(45,25);
    printf("21)The story of art      - Rs 450");
    gotoxy(45,26);
    printf("22)Eminent victorians    - Rs 500");
    gotoxy(45,27);
    printf("23)The diaries of Samuel - Rs 150");

    gotoxy(10,30);
    printf("Health");
    gotoxy(6,32);
    printf("24)Perfect Body    - RS 350");
    gotoxy(6,33);
    printf("25)Fast exercise  - Rs 200");
    gotoxy(6,34);
    printf("26)The Blue Zones - Rs 240");
    gotoxy(6,35);
    printf("27)The Whole30    - Rs 458");

    gotoxy(50,30);
    printf("Academics");
    gotoxy(45,32);
    printf("28)Let US C         - RS 250");
    gotoxy(45,33);
    printf("29)Java For Dummies - Rs 780");
    gotoxy(45,34);
    printf("30)Ethical Hacking  - Rs 2340");
    gotoxy(45,35);
    printf("31)3DS Max Guide    - Rs 3450");

    gotoxy(6,37);
    printf("Enter item seriel number to buy:");
    scanf("%d", &choice_E);

    switch(choice_E)
    {
    case 16  : total_Rs=total_Rs+item[choice_E].price ;
               printf("\tAdded to cart");
               main_menu();
               break;
    case 17  : total_Rs=total_Rs+item[choice_E].price ;
               printf("\tAdded to cart");
               main_menu();
               break;
    case 18  : total_Rs=total_Rs+item[choice_E].price ;
               printf("\tAdded to cart");
               main_menu();
               break;
    case 19  : total_Rs=total_Rs+item[choice_E].price ;
               printf("\tAdded to cart");
               main_menu();
               break;
    case 20  : total_Rs=total_Rs+item[choice_E].price ;
               printf("\tAdded to cart");
               main_menu();
               break;
    case 21  : total_Rs=total_Rs+item[choice_E].price ;
               printf("\tAdded to cart");
               main_menu();
               break;
    case 22  : total_Rs=total_Rs+item[choice_E].price ;
               printf("\tAdded to cart");
               main_menu();
               break;
    case 23  : total_Rs=total_Rs+item[choice_E].price ;
               printf("\tAdded to cart");
               main_menu();
               break;
    case 24  : total_Rs=total_Rs+item[choice_E].price ;
               printf("\tAdded to cart");
               main_menu();
               break;
    case 25  : total_Rs=total_Rs+item[choice_E].price ;
               printf("\tAdded to cart");
               main_menu();
               break;
    case 26  : total_Rs=total_Rs+item[choice_E].price ;
               printf("\tAdded to cart");
               main_menu();
               break;
    case 27  : total_Rs=total_Rs+item[choice_E].price ;
               printf("\tAdded to cart");
               main_menu();
               break;
    case 28  : total_Rs=total_Rs+item[choice_E].price ;
               printf("\tAdded to cart");
               main_menu();
               break;
    case 29  : total_Rs=total_Rs+item[choice_E].price ;
               printf("\tAdded to cart");
               main_menu();
               break;
    case 30  : total_Rs=total_Rs+item[choice_E].price ;
               printf("\tAdded to cart");
               main_menu();
               break;
    case 31  : total_Rs=total_Rs+item[choice_E].price ;
               printf("\tAdded to cart");
               main_menu();
               break;
    default  : main_menu();
               break;
    }

    gotoxy(5,50);

}

void interface_cloth()
{
    system("cls");
    fflush(stdin);
    window(3,77,20,40);

    gotoxy(35,18);
    printf("FASHION");

    gotoxy(10,22);
    printf("MALES");
    gotoxy(6,24);
    printf("32)Levis Jeans - RS 2560");
    gotoxy(6,25);
    printf("33)FLU Jeans   - Rs 1590");
    gotoxy(6,26);
    printf("34)FOG Jeans   - Rs 700");
    gotoxy(6,27);
    printf("35)DENIM Jeans - Rs 500");

    gotoxy(10,30);
    printf("FEMALES");
    gotoxy(6,32);
    printf("36)French collection printed t-shirt - RS 560");
    gotoxy(6,33);
    printf("37)ICENSE ANARKALI CUT RED SUIT      - Rs 1590");
    gotoxy(6,34);
    printf("38)MAHARANI ZEVARI DESIGNER SALWAR   - Rs 2560");
    gotoxy(6,35);
    printf("39)INCENSE PRINTED KURTI SET         - Rs 1500");

    gotoxy(6,37);
    printf("Enter item seriel number to buy:");
    scanf("%d", &choice_E);

    switch(choice_E)
    {
    case 32  : total_Rs=total_Rs+item[choice_E].price ;
               printf("\tAdded to cart");
               main_menu();
               break;
    case 33  : total_Rs=total_Rs+item[choice_E].price ;
               printf("\tAdded to cart");
               main_menu();
               break;
    case 34  : total_Rs=total_Rs+item[choice_E].price ;
               printf("\tAdded to cart");
               main_menu();
               break;
    case 35  : total_Rs=total_Rs+item[choice_E].price ;
               printf("\tAdded to cart");
               main_menu();
               break;
    case 36  : total_Rs=total_Rs+item[choice_E].price ;
               printf("\tAdded to cart");
               main_menu();
               break;
    case 37  : total_Rs=total_Rs+item[choice_E].price ;
               printf("\tAdded to cart");
               main_menu();
               break;
    case 38  : total_Rs=total_Rs+item[choice_E].price ;
               printf("\tAdded to cart");
               main_menu();
               break;
    case 39  : total_Rs=total_Rs+item[choice_E].price ;
               printf("\tAdded to cart");
               main_menu();
               break;
    default  : main_menu();
               break;
    }

    gotoxy(5,50);
}

void interface_games()
{
    system("cls");
    fflush(stdin);
    window(3,77,20,40);

    gotoxy(35,18);
    printf("GAMES And PAINTINGS");

    gotoxy(10,22);
    printf("PC Games");
    gotoxy(6,24);
    printf("40)GTA 5            - RS 2400");
    gotoxy(6,25);
    printf("41)Mortal Kombat X  - Rs 999");
    gotoxy(6,26);
    printf("42)Starship Citizen - Rs 2900");
    gotoxy(6,27);
    printf("43)The Witcher 3    - Rs 1499");

    gotoxy(50,22);
    printf("Console Games");
    gotoxy(44,24);
    printf("44)Final Fantasy 15 - RS 3500");
    gotoxy(44,25);
    printf("45)Xenoblade X      - Rs 4500");
    gotoxy(44,26);
    printf("46)Bloodborne       - Rs 3200");
    gotoxy(44,27);
    printf("47)Persona 5        - Rs 2800");

    gotoxy(10,30);
    printf("PAINTINGS");
    gotoxy(6,32);
    printf("48)Monalisa        - Rs 150000");
    gotoxy(6,33);
    printf("49)The Last Supper - Rs 125000");
    gotoxy(6,34);
    printf("50)Generic Art     - Rs 50000");
    gotoxy(6,35);
    printf("51)Berlin art      - Rs 200000");


    gotoxy(6,37);
    printf("Enter item seriel number to buy:");
    scanf("%d", &choice_E);

    switch(choice_E)
    {
    case 40  : total_Rs=total_Rs+item[choice_E].price ;
               printf("\tAdded to cart");
               main_menu();
               break;
    case 41  : total_Rs=total_Rs+item[choice_E].price ;
               printf("\tAdded to cart");
               main_menu();
               break;
    case 42  : total_Rs=total_Rs+item[choice_E].price ;
               printf("\tAdded to cart");
               main_menu();
               break;
    case 43  : total_Rs=total_Rs+item[choice_E].price ;
               printf("\tAdded to cart");
               main_menu();
               break;
    case 44  : total_Rs=total_Rs+item[choice_E].price ;
               printf("\tAdded to cart");
               main_menu();
               break;
    case 45  : total_Rs=total_Rs+item[choice_E].price ;
               printf("\tAdded to cart");
               main_menu();
               break;
    case 46  : total_Rs=total_Rs+item[choice_E].price ;
               printf("\tAdded to cart");
               main_menu();
               break;
    case 47  : total_Rs=total_Rs+item[choice_E].price ;
               printf("\tAdded to cart");
               main_menu();
               break;
    case 48  : total_Rs=total_Rs+item[choice_E].price ;
               printf("\tAdded to cart");
               main_menu();
               break;
    case 49  : total_Rs=total_Rs+item[choice_E].price ;
               printf("\tAdded to cart");
               main_menu();
               break;
    case 50  : total_Rs=total_Rs+item[choice_E].price ;
               printf("\tAdded to cart");
               main_menu();
               break;
    case 51  : total_Rs=total_Rs+item[choice_E].price ;
               printf("\tAdded to cart");
               main_menu();
               break;
    default  : main_menu();
               break;
    }


    gotoxy(5,50);

}

void contact()
{

    system("cls");
    window(25,60,20,32);
    gotoxy(33,18);
    printf("CONTACT US");
    gotoxy(29,22);
    printf("Shubham Rai     : 7859878908");
    gotoxy(29,23);
    printf("Zeeshan Al      : 9891154325");
    gotoxy(29,24);
    printf("Saad Bin        : 9717452795");
    gotoxy(29,25);
    printf("Shubham Mailk   : 9654334984");
    gotoxy(29,26);
    printf("Shubham Rawat   : 9716516922");
    gotoxy(29,27);
    printf("Shubham Rathore : 9654127013");
    gotoxy(29,28);
    printf("Sonu            : 7042338239");
    gotoxy(29,29);
    printf("Shilpi Aggarwal : 8585992417");
    gotoxy(29,30);
    printf("Riya Pathak     : 9958404576");
    gotoxy(29,31);
    printf("Priya Bogra     : 9999726756");

    fflush(stdin);
    scanf("%c", &ch);

    switch(ch)
    {
        default : main_menu();
    }
    gotoxy(5,50);
}

//Main Cart Logic

void total()
{
    system("cls");
    window(25,65,20,32);
    gotoxy(36,18);
    printf("TOTAL AMOUNT");
    gotoxy(28,22);
    printf("Total amount payable is: %f", total_Rs);
    gotoxy(28,25);
    printf("Please wait 5 Seconds");
    delay(5000);

    main_menu();

}

//Login Screen
int login()
{
    char u_name[10],pw[10];
    window(20,60,20,32);
    gotoxy(33,18);
    printf("SYSTEM LOGIN");
    gotoxy(25,22);
    printf("Enter User Name: ");
    scanf("%s", &u_name);
    gotoxy(25,23);
    printf("Enter the password : ");
   // fflush(stdin);
    scanf("%s" , &pw);

    if((strcmp(u_name,"admin") == 0 ) && (strcmp(pw,"password") == 0))
        {
            load();
            gotoxy(25,27);
            printf("****Logged in Successfully****");
            c_record();

        }

    else
    {
        load();
        gotoxy(25,27);
        printf("Incorrect Username or Password");
        delay(1000);
        gotoxy(5,50);
        exit(0);

    }

}

//Record Entry
int c_record()
{
    //struct customer cust;

    system("cls");
    window(20,60,20,32);
    gotoxy(33,18);
    printf("ENTER YOUR DETAILS\n\n");
    gotoxy(25,22);
    printf("Name:");
    scanf("%s", &cust.c_name);
    gotoxy(25,23);
    printf("Email ID:");
    scanf("%s", &cust.c_email);
    fflush(stdin);
    gotoxy(25,24);
    printf("Mobile Number:");
    scanf("%lf.0", &cust.c_num);
    load();
    delay(1000);
    gotoxy(25,28);
    printf("***Details Recorded***");
    delay(1000);

}

//Record Print
int c_print()
{
    //struct customer cust;
    gotoxy(10,24);
    printf("Name:");
    gotoxy(25,24);
    printf("%s", cust.c_name);
    gotoxy(10,26);
    printf("Email ID:");
    gotoxy(25,26);
    printf("%s", cust.c_email);
    gotoxy(10,28);
    printf("Mobile Number:");
    gotoxy(25,28);
    printf("%lf.0", cust.c_num);

}

//Load Screen
int load()
{
    long double z;
    int q;
    gotoxy(25,25);
    for(q=0;q<30;q++)
    {
        delay(50);
        int c=219;
        printf("%c", c);
    }
}

void end_program()
{
   window(3,77,20,40);
   gotoxy(35,18);
   printf("THANKS FOR SHOPPING");
   gotoxy(10,22);
   printf("YOUR DETAILS ARE :");
   c_print();
   gotoxy(10,30);
   printf("Your Total Payable Amount is :");
   gotoxy(41,30);
   printf("%f", total_Rs);
   gotoxy(10,32);
   printf("Please wait 5 Seconds");
   delay(5000);
   gotoxy(10,34);
   printf("A Conformation Has Been Sent to Your Mobile Number");
   delay(5000);
   exit(0);
}

//Main Loading Screen

void main_load()
{
    long double z;
    int q;
    gotoxy(35,13);
    printf("LOADING");
    gotoxy(1,15);
    for(q=0;q<78;q++)
    {
        delay(25);
        int c=219;
        printf("%c", c);
    }
}

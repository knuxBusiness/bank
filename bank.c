#include <stdio.h>
#include <stdlib.h>
struct user
{
    int passcode;
    char name[20];
    int dd, mm, yy;
    int balance;
};

struct user a[5];
// user iputs data for account

// Balance sheet for every user
struct user input()
{
    struct user x;
    printf("Please Enter Your Passcode :");
    scanf("%d", &x.passcode);
    printf("Enter Your Name :");
    // fgets(x.name,20,stdin);
    fflush(stdin);
    gets(x.name);
    printf("Enter Your Date Of Birth :");
    scanf("%d/%d/%d", &x.dd, &x.mm, &x.yy);
    x.balance = 0;
    return x;
}

// display user details
void display(struct user x)
{
    printf("Name :%s\n", x.name);
    printf("DOB :%d/%d/%d\n", x.dd, x.mm, x.yy);
}

// transaction of user

int main()
{   
    FILE *bank;
    bank=fopen("bank.dat","ab+");
    int op1 = 0, op2, pass, bal, damt, wamt;
    int i = 0;
    char ex;
    printf("=====Welcome to ACB Bank=====\n");
    while (op1 < 3)
    {
    menu:;
        printf("Please choose an option\n1.New User\n2.Existing User\n3.Quit\n");
        scanf("%d", &op1);
        // for New User Deatails
        if (op1 == 1)
        {
            printf("Enter Your UserNumber :");
            scanf("%d", &op2);
            do
            {
                a[op2] = input();
                fwrite(&a[op2],sizeof(a[op2]),1,bank);
                fclose(bank);

            } while (1 < 0);
            goto dis;
        }

        // For existing user deatails
        else if (op1 == 2)
        {
            printf("Enter Your userNumber :");
            scanf("%d", &op2);
            printf("Enter Your PassCode :");
            scanf("%d", &pass);

            do
            {
                if (pass == a[op2].passcode)
                {
                dis:;
                    display(a[op2]);
                fi:;
                    printf("Choose an option :\n1.Check Account Balance\n2.Diposit\n3.Withdraw\n4.Main Menu\n5.Exit\n");
                    scanf("%d", &bal);
                    switch (bal)
                    {
                    case 1:
                        printf("The Account Balance :%d\n", a[op2].balance);
                        break;
                    case 2:
                        printf("Enter The Amount :");
                        scanf("%d", &damt);
                        a[op2].balance = a[op2].balance + damt;
                        printf("Balance :%d\n", a[op2].balance);
                        break;
                    case 3:
                        printf("Balance :%d\n", a[op2].balance);
                        if (a[op2].balance != 0)
                        {
                            printf("Enter The Amount :");
                            scanf("%d", &wamt);
                            if (a[op2].balance <= wamt)
                            {
                                printf("Insufficent Balance");
                            }
                            else
                            {
                                printf("Withdrwal Successful\n");
                                a[op2].balance = a[op2].balance - wamt;
                                printf("Remaining Balance :%d\n", a[op2].balance);
                            }
                        }
                        break;
                    case 4:
                        goto menu;
                        continue;
                    case 5:
                        exit(1);
                    default:
                        printf("Try again later");
                        // printf("Try again later");
                    }
                }
                else
                {
                    printf("Sorry ! Missing user");
                    goto menu;
                }
                goto fi;
            } while (op2 < 5);
        }
    }
}


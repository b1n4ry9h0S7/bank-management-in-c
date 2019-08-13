#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

int i, j;
int main_exit;
void menu();
void close();

struct date {
    int month, day, year;

};
struct {

    char name[60];
    int acc_no, age;
    char address[100];
    char citizenship[15];
    double phone;
    char acc_type[10];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;

}
add, upd, check, rem, transaction;

float interest(float t, float amount, int rate) {
    float SI;
    SI = (rate * t * amount) / 100.0;
    return (SI);

}
void fordelay(int j) {
    int i;
    for (i = 0; i < j; i++) {}
    // k=i;
}
void close() {
    exit(0);
}
void new_acc()

{
    FILE * ptr;

    ptr = fopen("record.dat", "a+");
    account_no:
        system("cls");
    printf("\n\n\t\t\t\xB2\xB2\xB2\xB2 ADD RECORD \xB2\xB2\xB2\xB2");
    printf("\n\n\nEnter today's date(mm/dd/yyyy):");
    scanf("%d/%d/%d", & add.deposit.month, & add.deposit.day, & add.deposit.year);
    printf("\n\n\t\tEnter the account number:");
    scanf("%d", & check.acc_no);
    while (fscanf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", & add.acc_no, add.name, & add.dob.month, & add.dob.day, & add.dob.year, & add.age, add.address, add.citizenship, & add.phone, add.acc_type, & add.amt, & add.deposit.month, & add.deposit.day, & add.deposit.year) != EOF) {
        if (check.acc_no == add.acc_no) {
            printf("\n\n\t\tAccount no. already in use!");
            fordelay(1000000000);
            goto account_no;
        }
    }
    add.acc_no = check.acc_no;
    printf("\n\n\t\tEnter the name:");
    scanf("%s", add.name);
    printf("\nEnter the date of birth(mm/dd/yyyy):");
    scanf("%d/%d/%d", & add.dob.month, & add.dob.day, & add.dob.year);
    printf("\n\n\t\tEnter the age:");
    scanf("%d", & add.age);
    printf("\n\n\t\tEnter the address:");
    scanf("%s", add.address);
    printf("\n\n\t\tEnter the citizenship number:");
    scanf("%s", add.citizenship);
    printf("\n\n\t\tEnter the phone number: ");
    scanf("%lf", & add.phone);
    printf("\n\n\t\tEnter the amount to deposit:Rs.");
    scanf("%f", & add.amt);
    printf("\n\n\t\tType of account:\n\t[#] saving\n\n\t\tg (Savings account)\n\t[#] current (Current account)\n\t[#] fixed1(Fixed account for 1 year)\n\t[#] fixed2(Fixed account for 2 years)\n\t[#] fixed3(Fixed account for 3 years)\n\n\tPlease type your choice:");
    scanf("%s", add.acc_type);
    fprintf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
    fclose(ptr);
    printf("\n\n\t\tAccount created successfully!");
    add_invalid:
        printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d", & main_exit);
    system("cls");
    if (main_exit == 1) {
        menu();
    } else if (main_exit == 0) {
        close();
    } else {
        printf("\n\n\t\tInvalid!\a");
        goto add_invalid;
    }
}
void view_list() {
    int test = 0;
    FILE * view;
    view = fopen("record.dat", "r");

    system("cls");
    printf("\n\n\t\t\t\xB2\xB2\xB2\xB2 CUSTOMER LIST \xB2\xB2\xB2\xB2");
    printf("\n\n\t\tACC.NO.\t\tNAME\t\tADDRESS\t\tPHONE\n");

    while (fscanf(view, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", & add.acc_no, add.name, & add.dob.month, & add.dob.day, & add.dob.year, & add.age, add.address, add.citizenship, & add.phone, add.acc_type, & add.amt, & add.deposit.month, & add.deposit.day, & add.deposit.year) != EOF) {
        printf("\n\n\t\t%6d\t\t%6s\t%s\t%.0lf", add.acc_no, add.name, add.address, add.phone);
        test++;
    }

    fclose(view);
    if (test == 0) {
        system("cls");
        printf("\n\n\t\tNO RECORDS!!\n");
    }

    view_list_invalid:
        printf("\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d", & main_exit);
    system("cls");
    if (main_exit == 1)
        menu();
    else if (main_exit == 0)
        close();
    else {
        printf("\n\n\t\tInvalid!\a");
        goto view_list_invalid;
    }
}
void edit(void) {
    int choice, test = 0;
    FILE * old, * newrec;
    old = fopen("record.dat", "r");
    newrec = fopen("new.dat", "w");
    printf("\n\n\t\t\t\xB2\xB2\xB2\xB2 UPDATE RECORD \xB2\xB2\xB2\xB2");
    printf("\n\n\t\tEnter account number: ");
    scanf("%d", & upd.acc_no);
    while (fscanf(old, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", & add.acc_no, add.name, & add.dob.month, & add.dob.day, & add.dob.year, & add.age, add.address, add.citizenship, & add.phone, add.acc_type, & add.amt, & add.deposit.month, & add.deposit.day, & add.deposit.year) != EOF) {
        if (add.acc_no == upd.acc_no) {
            test = 1;
            printf("\n\n\t\tWhich information do you want to change?\n1.Address\n2.Phone\n\nEnter your choice: ");
            scanf("%d", & choice);
            system("cls");
            if (choice == 1) {
                printf("\n\n\t\tEnter new address: ");
                scanf("%s", upd.address);
                fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, upd.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
                system("cls");
                printf("\n\n\t\tChanges saved!");
            } else if (choice == 2) {
                printf("\n\n\t\tEnter the new phone number:");
                scanf("%lf", & upd.phone);
                fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, upd.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
                system("cls");
                printf("\n\n\t\tChanges saved!");
            }

        } else
            fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat", "record.dat");

    if (test != 1) {
        system("cls");
        printf("\n\n\t\tRecord not found!!\a\a\a");
        edit_invalid:
            printf("\n\n\t\tEnter 0 to try again,1 to return to main menu and 2 to exit: ");
        scanf("%d", & main_exit);
        system("cls");
        if (main_exit == 1)

            menu();
        else if (main_exit == 2)
            close();
        else if (main_exit == 0)
            edit();
        else {
            printf("\n\n\t\tInvalid!\a");
            goto edit_invalid;
        }
    } else {
        printf("\n\n\t\tEnter 1 to go to the main menu and 0 to exit: ");
        scanf("%d", & main_exit);
        system("cls");
        if (main_exit == 1)
            menu();
        else
            close();
    }
}

void transact(void) {
    int choice, test = 0;
    FILE * old, * newrec;
    old = fopen("record.dat", "r");
    newrec = fopen("new.dat", "w");
    printf("\n\n\t\t\t\xB2\xB2\xB2\xB2 TRANSACTION \xB2\xB2\xB2\xB2");
    printf("\n\n\t\tEnter the account number: ");
    scanf("%d", & transaction.acc_no);
    while (fscanf(old, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", & add.acc_no, add.name, & add.dob.month, & add.dob.day, & add.dob.year, & add.age, add.address, add.citizenship, & add.phone, add.acc_type, & add.amt, & add.deposit.month, & add.deposit.day, & add.deposit.year) != EOF) {

        if (add.acc_no == transaction.acc_no) {
            test = 1;
            if (strcmpi(add.acc_type, "fixed1") == 0 || strcmpi(add.acc_type, "fixed2") == 0 || strcmpi(add.acc_type, "fixed3") == 0) {
                printf("\a\a\a\n\nYOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!");
                fordelay(1000000000);
                system("cls");
                menu();

            }
            printf("\n\n\t\tDo you want to\n1.Deposit\n2.Withdraw?\n\nEnter your choice(1 for deposit and 2 for withdraw): ");
            scanf("%d", & choice);
            if (choice == 1) {
                printf("\n\n\t\tEnter the amount you want to deposit:Rs. ");
                scanf("%f", & transaction.amt);
                add.amt += transaction.amt;
                fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
                printf("\n\n\t\tDeposited successfully!");
            } else {
                printf("\n\n\t\tEnter the amount you want to withdraw:Rs. ");
                scanf("%f", & transaction.amt);
                add.amt -= transaction.amt;
                fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
                printf("\n\nWithdrawn successfully!");
            }

        } else {
            fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
        }
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat", "record.dat");
    if (test != 1) {
        printf("\n\n\t\tRecord not found!!");
        transact_invalid:
            printf("\n\n\t\tEnter 0 to try again,1 to return to main menu and 2 to exit: ");
        scanf("%d", & main_exit);
        system("cls");
        if (main_exit == 0)
            transact();
        else if (main_exit == 1)
            menu();
        else if (main_exit == 2)
            close();
        else {
            printf("\n\n\t\tInvalid!");
            goto transact_invalid;
        }

    } else {
        printf("\n\n\t\tEnter 1 to go to the main menu and 0 to exit: ");
        scanf("%d", & main_exit);
        system("cls");
        if (main_exit == 1)
            menu();
        else
            close();
    }

}
void erase(void) {
    FILE * old, * newrec;
    int test = 0;
    old = fopen("record.dat", "r");
    newrec = fopen("new.dat", "w");
    printf("\n\n\t\t\t\xB2\xB2\xB2\xB2 DELETE RECORD \xB2\xB2\xB2\xB2");
    printf("\n\n\t\tEnter the account number to delete: ");
    scanf("%d", & rem.acc_no);
    while (fscanf(old, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", & add.acc_no, add.name, & add.dob.month, & add.dob.day, & add.dob.year, & add.age, add.address, add.citizenship, & add.phone, add.acc_type, & add.amt, & add.deposit.month, & add.deposit.day, & add.deposit.year) != EOF) {
        if (add.acc_no != rem.acc_no)
            fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);

        else {
            test++;
            printf("\n\t\tRecord deleted successfully!\n");
        }
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat", "record.dat");
    if (test == 0) {
        printf("\n\t\tRecord not found!!\a\a\a");
        erase_invalid:
            printf("\n\t\tEnter 0 to try again,1 to return to main menu and 2 to exit: ");
        scanf("%d", & main_exit);

        if (main_exit == 1)
            menu();
        else if (main_exit == 2)
            close();
        else if (main_exit == 0)
            erase();
        else {
            printf("\nInvalid!\a");
            goto erase_invalid;
        }
    } else {
        printf("\n\n\t\tEnter 1 to go to the main menu and 0 to exit: ");
        scanf("%d", & main_exit);
        system("cls");
        if (main_exit == 1)
            menu();
        else
            close();
    }

}

void see(void) {
    FILE * ptr;
    int test = 0, rate;
    int choice;
    float time;
    float intrst;
    ptr = fopen("record.dat", "r");
    printf("\n\n\t\t\t\xB2\xB2\xB2\xB2 CUSTOMER DETAILS \xB2\xB2\xB2\xB2");
    printf("\n\n\t\tDo you want to check by\n[1] Account number\n [2] Name\nEnter your choice: ");
    scanf("%d", & choice);
    if (choice == 1) {
        printf("\n\n\t\tEnter the account number:");
        scanf("%d", & check.acc_no);

        while (fscanf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", & add.acc_no, add.name, & add.dob.month, & add.dob.day, & add.dob.year, & add.age, add.address, add.citizenship, & add.phone, add.acc_type, & add.amt, & add.deposit.month, & add.deposit.day, & add.deposit.year) != EOF) {
            if (add.acc_no == check.acc_no) {
                system("cls");
                test = 1;
                printf("\n\n\t\t\tACCOUNT DETAILS\n");
                printf("\nAccount Number: %d\nName: %s \nDOB: %02d/%02d/%04d \nAge: %d \nAddress: %s \nCitizenship No: %s \nPhone number: %.0lf \nType Of Account: %s \nAmount deposited: Rs. %.2f \nDate Of Deposit: %02d/%02d/%04d\n\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone,
                    add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
                if (strcmpi(add.acc_type, "fixed1") == 0) {
                    time = 1.0;
                    rate = 9;
                    intrst = interest(time, add.amt, rate);
                    printf("\n\n\t\tYou will get Rs. %.2f as interest on %d/%d/%d", intrst, add.deposit.month, add.deposit.day, add.deposit.year + 1);
                } else if (strcmpi(add.acc_type, "fixed2") == 0) {
                    time = 2.0;
                    rate = 11;
                    intrst = interest(time, add.amt, rate);
                    printf("\n\n\t\tYou will get Rs. %.2f as interest on %d/%d/%d", intrst, add.deposit.month, add.deposit.day, add.deposit.year + 2);

                } else if (strcmpi(add.acc_type, "fixed3") == 0) {
                    time = 3.0;
                    rate = 13;
                    intrst = interest(time, add.amt, rate);
                    printf("\n\n\t\tYou will get Rs. %.2f as interest on %d/%d/%d", intrst, add.deposit.month, add.deposit.day, add.deposit.year + 3);

                } else if (strcmpi(add.acc_type, "saving") == 0) {
                    time = (1.0 / 12.0);
                    rate = 8;
                    intrst = interest(time, add.amt, rate);
                    printf("\n\n\t\tYou will get Rs. %.2f as interest on %d of every month", intrst, add.deposit.day);

                } else if (strcmpi(add.acc_type, "current") == 0) {

                    printf("\n\n\t\tYou will get no interest\a\a");

                }
            }
        }
    } else if (choice == 2) {
        printf("\n\n\t\tEnter the name: ");
        scanf("%s", check.name);
        while (fscanf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", & add.acc_no, add.name, & add.dob.month, & add.dob.day, & add.dob.year, & add.age, add.address, add.citizenship, & add.phone, add.acc_type, & add.amt, & add.deposit.month, & add.deposit.day, & add.deposit.year) != EOF) {
            if (strcmpi(add.name, check.name) == 0) {
                system("cls");
                test = 1;
                printf("\nAccount Number: %d\nName: %s \nDOB: %02d/%02d/%02d \nAge: %d \nAddress: %s \nCitizenship No: %s \nPhone number: %.0lf \nType Of Account: %s \nAmount deposited: Rs.%.2f \nDate Of Deposit:%02d/%02d/%04d\n\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone,
                    add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
                if (strcmpi(add.acc_type, "fixed1") == 0) {
                    time = 1.0;
                    rate = 9;
                    intrst = interest(time, add.amt, rate);
                    printf("\n\n\t\tYou will get Rs. %.2f as interest on %d/%d/%d", intrst, add.deposit.month, add.deposit.day, add.deposit.year + 1);
                } else if (strcmpi(add.acc_type, "fixed2") == 0) {
                    time = 2.0;
                    rate = 11;
                    intrst = interest(time, add.amt, rate);
                    printf("\n\n\t\tYou will get Rs. %.2f as interest on %d/%d/%d", intrst, add.deposit.month, add.deposit.day, add.deposit.year + 2);

                } else if (strcmpi(add.acc_type, "fixed3") == 0) {
                    time = 3.0;
                    rate = 13;
                    intrst = interest(time, add.amt, rate);
                    printf("\n\n\t\tYou will get Rs. %.2f as interest on %d/%d/%d", intrst, add.deposit.month, add.deposit.day, add.deposit.year + 3);

                } else if (strcmpi(add.acc_type, "saving") == 0) {
                    time = (1.0 / 12.0);
                    rate = 8;
                    intrst = interest(time, add.amt, rate);
                    printf("\n\n\t\tYou will get Rs. %.2f as interest on %d of every month", intrst, add.deposit.day);

                } else if (strcmpi(add.acc_type, "current") == 0) {

                    printf("\n\n\t\tYou will get no interest\a\a");
                }
            }
        }
    }

    fclose(ptr);
    if (test != 1) {
        system("cls");
        printf("\n\n\t\tRecord not found!!\a\a\a");
        see_invalid:
            printf("\n\n\t\tEnter 0 to try again,1 to return to main menu and 2 to exit: ");
        scanf("%d", & main_exit);
        system("cls");
        if (main_exit == 1)
            menu();
        else if (main_exit == 2)
            close();
        else if (main_exit == 0)
            see();
        else {
            system("cls");
            printf("\nInvalid!\a");
            goto see_invalid;
        }
    } else {
        printf("\n\n\t\tEnter 1 to go to the main menu and 0 to exit: ");
        scanf("%d", & main_exit);
    }
    if (main_exit == 1) {
        system("cls");
        menu();
    } else {

        system("cls");
        close();
    }
}

void menu(void) {
    int choice;
    system("cls");
    system("color 9");
    printf("\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BANKING MANAGEMENT SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t[1] Create Account\n\t\t[2] Update Account\n\t\t[3] Transaction\n\t\t[4] Check Account\n\t\t[5] Delete ccount\n\t\t[6] Customer List\n\t\t[7] Exit\n\n\n\n\n\t\t Enter your choice: ");
    scanf("%d", & choice);

    system("cls");
    switch (choice) {
    case 1:
        new_acc();
        break;
    case 2:
        edit();
        break;
    case 3:
        transact();
        break;
    case 4:
        see();
        break;
    case 5:
        erase();
        break;
    case 6:
        view_list();
        break;
    case 7:
        close();
        break;

    }

}
int main() {
    char pass[10], password[10] = "pass";
    int i = 0;
    printf("\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BANKING MANAGEMENT SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Login \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\tPlease enter the login password:\t");
    scanf("%s", pass);
    if (strcmp(pass, password) == 0) {
        printf("\n\n\t\tPassword Match!\n\n\t\tLOADING");
        for (i = 0; i <= 6; i++) {
            fordelay(100000000);
            printf(".");
        }
        system("cls");
        menu();
    } else {
        printf("\n\n\t\tWrong password!!\a\a\a");
        login_try:
            printf("\n\n\t\tEnter 1 to try again and 0 to exit:");
        scanf("%d", & main_exit);
        if (main_exit == 1) {

            system("cls");
            main();
        } else if (main_exit == 0) {
            system("cls");
            close();
        } else {
            printf("\n\n\t\tInvalid!");
            fordelay(1000000000);
            system("cls");
            goto login_try;
        }

    }
    return 0;
}
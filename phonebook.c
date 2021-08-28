#include <stdio.h>

struct phonebook
{
    char first_name[15];
    char family_name[15];
    unsigned long long int mobile;
    unsigned long long int landline;
} contact[50];

void new (int);
void modify(int, unsigned long long int, int);

int main()
{
    int nums = 0;
    while (1)
    {
        int code;
        printf("\nPress 1 to enter new contacts.\n");
        printf("Press 2 to modify contact.\n");
        printf("Press 3 to print list of all contacts.\n");
        printf("Press 4 to EXIT\n");
        printf("Your command: ");
        scanf("%d", &code);
        fflush(stdin);

        int n, m;
        unsigned long long int mob;
        switch (code)
        {
        case 1:
            printf("Enter the number of contacts you want to store: ");
            scanf("%d", &n);
            fflush(stdin);
            nums += n;
            new (nums);
            break;

        case 2:
            printf("\nEnter the mobile number whose info you wanna edit:");
            scanf("%llu", &mob);
            fflush(stdin);
            printf("Press 1 to modify First Name.\n");
            printf("Press 2 to modify Family Name.\n");
            printf("Press 3 to modify Mobile Number.\n");
            printf("Press 4 to modify Landline Number\n");
            printf("Your command: ");
            scanf("%d", &m);
            fflush(stdin);
            modify(nums, mob, m);
            break;

        case 3:
            printf("\n------List Of All Contacts------\n");
            printf("FIRST NAME  Family Name  MOBILE NUMBER  LANDLINE\n");
            for (int j = 0; j < nums; j++)
            {
                printf("%s \t %s     %llu     %llu\n", contact[j].first_name, contact[j].family_name, contact[j].mobile, contact[j].landline);
            }
            break;

        case 4:
            return 0;

        default:
            printf("Invalid Input");
        }
    }
    return 0;
}

void new (int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\n----Info of Contact %d----\n", i + 1);
        printf("Enter the First Name: ");
        gets(contact[i].first_name);
        printf("Enter the Family Name: ");
        gets(contact[i].family_name);
        printf("Enter the Mobile Number: ");
        scanf("%llu", &contact[i].mobile);
        fflush(stdin);
        printf("Enter the Landline Number: ");
        scanf("%llu", &contact[i].landline);
        fflush(stdin);
    }
}

void modify(int n, unsigned long long int mob, int m)
{
    int k;
    for (int i = 0; i < n; i++)
    {
        if (contact[i].mobile == mob)
            k = i;
    }
    unsigned long long int temp;
    switch (m)
    {
    case 1:
        printf("Enter the New First Name:");
        gets(contact[k].first_name);
        break;

    case 2:
        printf("Enter new Family Name:");
        gets(contact[k].family_name);
        break;

    case 3:
        printf("Enter new Mobile Number:");
        scanf("%llu", &temp);
        contact[k].mobile = temp;
        break;

    case 4:
        printf("Enter new Landline Number:");
        scanf("%llu", &temp);
        contact[k].landline = temp;
        break;

    default:
        printf("Invalid Input");
        break;
    }
}

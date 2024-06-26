// Calendar project
#include<stdio.h>
#include<math.h>
int main()
{
    int year, month, daysInMonth, startingDay, daysOfWeek;
    char monthNames[][20] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
    printf("Enter  year: ");
    scanf("%d",&year);
    printf("Enter Month(0-12): ");
    scanf("%d",&month);

    // calculate the number of days in month
    if(month == 2)
        {
            if ((year%100 == 0 && year % 400 == 0) || (year % 4 == 0))  // check leap year or not
                {
                    daysInMonth = 29;
                }
            else
                daysInMonth = 28;
        }

    else if(month == 4 || month == 6 || month == 9 || month == 11)
        {
            daysInMonth = 30;
        }
    else
        daysInMonth = 31;
    // calculate starting day of month
    startingDay = ((year-1) * 365) + ((year-1) / 4) - ((year-1) / 100) + ((year-1) / 400);
    for(int i = 1; i < month; i++)
    {
        if(i == 2)
        {
            if ((year%100 == 0 && year % 400 == 0) || (year % 4 == 0))  // check leap year or not
                {
                    startingDay += 29;
                }
            else
                startingDay += 28;
        }

        else if(i == 4 || i == 6 || i == 9 || i == 11)
            {
                startingDay += 30;
            }
        else
            startingDay += 31;   
    }
    daysOfWeek = (startingDay+1) % 7; // Incrementing the starting by 1 to find exact week days
    // Display calendar
    printf("\n =====================================\n");
    printf("     Year : %4d   Month: %s\n", year, monthNames[month-1]);
    printf(" =====================================\n");
    printf("  SUN  MON  TUE  WED  THU  FRI  SAT\n");

    // print spaces for the days before starting day of the month
    for(int i=1; i<=daysOfWeek; i++)
        {
            printf("     ");
        }
    // print days in month
    for(int day=1; day<=daysInMonth; day++)
        {
            printf("%5d", day);
            if((day+daysOfWeek) % 7 == 0) // if the current day + daysofweek is multiply of 7 then it move to next line 
                {
                    printf(" \n");
                }
        }
    printf("\n");
    return 0;

}

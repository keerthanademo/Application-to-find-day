#include<stdio.h>
int main()
{
    int date,month,year,next_yr,month_total;
    //GETTING THE INPUT FROM USER
    printf("Enter the date:");
    scanf("%d",&date);
    if(date<1 || date>31)
    {
        printf("please enter the valid date between 1 to 31");
    }
    else
    {
        printf("Enter the month:");
        if(scanf("%d",&month)!=1 || month<1 || month>12)
        {
           printf("Please enter the valid month between 1 to 12 in integer form");
        }
        else
        {
            printf("Enter the year:");
            scanf("%d",&year);
            if(year<1000)
            {
                printf("Please enter the valid year");
            }
            else
            {
                //FINDING PREVIOUS YEAR
                int previous_year=year-1;
                //FINDING THE ODD DAYS IN THE PREVIOUS YEAR
                int year_400_cycle=previous_year/400;
                //FINDING REMAINING YEAR AFTER THAT 400 COMPLETE CYCLE
                int remaining_year=previous_year%400;
                //EXTRACT FOR 100,200,300
                if (remaining_year >= 300)
                {
                    next_yr = 300;
                }
                else if (remaining_year >= 200)
                {
                    next_yr = 200;
                }
                else if (remaining_year >= 100)
                {
                    next_yr = 100;
                }
                else
                {
                    next_yr = remaining_year;
                }
                //CALCULATE THE ODD DAYS FOR  REMAINING YEAR
                int leap_year1=next_yr/4 - next_yr/100 + next_yr/400;
                int non_leap_year1=next_yr-leap_year1;
                //NOW FOR ALL LEAP_YEAR SHOULD *2 AND NON_LEAP *1
                int odd_days1=(leap_year1*2+non_leap_year1*1)%7;  //total odd_days for previous year
                //CALCULATE FOR LEFT_OVER YEAR
                int left_over_year=remaining_year-next_yr;
                int leap_year2=left_over_year/ 4 - left_over_year/100 + left_over_year/400;
                int non_leap_year2 = left_over_year - leap_year2;
                //CALCULATE THE ODD DAYS FOR  LEFT OVER YEAR
                int odd_days2=(leap_year2*2+non_leap_year2*1)%7;
                //CALCULATE TOTAL ODD DAYS FOR REMAINING YEAR
                int tot_odd_days = (odd_days1 + odd_days2) % 7;
                //NOW CALCULATING FOR MONTHS IN CURRENT YEAR
                // Array to store day names
                char *days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
                // Array to store number of days in each month
                int arr[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
                //LEAP YEAR FOR CALCULATING FEB
                if((year%4==0 && year%100!=0)||(year%400==0))
                {
                    arr[1]=29;
                }
                //CALCULATING THE MONTH TILL GIVEN MONTH
                for(int i=0;i<month;i++)
                {
                    if(i==month-1)
                    {
                        month_total+=date;
                    }
                    else
                    {
                        month_total+=arr[i];
                    }
                }
                int odd_day_month=month_total%7;
                int final_odd_day=(tot_odd_days+odd_day_month)%7;
                printf("The day is %s",days[final_odd_day]);
                return 0;
            } 
        }
    }
}


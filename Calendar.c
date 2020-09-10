#include <stdio.h>
#include <stdlib.h>

int firstday(int year){

  int d;
  d = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7;
  return d;
}

int calendar()
{
   int year,month,day,daysInMonth,weekDay=0,startingDay;
   printf("\nEnter the Year:");
   scanf("%d",&year);

   char *months[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
   int monthDay[]={31,28,31,30,31,30,31,31,30,31,30,31};

   if((year%4==0&&year%100!=0)||year%400==0)
       monthDay[1]=29;

   startingDay=firstday(year);

   for(month=0;month<12;month++)
   {

      daysInMonth=monthDay[month];
      printf("\n\n---------------%s-------------------\n",months[month]);
      printf("\n  Sun  Mon  Tue  Wed  Thurs  Fri  Sat\n");

      for(weekDay=0;weekDay<startingDay;weekDay++)
        printf("     ");

      for(day=1;day<=daysInMonth;day++){
        printf("%5d",day);

        if(++weekDay>6){
            printf("\n");
            weekDay=0;
        }
        startingDay=weekDay;
      }

   }
}
  int dayoftheweek(){
                  int dat, mont, years;
                  printf("Enter the Year : ");
                  scanf("%d", &years);
                  printf("\nEnter the Month : ");
                  scanf("%d", &mont);
                  printf("\nEnter the Date : ");
                  scanf("%d", &dat);
                  weekday(dat, mont, years);
                  return 0;
                  }
    int weekday(int date, int month, int year) {
           int dayWeek, yr, yd;
           yr = year % 100;
           yd = year / 100;
           printf("\nThe Date Given is : %d / %d / %d \n\n", date, month, year);
           dayWeek = 1.25 * yr + findm(month, year) + date - 2 * (yd % 4);
           dayWeek = dayWeek % 7;
           switch (dayWeek){
           case 0:  printf("Day of Week is : Saturday\n");
                        break;
           case 1:  printf("Day of Week is : Sunday\n");
                        break;
           case 2:  printf("Day of Week is : Monday\n");
                        break;
           case 3:  printf("Day of Week is : Tuesday\n");
                        break;
           case 4:  printf("Day of Week is : Wednesday\n");
                        break;
           case 5:  printf("Day of Week is : Thursday\n");
                        break;
           case 6:  printf("Day of Week is : Friday\n");
                        break;
           default:  printf("The Given input data is wrong");
           }
           return 0;
           }
    int findm(int months, int yearss){
           int findmonth, leapyr;
           if ((yearss % 100 == 0) && (yearss % 400 != 0))
           leapyr = 0;
           else if (yearss % 4 == 0)
           leapyr = 1;
           else
           leapyr = 0;
           findmonth = 3 + (2 - leapyr) * ((months + 2) / (2 * months))
+ (5 * months + months / 9) / 2;
           findmonth = findmonth % 7;
           return findmonth;
    }

int main ()
{
    printf ("\t\t     Select which one to display\n");
    while (1){
        printf ("1. Calendar of every month\n2. Day of the Week\n");

        int in;
        scanf ("%d", &in);
        getchar ();
        switch (in){
            case 1 : {
                calendar ();
                break;
            }
            case 2 : {
                dayoftheweek();
                break;
            }
                return 0;

        }
    }
}

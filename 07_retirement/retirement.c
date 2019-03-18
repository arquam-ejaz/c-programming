#include <stdio.h>
#include <stdlib.h>

struct _retire_info
{
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct _retire_info retire_info;

double calculation(retire_info r, double initial)
{
  initial+=initial*r.rate_of_return + r.contribution;
  return initial;
}

void retirement(int startAge, double initial, retire_info working, retire_info retired)
{
  while(working.months>0)
    {
      printf("Age %3d month %2d you have $%.2lf\n", startAge/12, startAge%12, initial);
      initial= calculation(working, initial);
      startAge++;
      working.months--;
    }
  while(retired.months>0)
    {
      printf("Age %3d month %2d you have $%.2lf\n", startAge/12, startAge%12, initial);
      initial= calculation(retired, initial);
      startAge++;
      retired.months--;
    }
}

int main()
{
  int startAge=327;
  double initial=21345;

  retire_info working;
  working.months=489;
  working.contribution=1000;
  working.rate_of_return=0.045/12;

  retire_info retired;
  retired.months=384;
  retired.contribution=-4000;
  retired.rate_of_return=0.01/12;
  retirement(startAge, initial, working, retired);
  return 0;
}


  
  

#include <stdio.h>
#include <stdlib.h>

#define PAYRATE 15.00
#define TAXRATE_300 0.15
#define TAXRATE_150 0.20
#define TAXRATE_REST 0.25
#define OVERTIME 40

int main()
{
//create variables
int hour = 0;
double grosspay = 0;
double taxes = 0;
double overTimepay = 0;
double netpay = 0;

//get data from the user
printf("Please Enter the number of hours worked this week: ");
scanf("%d", &hour);

//calculate gross pay
if (hour < 40)
grosspay = hour * PAYRATE;

else
{
	grosspay = 40 * PAYRATE;
	overTimepay = (hour - 40) * (PAYRATE * 1.5);
	grosspay += overTimepay;
}

//Calculate taxes
if (grosspay <= 300)
taxes = grosspay * TAXRATE_300;

else if (grosspay > 300 && grosspay <= 450)
{
	taxes = 300 * TAXRATE_300;
	taxes += (grosspay - 300) * TAXRATE_150;
}

else if (grosspay > 450)
{
	taxes = 300 * TAXRATE_300;
	taxes += 150 * TAXRATE_150;
	taxes += (grosspay - 450) * TAXRATE_REST;
}

//Calculate the netpay
netpay = grosspay - taxes;

//printout the results

printf("Grosspay: %.2f\n", grosspay);
printf("Taxes:  %.2f\n", taxes);
printf("Netpay: %.2f\n", netpay);

return 0;

}


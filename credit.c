#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
     int ssE = 0;
    int ssO = 0;

    //Gets the user card number
    long Cn = get_long("Card number: ");
    long ccp = Cn;
    long ccp1 = Cn;
    int length = 0;

    //Luhns algorithm
    while(Cn > 0)
    {
        //Calculation on the 2nd even digits position
        int Edgt = (Cn / 10) % 10;
        int Individual_sum = (Edgt*2)/10 + (Edgt*2)%10;
        ssE = ssE + Individual_sum;

        //Calculation on the 1st odd position
        int Odgt = Cn % 10;
        ssO = ssO + Odgt;

        //Stores the length of the card
        while(ccp > 0)
        {
            ccp = ccp/10;
            length++;
        }

        // Reduces the number
        Cn /= 100;
    }
    int luhn = ssE + ssO;

    if((luhn % 10) == 0)
    {
        //Identifying Visa
        int var1 = ccp1/1000000000000;
        int var2 = ccp1/1000000000000000;
        int var3 = ccp1/100000000000000;
        int var4 = ccp1/10000000000000;
        if((length == 13 || length == 16) && (var1 == 4 || var2 == 4))
        {
            printf("VISA\n");
            //return 0;
        }
        //Identifying Mastercard
        else if(length ==16 && (var3 >= 51 && var3 <= 55))
        {
            printf("MASTERCARD\n");
        }
        //Identifying AMEX
        else if(length ==15 && (var4 == 34 || var4 == 37))
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

}
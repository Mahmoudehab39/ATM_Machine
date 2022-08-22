#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\Card\card.h"


EN_cardError_t getCardHolderName(ST_cardData_t *cardData)
{
        printf("Please Enter the CardHolder Name from 20 characters and no more than 24: ");
        gets((char *)cardData->cardHolderName);
if (strlen((const char *)cardData->cardHolderName)>24||strlen( ( const char *)cardData->cardHolderName)<20 || NULL)
   {
        printf("\nerror: WRONG NAME\n");
        printf("Please Enter the CardHolder Name again from 20 characters and no more than 24: ");
        gets((char *)cardData->cardHolderName);
   }
if (strlen((const char *)cardData->cardHolderName)>24||strlen((const char *)cardData->cardHolderName)<20 || NULL)
   {
        printf("\nerror: WRONG NAME\n");
        return WRONG_NAME;
   }
        return OK;
}


EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData)
{
        printf("\nPlease Enter the CardHolder Date in the format MM/YY, e.g 05/25: ");
        gets((char *)cardData->cardExpirationDate);
if (strlen((const char *)cardData->cardExpirationDate)>5||strlen((const char *)cardData->cardExpirationDate)<5 || NULL)
   {
        printf("\nerror: WRONG EXP DATE\n");
        printf("Please Enter the CardHolder Date again in the format MM/YY, e.g 05/25: ");
        gets((char *)cardData->cardExpirationDate);
   }
if (strlen((const char *)cardData->cardExpirationDate)>5||strlen((const char *)cardData->cardExpirationDate)<5 || NULL)
   {
        printf("\nerror: WRONG EXP DATE\n");
        return WRONG_EXP_DATE;
   }
        return OK;
}


EN_cardError_t getCardPAN(ST_cardData_t *cardData)
{
        printf("\nPlease Enter the Card PAN in 19 character max, and 16 character min: ");
        gets((char *)cardData->primaryAccountNumber);
if(strlen((const char *)cardData->primaryAccountNumber)>19||strlen((const char *)cardData->primaryAccountNumber)<16 || NULL)
  {
        printf("\nerror: WRONG PAN\n");
        printf("Please Enter the Card PAN again in 19 character max, and 16 character min: ");
        gets((char *)cardData->primaryAccountNumber);
  }
if(strlen((const char *)cardData->primaryAccountNumber)>19||strlen((const char *)cardData->primaryAccountNumber)<16 || NULL)
  {
        printf("\nerror: WRONG PAN\n");
        return WRONG_PAN;
  }
    return OK;
}




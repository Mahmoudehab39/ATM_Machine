#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\Card\card.h"
#include "..\Terminal\terminal.h"


EN_terminalError_t getTransactionDate(ST_terminalData_t *termData)
{
        printf("\nPlease Enter the transaction Date in the format DD/MM/YYYY, e.g 25/06/2022: ");
        gets((char *)termData->transactionDate);
if (strlen((const char *)termData->transactionDate)>10||strlen((const char *)termData->transactionDate)<10 || NULL)
   {
        printf("\nWRONG_DATE");
        printf("\nPlease Enter the transaction Date again in the format DD/MM/YYYY, e.g 25/06/2022: ");
        gets((char *)termData->transactionDate);
   }
if (strlen((const char *)termData->transactionDate)>10||strlen((const char *)termData->transactionDate)<10 || NULL)
   {
        printf("\nWRONG_DATE\n");
        return WRONG_DATE;
   }
        return OKK;
}


EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData)
{

if(cardData.cardExpirationDate[3]<termData.transactionDate[8])
  {
        printf("\nEXPIRED CARD\n");
        exit(EXPIRED_CARD);
  }

else if(cardData.cardExpirationDate[3]==termData.transactionDate[8])
       {
       if(cardData.cardExpirationDate[4]<termData.transactionDate[9])
        {
                printf("\nEXPIRED CARD\n");
                exit(EXPIRED_CARD);
        }
       else if(cardData.cardExpirationDate[4]==termData.transactionDate[9])
              { if(cardData.cardExpirationDate[0]<termData.transactionDate[3])
                  {
                        printf("\nEXPIRED CARD\n");
                        exit(EXPIRED_CARD);
                  }
else if(cardData.cardExpirationDate[0]==termData.transactionDate[3])
       {
    if(cardData.cardExpirationDate[1]<termData.transactionDate[4])
      {
            printf("\nEXPIRED CARD\n");
            exit(EXPIRED_CARD);
      }
       }
              }
       }
        return OKK;
}


EN_terminalError_t getTransactionAmount(ST_terminalData_t *termData){
        printf("\nPlease Enter transaction amount: ");
        scanf("%f",&termData->transAmount);
if (termData->transAmount<=0)
   {
        printf("\nerror: INVALID AMOUNT");
        printf("\nPlease Enter transaction amount again: ");
        scanf("%f",&termData->transAmount);
   }
if (termData->transAmount<=0)
   {
        printf("\nerror: INVALID AMOUNT\n");
        return INVALID_AMOUNT;
   }
        return OK;
}


EN_terminalError_t setMaxAmount(ST_terminalData_t *termData)
{
        printf("\nPlease Enter The Maximum ATM Number That Could be Withdrawn: ");
        scanf("%f",&termData->maxTransAmount);
if((termData->maxTransAmount)<=0.000000)
  {
        printf("\nerror: INVALID MAX AMOUNT\n");
        printf("Please Enter The Maximum ATM Number That Could be Withdrawn again: ");
        scanf("%f",&termData->maxTransAmount);}
if((termData->maxTransAmount)<=0.000000)
  {
        printf("\nerror: INVALID MAX AMOUNT\n");
        return INVALID_MAX_AMOUNT;
  }
        return OKK;
}


EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *termData)
{
if (termData->transAmount>termData->maxTransAmount)
{
        printf("\nerror: EXCEED MAX AMOUNT\n");
        exit(EXCEED_MAX_AMOUNT);
}
else{
            return OKK;
    }
}






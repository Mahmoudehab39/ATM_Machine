#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\Card\card.h"
#include "..\Terminal\terminal.h"
#include "..\Server\server.h"


ST_accountsDB_t arrayd[4] ={3000,{"392000mahmoudehab"},300,{"392000mahmoudqwer"} };
ST_transaction arrayt ={0};
uint8_t i=0;
//ST_accountsDB_t arrayd[4] ={{3000,{"392000mahmoudehab"}},{300,{"392000mahmoudqwer"}} };

EN_transStat_t recieveTransactionData(ST_transaction *transData)
{
 {if(strcmp((const char *)arrayd[1].primaryAccountNumber,(const char *)transData->cardHolderData.primaryAccountNumber)==0)
    {
            i=1;
    }
else if(strcmp((const char *)arrayd[0].primaryAccountNumber,(const char *)transData->cardHolderData.primaryAccountNumber)==0)
       {
            i=0;
       }
else
    {
            return DECLINED_STOLEN_CARD;
    }
 }
if(arrayd[i].balance< transData->terminalData.transAmount )
  {
        printf("\nDECLINED INSUFFECIENT FUND\n");
        return DECLINED_INSUFFECIENT_FUND;
  }
        printf("\nAPPROVED\n");
        return APPROVED;
}


EN_serverError_t isValidAccount(ST_cardData_t *cardData)
{
if(strcmp((const char *)cardData->primaryAccountNumber,(const char *)arrayd[i].primaryAccountNumber) )
  {
        printf("\nDECLINED STOLEN CARD\n");
        exit(DECLINED_STOLEN_CARD);
  }
        printf("\nHello Ms %s\n",cardData->cardHolderName);
        return OK;
}


EN_serverError_t isAmountAvailable(ST_terminalData_t *termData)
{
        printf("\nThe Current Balance equals: %f$\n",arrayd[i].balance );
if(termData->transAmount> arrayd[i].balance)
  {
        printf("\nLOW BALANCE\n");
        exit(LOW_BALANCE);
  }
        printf("\nAVAILABLE\n");
        return OK;
}


EN_serverError_t saveTransaction(ST_transaction *transData)
{
        strcpy((char *)arrayt.cardHolderData.cardHolderName,(char *)transData->cardHolderData.cardHolderName);
        strcpy((char *)arrayt.cardHolderData.primaryAccountNumber,(char *)transData->cardHolderData.primaryAccountNumber);
        arrayt.terminalData.transAmount=  arrayd[i].balance  -transData->terminalData.transAmount;
        transData->transactionSequenceNumber=98712343;
if(arrayt.terminalData.transAmount==  arrayd[i].balance-transData->terminalData.transAmount)
  {
        transData->transactionSequenceNumber=transData->transactionSequenceNumber+1;
        printf("\nSAVING_SUCESSFUL\n");
  }
else
    {
            printf("\nSAVING_FAILED\n");
            exit(SAVING_FAILED);
    }
        arrayd[i].balance=arrayd[i].balance  -transData->terminalData.transAmount;
        printf("\nThe New Sequence Number is: %d",transData->transactionSequenceNumber);
        printf("\n\nThe Updated Balance equals: %f$",arrayd[i].balance);
        printf("\nYou Withdrew: %f$",transData->terminalData.transAmount);
        printf("\nThe Balance that saved in Transaction database is: %f$\n",arrayt.terminalData.transAmount);
        printf("\nThank You\n");
        return OK;
}






#include <stdio.h>
#include <stdlib.h>
#include "..\Card\card.h"
#include "..\Terminal\terminal.h"
#include "..\Server\server.h"
#include "..\Application\app.h"
void appStart(void)
{
        printf("|       | |               |\n");
        printf("| HELLO | |  ATM Machine  |\n");
        printf("|       | |               | \n\n");


ST_cardData_t t;
ST_terminalData_t tt;


if( getCardHolderName(&t)!=0)
  {
        exit(WRONG_NAME);
  }


if(getCardExpiryDate(&t)!=0)
  {
        exit(WRONG_EXP_DATE);
  }


if( getCardPAN(&t)!=0)
  {
        exit(WRONG_PAN);
  }


if(getTransactionDate(&tt)!=0)
  {
        exit(WRONG_DATE);
  }


isCardExpired(t,tt);


if( getTransactionAmount(&tt)!=0)
  {
        exit(INVALID_AMOUNT);
  }


if( setMaxAmount(&tt)!=0)
  {
        exit(INVALID_MAX_AMOUNT);
  }


isBelowMaxAmount(&tt);


ST_transaction rr={t,tt};


recieveTransactionData(&rr);


isValidAccount(&t);


isAmountAvailable(&tt);


saveTransaction(&rr);
}

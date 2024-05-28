/*=============  I N C L U D E S   =============*/
#include "C.h"


/*=============  L O C A L    F U N C T I O N S  =============*/


/* Verifies memory DMA copy by comparing destination data with source */
static int VerifyDataCopy (int status);
/* Copies Source Data to Destination Data */
static int CopySourceToDest (int* DestDataBuf, int* SrcDataBuf);

/*=============  C O D E  =============*/

int main(int argc, char *argv[])
{

	/* Copy data buffers */
	    int copy_success = (int)CopySourceToDest(DestDataBuf, SrcDataBuf);

	    if(copy_success == 1)
	    {
	    	printf("Channel Data successfully copied");

	    }
	    else
	    {
	    	printf("Channel Data copy unsuccessful");
	    }

	    VerifyDataCopy(status);


	    return 0;
}

/*
 * Copies source data to destination data.
 *
 * Parameters
 *  None
 *
 * Returns
 *  - COPY_SUCCESS   - Data verification success
 *  - COPY_FAILURE  - Data verification failed
 *
 */

static int CopySourceToDest (int* DestDataBuf, int* SrcDataBuf)
{
	uint32_t    i;
	int eResult;
	for(i = 0; i < MEMCOPY_BUF_SIZE; i++)
	{
		DestDataBuf[i] = SrcDataBuf[i];
		if(i == (MEMCOPY_BUF_SIZE-1))
		{
			eResult = COPY_SUCCESS;
		}
		else
		{
			eResult = COPY_FAIL;

		}
	}

	return eResult;

	}


/*
 * Verifies copy by comparing destination data with source.
 *
 * Parameters
 *  None
 *
 * Returns
 *  - COPY_SUCCESS   - Data verification success
 *  - COPY_FAILURE  - Data verification failed
 *
 */
static int VerifyDataCopy (int status)
{
    /* Loop variable */
    uint32_t i;

    /* Compare the destination data with source */
    for (i = 0; i < MEMCOPY_BUF_SIZE; i++)
    {
        /* IF (Destination data not same as source) */
        if (DestDataBuf[i] != SrcDataBuf[i])
        {
            /* Return error */
        	status = COPY_FAIL;
        }

        else
        {
        	status = COPY_SUCCESS;
        }

    }

    return (status);
}


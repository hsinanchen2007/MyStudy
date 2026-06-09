#include <string.h>
char * defangIPaddr(char * address)
{
    int Len = strlen(address);
    char *returnAddr = (char*)malloc(Len + 7);
   
    for(int i = 0; i <= Len; i++)
    {
        if((*address) != '.')
        {
            *returnAddr++ = *address++;
        }
        else
        {
            memcpy(returnAddr, "[.]", 4);
            returnAddr += 3;
            address++;
        }


    }


    return returnAddr - Len - 7;

}
click here

```
char * reverseWords(char * s){

    int len = strlen(s);

    char *retBuf = malloc(len + 2); // for '/0' and the potential extra blank 
    memset(retBuf, 0, len + 2);

    char *wordHead = s + len - 1;
    int wordLen = 0;

    while(wordHead >= s)
    {
        if(*wordHead == ' ')
        {
            if(wordLen > 0)
            {
                strncat(retBuf, wordHead + 1, wordLen); // append word
                strcat(retBuf, " ");                    // append blank

                wordLen = 0;
            }
        }
        else
        {
            wordLen++;
        }

        wordHead--;
    }

    if(wordLen > 0)
    {   // append the last word
        strncat(retBuf, wordHead + 1, wordLen);
    }
    else 
    {   
        int retLen = strlen(retBuf);

        if(retLen > 0 && retBuf[retLen - 1] == ' ')
        {   // remove the extra blank at tail
            retBuf[retLen - 1] = 0;
        }
    }

    return retBuf;
}

```

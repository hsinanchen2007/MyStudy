```

bool isDigit(char c)
{
    return c <= '9' && c >= '0';
}

void dfs(char *s, char **endAt, char *buf)
{
    char mutiBuf[10];
    memset(mutiBuf, 0, sizeof(mutiBuf));

    char *cur = s;

    while(*cur)
    {
        if(isDigit(*cur))
        {
            mutiBuf[strlen(mutiBuf)] = *cur;
        }
        else if(*cur == '[')
        {
            char *tmpBuf = malloc(1000);
            memset(tmpBuf, 0, 1000);

            int muti = atoi(mutiBuf);
            memset(mutiBuf, 0, sizeof(mutiBuf));

            dfs(cur + 1, endAt, tmpBuf);

            while(muti--)
            {
                strcat(buf, tmpBuf);
            }

            free(tmpBuf);
        
            cur = *endAt;
        }
        else if(*cur == ']')
        {
            *endAt = cur;
            return;
        }
        else
        {
            buf[strlen(buf)] = *cur;
        }

        cur++;
    }
}

char * decodeString(char * s){

    char *tmpBuf = malloc(2000);
    memset(tmpBuf, 0, 2000);

    char *endAt;
    dfs(s, &endAt, tmpBuf);

    return tmpBuf;
}







```

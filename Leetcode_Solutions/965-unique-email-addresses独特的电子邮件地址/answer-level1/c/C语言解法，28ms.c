思路比较笨，仅供用C的参考，C真的不好用
```
int numUniqueEmails(char ** emails, int emailsSize){
    int item = 0;
    char **record;
    record = (char **)malloc(sizeof(char *)*100);
    for(int i = 0; i < emailsSize; i++)
    {
        int length = strlen(emails[i]);
        int posJia = -1;
        int posAt = -1;
        for(int j = 0; j < length; j++)
        {
            if(emails[i][j] == '@')
            {
                posAt = j;
                break;
            }
            if(emails[i][j] == '+' && posJia == -1)
            {
                posJia = j;
            }
        }
        record[item] = (char *)malloc(sizeof(char)*101);

        int k = 0;
        for(int j = 0; j<length; j++)
        {
            if(posJia != -1)
            {
                if(j < posJia)
                {
                    if(emails[i][j] == '.')
                        continue;
                }
                else if(j >= posJia && j < posAt)
                {
                    continue;
                }
                record[item][k] = emails[i][j];
                k++;
            }
            else
            {
                if(emails[i][j] == '.'&& j < posAt)
                        continue;
                record[item][k] = emails[i][j];
                k++;
            }

        }
        record[item][k] = '\0';
        int flag2 = 0;
        for(int j = 0; j < item; j++)
        {
            int cmp = strcmp(record[j],record[item]);
            if(cmp == 0)
            {
                flag2 = 1;
                //record[item] = {'\0'};
                break;
            }
        }
        if(flag2 != 1)
        {
            item++;
        }
    }
    return item;
}


```


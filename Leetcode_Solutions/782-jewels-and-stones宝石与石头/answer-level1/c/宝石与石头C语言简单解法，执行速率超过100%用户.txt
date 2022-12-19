```
int numJewelsInStones(char * J, char * S)
{
    int returnNum = 0;
    char *temp = S;
    while(*J!='\0')
    {
        while(*S!='\0')
        {
            if(*S == *J)
            {
                returnNum++;
            }
            S++;
        }
        S = temp;
        J++;
    }
    return returnNum;
}
```

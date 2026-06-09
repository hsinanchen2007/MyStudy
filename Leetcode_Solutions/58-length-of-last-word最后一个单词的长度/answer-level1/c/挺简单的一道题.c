```
int lengthOfLastWord(char * s){
    int k=0,j=0;
    while(*s)
    {
        if(*s != ' ')
        {
            if(j==1)
            {
                k=0;
                j=0;
            }
            k++;
        }
        else if(*(s+1) !='\0')
        {
            j=1;
        }
        *s++;
    }
    return k;
    /*for(int i=0;s[i];i++)
    {
        if(s[i]!=' ')
        {
            if(j==1)
            {
                k=0;
                j=0;
            }
            k++;
        } 
        else if(s[i+1]!='\0')
        {
            j=1;
        }
    }
    return k;*/
}
```

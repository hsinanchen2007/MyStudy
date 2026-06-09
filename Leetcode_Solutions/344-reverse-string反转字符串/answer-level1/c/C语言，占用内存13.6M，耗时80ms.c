
```
void reverseString(char* s, int sSize){
    char tmpStr;
    if(s != NULL)
    {
        for(int i = 0; i < (sSize/2); i++)
        {
            printf("%c",s[i]);
         tmpStr = s[i];
         s[i] = s[sSize-i-1];   
         s[sSize-i-1] = tmpStr;
           //printf("%c",s[i]);
        }
    }
```
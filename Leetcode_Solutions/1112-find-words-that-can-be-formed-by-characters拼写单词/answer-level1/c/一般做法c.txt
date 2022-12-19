```
int countCharacters(char ** words, int wordsSize, char * chars){
    int res=0;
    int a[26]={0};
    for(int i=0;i<strlen(chars);i++)
    {
        a[chars[i]-'a']++;
    }
    for(int i=0;i<wordsSize;i++)
    {
        int b[26]={0};
        for(int j=0;j<strlen(words[i]);j++)
        {
            b[words[i][j]-'a']++;
        }
        int flag=1;
        for(int k=0;k<26;k++)
        {
            if(a[k]<b[k])
            {
                flag=0;
                break;
            }
        }
        if(flag){
            res+=strlen(words[i]);
        }
    }
    return res;
}
```

纯c面对字符串问题的无奈.....这道题感觉在考字符串排序
```
int cmp(const void* a,const void* b)
{
    return strcmp(*(char **)a,*(char**)b);
}
int uniqueMorseRepresentations(char ** words, int wordsSize){
    if(wordsSize==0)
    {
        return 0;
    }
    char hash[26][7]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    int i,j,k;
    int len;
    int lenh;
    int count=0;
    int cn=1;
    char **str=(char**)malloc(sizeof(char*)*wordsSize);
    for(i=0;i<wordsSize;i++)
    {
        str[i]=(char*)malloc(sizeof(char)*50);
    }
    for(i=0;i<wordsSize;i++)
    {
        len=strlen(words[i]);
        count=0;
        for(j=0;j<len;j++)
        {
            lenh=strlen(hash[words[i][j]-'a']);
            for(k=0;k<lenh;k++)
            {
                str[i][count++]=hash[words[i][j]-'a'][k];
            }
        }
        str[i][count]=0;
    }
    qsort(str,wordsSize,sizeof(str[0]),cmp);
    for(i=1;i<wordsSize;i++)
    {
        if(strcmp(str[i],str[i-1])!=0)
        {
            cn++;
        }
    }
    return cn;
}
```

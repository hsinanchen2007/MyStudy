```
int balancedStringSplit(char * s){
int flag=0;
int len=strlen(s);
int i;
int count=0;
for(i=0;i<len;i++)
{
    if(s[i]=='L')
    {
        flag++;
    }
    else
    {
        flag--;
    }
    if(i!=0&&flag==0)
    {
        count++;
    }
}
return count;
}
```

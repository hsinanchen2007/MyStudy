模拟二进制进位，特殊情况直接返回即可，思路较清晰
```
int numSteps(char * s){
    int len=strlen(s);
    int step=0;
    int i=len-1;
    int j;
    while(i>=1)
    {
        if(s[i]=='1')
        {
            step++;
            for(j=i-1;j>-1&&s[j]!='0';j--)
            {
                s[j]='0';
            }
            if(j==-1)
            {
                return step+strlen(s);
            }
            else
                s[j]='1';
            step++;
            s[i]='\0';
            i--;
        }
        else
        {
            step++;
            s[i]='\0';
            i--;
        }
    }
    return step;
}
```

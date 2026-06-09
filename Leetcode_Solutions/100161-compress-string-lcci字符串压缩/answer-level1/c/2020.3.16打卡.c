### 解题思路
主要就是一些细节，比如处理过程中要判断长度是否超过原字符串，比如大于10的数字要拆分成个位数字符

### 代码

```c
char *transNumToChar(int num,int *bitcnt) 
{
    int numToChar='1'-1;
    int cnt=0;
    char *cnum;
    cnum=(char*)malloc(5*sizeof(char));
    while(num>=10)
    {
        *(cnum+cnt)=(char)(num%10+numToChar);
        num/=10;
        cnt++;
    }
    *(cnum+cnt)=(char)(num%10+numToChar);
    *bitcnt=cnt+1;
    return cnum;
}

char* compressString(char* S){
    //printf("%c",49);    
    int len=strlen(S);
    if(len==0)
    {
        return S;
    }
    
    char *ans;
    ans=(char *)malloc((len+1)*sizeof(char));

    char cur=*S;
    int cnt=0;
    int ansLen=0;
    for(int i=0;i<len;i++)
    {
        if(*(S+i)==cur)
        {
            cnt++;
        }
        else //遇到不同的字符就处理前一个字符
        {
            ansLen++;
            if(ansLen>=len)
            {
                return S;
            }
            *(ans+ansLen-1)=cur;

            int bitcnt;
            char *ntc=transNumToChar(cnt,&bitcnt);
            for(int i=bitcnt-1;i>=0;i--) //数字分离成个位数顺序是倒着的
            {
                //printf("%d ",*(ntc+i));
                ansLen++;
                if(ansLen>=len)
                {
                    return S;
                }
                *(ans+ansLen-1)=*(ntc+i);
            }
            
            cur=*(S+i);
            cnt=1;
        }
    }

    //  对最后一位因为不存在下一个不同的字符，所以要在遍历完后单独计算一次
    ansLen++;
    if(ansLen>=len)
    {
        return S;
    }
    *(ans+ansLen-1)=cur;

    int bitcnt;
    char *ntc=transNumToChar(cnt,&bitcnt);
    for(int i=bitcnt-1;i>=0;i--)
    {
        //printf("%d ",*(ntc+i));
        ansLen++;
        if(ansLen>=len)
        {
            return S;
        }
        *(ans+ansLen-1)=*(ntc+i);
    }

    *(ans+ansLen)='\0';
    //printf("%d",ansLen);

    return ans;
}
```
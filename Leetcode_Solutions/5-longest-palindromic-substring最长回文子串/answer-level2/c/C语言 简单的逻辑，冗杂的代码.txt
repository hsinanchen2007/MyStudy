### 解题思路
逻辑很简单，但是相比于大佬们的冗杂了很多，效率也低了很多.

### 代码

```c
char * longestPalindrome(char * s)
{
    int len = strlen(s);
    if(len<=1)
        return s;
    int i,j,maxsize=0,startnum=0,endnum=0,cout=0,tempmax=0;
    for(i=1;i<len;i++)
    {
        // 这是为了判断如果存在连续两个数相等，即abba型的
        if(s[i]==s[i-1])
        {
            for(j=1;i-1-j>=0&&i+j<len;j++)
            {
                if(s[i-1-j]==s[i+j])
                {
                    cout=(i+j)-(i-j-1);
                    tempmax=cout+1;
                }
                else
                {
                    break;
                }
            }
            // 如果除了最初的一对再不存在对称相等的情况，类似caab，或者aa型
            if(tempmax==0)
            {
                tempmax=2;
                startnum=i-1;
                endnum=i;
                maxsize=tempmax;
            }
            if(tempmax>maxsize)
            {
                startnum=i-tempmax/2;
                endnum=i+tempmax/2;
                maxsize=tempmax;
            }
        }
        // 这是为了判断abcbd型的
        for(j=1;i-j>=0&&i+j<len;j++)
        {
            if(s[i-j]==s[i+j])
            {
                cout=(i+j)-(i-j);
                tempmax=cout+1;
            }
            // 这里的break是为了保证如果有一次不相等就退出循环，也是出错之后才想到，防止类似abcda型
            else
            {
                break;
            }
        }
        if(tempmax>maxsize)
        {
            startnum=i-(tempmax-1)/2;
            endnum=i+(tempmax-1)/2;
            maxsize=tempmax;
        }

    }
    // 如果不存在回文子串，如：abcd，返回第一个元素即可
    if(maxsize==0)
    {
        char * returnStr = (char *)malloc(sizeof(char)*2);
        returnStr[1]='\0';
        returnStr[0]=s[0];
        return returnStr;
    }
    char * returnStr = (char *)malloc(sizeof(char)*(maxsize+1));
    returnStr[maxsize]='\0';
    for(i=0;i<maxsize;i++)
    {
        returnStr[i]=s[startnum+i];
    }
    return returnStr;
}
```
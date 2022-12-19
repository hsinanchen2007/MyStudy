### 解题思路
测试用例 "" ""和"aa" ""和"aaa" "aaaa" 要注意考虑

### 代码

```c
int strStr(char * haystack, char * needle){
    //算上'\0'的元素个数
    int haystackLength=0,needleLength=0;
    while(haystack[haystackLength++]!='\0');
    while(needle[needleLength++]!='\0');

    if(needleLength==0||*needle=='\0')return 0;
    if(needleLength>haystackLength)return -1;

    int set=0;
    while(set+needleLength<=haystackLength)
    {
        if(haystack[set]==needle[0])
        {
            int flag=1;
            for(int iter=0;iter<needleLength-1;++iter)
                if(needle[iter]!=haystack[set+iter])
                {
                    flag=0;
                    break;
                }
            if(flag)
                return set;                
        }
        ++set;
    }
    return -1;
}
```
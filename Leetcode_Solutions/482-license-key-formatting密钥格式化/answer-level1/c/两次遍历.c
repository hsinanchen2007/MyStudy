第一遍遍历，对所有有效字符计数cnt，并在原数组中去除'-'（可以减少第二次遍历的操作次数）
然后计算出第一组有（cnt除以K的余数=n）个字符
第二遍遍历，第一次赋值n个字符后加'-'，以后每K个加'-'

执行用时 :
4 ms
, 在所有 c 提交中击败了
99.25%
的用户
内存消耗 :
7.9 MB
, 在所有 c 提交中击败了
90.91%
的用户

```
char * licenseKeyFormatting(char * S, int K){
    char *p;
    char *p1=S;
    char *p2=S;
    int n=0;
    int len=0;
    while(*p1 != '\0')
    {
        if(*p1 != '-')
        {
            *p2++ = *p1;
            len++;
        }
        p1++;
    }
    *p2='\0';
    n=len%K;
    n=n?(K-n):0;
    p=malloc(len+len/K+1);
    p2=p;
    p1=S;
    while(*p1 != '\0')
    {
        if(n < K)
        {
            *p2 = ((*p1 >= 'a') ? (*p1 - 32) : *p1);
            n++;
        }
        else
        {
            *p2++ ='-';
            *p2 = ((*p1 >= 'a') ? (*p1 - 32) : *p1);
            n=1;
        }
        p2++;
        p1++;
    }
    *p2='\0';
    return p;
}
```

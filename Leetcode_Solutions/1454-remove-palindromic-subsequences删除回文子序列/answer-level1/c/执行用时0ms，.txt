### 解题思路
主要读题，搞明白回文 子序列的意思，题目说只有a，b,所以最大返回2

### 代码

```c
int removePalindromeSub(char * s){
int n=0;
    n=strlen(s);
    if(n==0)
        return 0;
   int i=0;
    for(i=0;i<n-i;i++)
    {
        if(s[i]!=s[n-i-1])
        {   
            return 2;
        }
    }
    return 1;
}
```
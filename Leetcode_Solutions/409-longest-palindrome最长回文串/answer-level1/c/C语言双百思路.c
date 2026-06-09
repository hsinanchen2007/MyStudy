### 解题思路
执行用时 :
0 ms
, 在所有 C 提交中击败了
100.00%
的用户
内存消耗 :
5.3 MB
, 在所有 C 提交中击败了
100.00%
的用户

假设并不知道字母在asc2表中的位置，可以采用如下方法

### 代码

```c
int longestPalindrome(char * s){
    int a[26]={0},A[26]={0},i,m,sum=0;
    char *p=s;
    while(*p!='\0')
    {
        if(*p>='a'&&*p<='z')
        {
            m=*p-'a';
            a[m]++;
        }
        else if(*p>='A'&&*p<='Z')
        {
            m=*p-'A';
            A[m]++;
        }
        p++;
    }
    m=0;
    for(i=0;i<26;i++)
    {
        if(a[i]%2!=0)
        {
            sum+=a[i]-1;
            m=1;
        }
        else sum+=a[i];
        if(A[i]%2!=0)
        {
            sum+=A[i]-1;
            m=1;
        }
        else sum+=A[i];
    }
    sum+=m;
    return sum;
}
```
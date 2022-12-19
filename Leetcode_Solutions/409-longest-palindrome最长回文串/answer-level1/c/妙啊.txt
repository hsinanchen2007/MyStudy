### 解题思路
此处撰写解题思路

### 代码

```c
int longestPalindrome(char * s){
    int c[128]={0}, ret=0;    //注意构造初始化
    for(int i=0;i<strlen(s);i++)
    {
        c[s[i]]++;
    }

    for(int i=0;i<128;i++)
        ret+=c[i]-c[i]%2;

    return ret+(ret!=strlen(s));       //这一步则是考虑了 奇数个＋1 偶数个排除的情形 

}

```
### 解题思路
#如果每个字母的次数都为偶数，则一定是回文。
#如果有字母次数为奇数，统计为奇数的字母个数。用总长度减去统计个数+1；

### 代码

```c
int doto(int * num){
    int count=0;
    for(int i=0;i<26;i++)
       if(num[i]%2==1)count++;
    return count;
}
int longestPalindrome(char * s){
    int n=strlen(s);
    int numMin[26]={0},numMax[26]={0};
    while(*s!='\0'){
        if(*s>='a')numMin[*s-'a']++;
        else numMax[*s-'A']++;
        s++;
    }
    int a=(doto(numMax)+doto(numMin));
    int tep=(a==0)?n:(n-a+1);
    return tep;
}
```
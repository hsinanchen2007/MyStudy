### 解题思路
26个字母*大小写，申请52个int空间就行了。
返回的时候，成对的字符总数比总数小，就随便再拿一个放对称轴就行了，返回sum+1
### 代码

```c
int longestPalindrome(char * s){

    int times[52]={0};
    int length=0;
    while(*s!='\0')
    {
        if(*s<'a')
            ++times[*s-'A'];
        else
            ++times[*s-'a'+26];
        ++length;++s;
    }

    
    int sum=0;
    for(int i=0;i<52;++i)
        sum+=2*(times[i]/2);

    return length>sum?sum+1:sum;
}
```
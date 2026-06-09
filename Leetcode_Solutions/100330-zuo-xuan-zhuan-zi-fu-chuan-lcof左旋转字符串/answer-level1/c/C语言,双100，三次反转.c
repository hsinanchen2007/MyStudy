### 解题思路
三次反转即可，时间复杂度O（N），空间复杂度O(1)

### 代码

```c
char* reverseLeftWords(char* s, int n){
    reverse(s,0,n-1);
    reverse(s,n,strlen(s)-1);
    reverse(s,0,strlen(s)-1);
    return s;
}

void reverse(char*s,int from,int to)
{
    char temp;
    while(from<to)
    {
        temp=s[from];
        s[from++]=s[to];
        s[to--]=temp;
    }
}
```
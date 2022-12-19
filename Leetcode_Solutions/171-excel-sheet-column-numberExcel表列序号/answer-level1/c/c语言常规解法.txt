### 解题思路
从后往前加。

### 代码

```c
int titleToNumber(char * s){
    int len=strlen(s);
    int cnt=0;
    int cmt=0;
    for(int i=len-1;i>=0;i--)
    {
       cnt=cnt+(s[i]-64)*(pow(26,cmt));
       cmt++;
    }
    return cnt;
}
```
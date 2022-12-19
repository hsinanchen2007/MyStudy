### 解题思路
memcmp

### 代码

```c
int strStr(char * haystack, char * needle){
    int l_n=strlen(needle);
    int l_h=strlen(haystack);
    if(l_n==0&&l_h==0)
        return 0;
    for(int i=0;i<=l_h-l_n;i++){
        if(memcmp(&haystack[i],needle,l_n)==0)//比较两个字符串的前l_n位
            return i;
    }
    return -1;
}
```
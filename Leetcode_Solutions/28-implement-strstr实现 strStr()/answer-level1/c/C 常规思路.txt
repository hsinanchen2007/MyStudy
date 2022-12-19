### 解题思路
此处撰写解题思路

### 代码

```c
int strStr(char * haystack, char * needle){
    if(*needle==NULL) return 0;
    int i=0;
    while(haystack[i]){
        if(haystack[i]==needle[0]){
            int j=1;                              //同时做haystack和needle的比较指针
            while(needle[j]){
                if(haystack[i+j]!=needle[j]) break;
                j++;
            }
            if(!needle[j]) return i;              //遍历完needle字符则返回当前i的值
        }
        i++;
    }
    return -1;
}
```
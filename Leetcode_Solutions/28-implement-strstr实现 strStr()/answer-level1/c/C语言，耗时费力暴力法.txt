### 解题思路
双循环

### 代码

```c
int strStr(char * haystack, char * needle){
    int len1=strlen(haystack);
    int len2=strlen(needle);
    int flag=0;
    if(len1==0&&len2==0){
        return 0;
    }
    for(int i=0;i<len1;i++){
        flag=0;
        for(int j=0;j<len2;j++){
            if(haystack[i+j]!=needle[j]){
                flag=1;
                break;
            }
        }
        if(flag==0){
            return i;
        }
    }
    return -1;
}
```
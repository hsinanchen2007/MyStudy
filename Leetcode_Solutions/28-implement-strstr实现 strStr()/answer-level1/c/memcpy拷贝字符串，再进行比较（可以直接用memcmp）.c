### 解题思路
此处撰写解题思路
使用memcpy函数，从第i个字符开始，比较i后面与needle长度相同的字符串与needle是否相等。
### 代码

```c
int strStr(char * haystack, char * needle){

    int l1=strlen(haystack);
    int l2=strlen(needle);
    if(l2==0)return 0;
    char* tmp=(char*)malloc((l2+1)*sizeof(char));
    int i;
    for(i=0;i<l1-l2+1;i++){
        memcpy(tmp,haystack+i,(l2)*sizeof(char));
        tmp[l2]='\0';
        if(strcmp(tmp,needle)==0)
            return (i);
    }
    return -1;
}
```
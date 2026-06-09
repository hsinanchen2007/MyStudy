### 解题思路
回溯。另有一种KMP，比较复杂

### 代码

```c
int strStr(char * haystack, char * needle){
    int i,j;
    if(*needle=='\0')return 0;
    for(i=0,j=0;haystack[i]!='\0';i++,j++){
        if(haystack[i]!=needle[j]){//不匹配回溯主串指针
            i=i-j;//主串回去j个位置
            j=-1;//因为后面会加，所以这里设置成-1,意思时回到字串最开始
        }else if(needle[j+1]=='\0')return i-j;//如果匹配成功，且下一个字串字符是'\0'，则成功
    }
    return -1;
}
```
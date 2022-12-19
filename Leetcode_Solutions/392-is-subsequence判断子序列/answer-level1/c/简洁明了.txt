### 解题思路
简洁明了

### 代码

```c
int isSubsequence(char * s, char * t){
    while(true){
        if(!*s) return true;
        if(!*t) return false;
        if(*t++ == *s) s++;
    }
}
```
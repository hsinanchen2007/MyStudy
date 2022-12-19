### 解题思路
此处撰写解题思路

### 代码

```c
bool isSubsequence(char * s, char * t){
    while(*s && *t){
        if(*s==*t){
            s++;
        }
        t++;
    }
    if(*s=='\0'){
        return true;
    }
    return false;
}
```
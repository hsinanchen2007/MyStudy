### 解题思路
 树上qi个猴

### 代码
地上一个猴子
```c
int findLUSlength(char * a, char * b){
    if(NULL == a || NULL == b){
        return 0;
    }

    if(strlen(a) == strlen(b) && 0 == strcmp(a,b)){
        return -1;
    }

    return strlen(a) > strlen(b)?strlen(a):strlen(b);
}
```
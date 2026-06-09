### 解题思路

都为了一场没有硝烟的战场。

### 代码

```c
int titleToNumber(char * s){
    if(strlen(s) <= 0){
        return -1;
    }
    int num = 0  , idx = 0;
    for(int i = strlen(s) - 1 ; i >= 0 ; i--){
        num += pow(26,idx) * (s[i] - 'A' + 1); 
        idx++;
    }
    return num;
}
```
### 解题思路
首先能够想到的就是判定条件可以分成
1. 数字  str[i] >= '0' && str[i] <= '9'
2. +与-  str[i] == '+' || str[i] == '-' && strlen(tmp) == 0
3. 空格  str[i] == ' ' && strlen(tmp) == 0
4. 其它  
四种情况。每一种情况的条件再详细讨论；
可能一开始写部分条件会漏掉，需要找到不同的例子来完善判断。

### 代码

```c
int myAtoi(char * str){
    int n = strlen(str);
    char *tmp = (char *)malloc(sizeof(char)*(n + 1));
    memset(tmp, '\0', sizeof(char)*(n + 1));
    int i = 0, k = 0;
    for(int i = 0 ; i < n; i++){
        if(str[i] >= '0' && str[i] <= '9'){
            tmp[k++] = str[i];
        } 
        else if(str[i] == '+' || str[i] == '-' && strlen(tmp) == 0){
            tmp[k++] = str[i];
        } 
        else if(str[i] == ' ' && strlen(tmp) == 0){
            continue;
        }
        else{
            break;
        }
    }
    tmp[k] = '\0';
    long long num = atoll(tmp);
    if(num > INT_MAX ) return INT_MAX;
    else if(num < INT_MIN) return INT_MIN;
    else return num;
}
```
### 解题思路
如题目所说，遍历字符串，对+和-以及边界条件要仔细判断

### 代码

```c
int myAtoi(char * str){
    if(strlen(str) == 0)
        return 0;
    int i, j, result = 0, numi;
    for(i = 0;i < strlen(str) && str[i] == ' ';i ++);
    if(str[i] == '+' || isdigit(str[i])){
        if(str[i] == '+')
            i ++;
        for(;i < strlen(str) && isdigit(str[i]);i ++){
            numi = str[i] - '0';
            if(result == 0)
                result = numi;
            else if(INT_MAX / result > 10 || (INT_MAX / result == 10 && INT_MAX - (result * 10) > numi))
                result = result * 10 + numi;
            else{
                result = INT_MAX;
                break;
            }
        }
    }
    else if(str[i] == '-')
        for(i ++;i < strlen(str) && isdigit(str[i]);i ++){
            numi = str[i] - '0';
            if(result == 0)
                result = -numi;
            else if(result == -1 || INT_MIN / result > 10 || (INT_MIN / result == 10 && INT_MIN - (result * 10) < -numi))
                result = result * 10 - numi;
            else{
                result = INT_MIN;
                break;
            }
        }
    return result;
}
```
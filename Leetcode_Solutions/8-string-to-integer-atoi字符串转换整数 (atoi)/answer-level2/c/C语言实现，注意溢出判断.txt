### 解题思路
此处撰写解题思路

### 代码

```c
int myAtoi(char * str){
    int i = 0;
    int res = 0;
    bool negative = false;
    while (str[i] != '\0' && str[i] == ' ') {
        i++;
    }
    if (str[i] == '\0') {
        return 0;
    }
    else if (str[i] == '-') {
        negative = true;
        i++;
    }
    else if (str[i] == '+') {
        i++;
    }
    if (str[i] < '0' || str[i] > '9') {
        return 0;
    }
    
    while (str[i] != '\0') {
        int num = str[i] - '0';
        if (num < 0 || num > 9) {
            break;
        }
        //printf("before=%d %d\n", i, num);
        if (res > (INT_MAX - num) / 10) {
            return negative == true ? INT_MIN : INT_MAX;
        }
        else {
            res = res * 10 + num;
            i++;
        }
        //printf("%d %d\n", i, res);
    }
    res = (negative == true ? 0 - res : res);
    return res;
}
```
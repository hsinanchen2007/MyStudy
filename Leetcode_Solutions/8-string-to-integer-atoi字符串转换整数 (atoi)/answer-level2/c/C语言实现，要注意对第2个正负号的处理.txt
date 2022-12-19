### 解题思路
此处撰写解题思路

### 代码

```c
int myAtoi(char * str){
    if (str == NULL) return 0;
    int i = 0;
    int res = 0;
    bool negative = false;
    bool disableblank = false;
    bool disablesign = false;
    while (str[i] != '\0') {
        if (str[i] == ' ' && disableblank == false) {
            i++;
            continue;
        }
        int num = str[i] - '0';
        //printf("before=%d %d\n", i, num);
        if (num < 0 || num > 9) {  //如果第一个非空字符不是数字或+-，则退出
            if ((str[i] == '+' || str[i] == '-') && disablesign == false) {}
            else
                break;
        }
        if (str[i] == '-') {
            disableblank = true;
            disablesign = true;
            negative = true;
            i++;
            continue;
        }
        if (str[i] == '+') {
            disableblank = true;
            disablesign = true;
            i++;
            continue;
        }
        if (res > (INT_MAX - num) / 10) {
            return negative == true ? INT_MIN : INT_MAX;
        }
        else {
            disableblank = true;
            disablesign = true;
            res = res * 10 + num;
            i++;
        }
        //printf("%d %d\n", i, res);
    }
    res = (negative == true ? 0 - res : res);
    return res;
}
```
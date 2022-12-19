```
int isspecial(char c)
{
    if ((c >= '0' && c <= '9') || c == '-' || c == '+') {
        return 1;
    }
    return 0;
}

int myAtoi(char * str){
    if (str == NULL) {
        return 0;
    }
    int i;
    int len = strlen(str);

    for (i = 0; i < len; i++) { //处理开头是空格的情况
        if (str[i] != ' ') {
            break;
        }
    }
    if (!isspecial(str[i])) {  //处理完空格后判断首字符
        return 0;
    }

    int isMinus = 0;
    if (str[i] == '-') { //首字符为'-'或'+'数字有效位即向后偏移一位
        isMinus = 1;
        i++;
    } else if (str[i] == '+') {
        i++;
    }
    long res = 0;
    while(isdigit(str[i]) && str[i] != '\0') {
        if (isMinus == 1) {
            res = res * 10 - (str[i] - '0'); //负数处理方式
        } else {
            res = res * 10 + (str[i] - '0'); //非负数处理方式
        }
        if (res > INT_MAX) {
            return INT_MAX;
        }
        if (res < INT_MIN) {
            return INT_MIN;
        }
        i++;
    }
    return (int)res;
}
```

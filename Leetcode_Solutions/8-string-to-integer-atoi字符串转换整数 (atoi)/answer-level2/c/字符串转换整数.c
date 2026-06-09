### 解题思路
这算是面向测试结果编程吧！！
哈哈😁

### 代码

```c

long myAtoiDetail(char* str, int start, int sign) {
    long result = 0;
    for (start; str[start]; start++) {
        if (str[start]-'0' > 9 || str[start]-'0' < 0) {
            return result;
        }
        result = result*10 + (str[start] - '0');
        if (sign == 1 && result > 2147483647) {
            return 2147483647;
        } else if (sign == -1 && result > 2147483648){
            return 2147483648;
        }
    }
    return result;
}

int myAtoi(char * str){
    long result = 0;

    int start = 0;
    for(start = 0; str[start]==' '; start++);
    int sign = 1;
    if(str[start] == '+' || str[start] == '-') {
        sign = (str[start] == '-') ? -1 :1;
        start++;
    }
    result = myAtoiDetail(str, start, sign);
    return result*sign;
}

```
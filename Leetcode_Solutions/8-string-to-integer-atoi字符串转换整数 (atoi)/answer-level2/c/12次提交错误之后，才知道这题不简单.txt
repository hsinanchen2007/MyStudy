### 解题思路

本道题目最考验到就是审题能力，代码至少需要考虑以下情况

1. 前面不仅会会有-,还有会有+
2. 即便是`long long`，也有可能出现更大的数字，因此在出现比INT_MAX大的数字后，可以直接跳出循环。
3. 非空字符不能是字母，
4. 处理数字的时候，如果遇到了"."可以直接跳出循环了
5. 处理数字的时候，如果遇到了字母，也可以跳出循环了。
6. 跳出循环后，如果值大于最大值，返回最大值，否则，还需要比较是否小于最小值，

### 代码

```c
int myAtoi(char * str){

    long res = 0;
    int flag = 0;
    int str_size = strlen(str);
    //丢弃空格
    int i = 0;
    while ( str[i] == ' '){
        i++;
    }
    //非空字符后第一位
    if (str[i] == '-') {
        flag = 1;
        i = i + 1;
    } else if (str[i] == '+'){
        i = i + 1;
    } else if (str[i] >= '0' && str[i] <='9') {
    } else {
        return 0;
    }

    for (; i < str_size; i++){

        if (str[i] < '0' ||  str[i] > '9') break;
        if (str[i] >= '0' && str[i] <= '9') {
            if (res >= INT_MAX) break;
            res = res * 10 + (str[i] - '0');
        } 
    }
    if (flag == 1) res = -res;
    if (res < INT_MIN) {
        return INT_MIN;
    } 
    if (res > INT_MAX){
        return INT_MAX ;
    }
    return res;

}
```
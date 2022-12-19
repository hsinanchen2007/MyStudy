C语言实现
```C []
char * convertToBase7(int num){
    char *res = (char*)malloc(13 * sizeof(char));
    memset(res, 0, 13 * sizeof(char));
    int i, index = 0;
    int tmp = num >= 0 ? num : - num;
    while (tmp) {
        res[index++] = tmp % 7 + '0';
        tmp /= 7;
    }
    if (num < 0) res[index++] = '-';
    if (0 == num) res[index++] = '0';
    for (i = 0; i < index / 2; ++i) {
        tmp = res[i];
        res[i] = res[index - 1 - i];
        res[index - 1- i] = tmp;
    }
    return res;
}
```

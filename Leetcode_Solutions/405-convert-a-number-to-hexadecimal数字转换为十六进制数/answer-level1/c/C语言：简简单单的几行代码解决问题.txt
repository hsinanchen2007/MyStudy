如果为负数，只要用 (unsigned int)num 就可以变为补码


```
char * toHex(int num){
    char *ret_str = (char*)malloc(33);
    if (num == 0) {
        ret_str[0] = '0';
        ret_str[1] = '\0';
    }else if (num > 0) positive(ret_str, num);//正数
    else               positive(ret_str, (unsigned int)num);//负数
    return ret_str;
}
int positive(char *str, unsigned int num)
{
    int i = 0;

    while (num > 0) {
        if (num % 16 > 9) str[i++] = (num % 16) + 87;
        else              str[i++] = (num % 16) + '0';
        num /= 16;
    }
    str[i] = '\0';
    int j = i-1;
    i = 0;
    while (i < j) {
        str[i]   ^= str[j];
        str[j]   ^= str[i];
        str[i++] ^= str[j--];
    }

    return 0;
}
```

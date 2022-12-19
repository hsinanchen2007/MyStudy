
```
char * convertToBase7(int num){
    char *s = (char *)malloc(1024);
    if (num >= 0) fun(s, num);
    else {
        s[0] = '-';
        fun(s+1, -num);
    }
    return s;
}
int fun (char *input_str, int input_num)
{
    if (input_num == 0) {
        input_str[0] = '0';
        input_str[1] = '\0';
        return 0;
    }
    int top = 0;
    while (input_num > 0) {
        input_str[top++] = input_num % 7 + '0';
        input_num /= 7;
    }
    input_str[top--] = '\0';
    int i = 0;
    while (i < top) {
        input_str[i]   ^= input_str[top];
        input_str[top] ^= input_str[i];
        input_str[i++] ^= input_str[top--];
    }
    return input_str;
}
```

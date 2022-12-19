涉及到字符串库的一些用法

#### 判断类

- isupper(char c) // 判断是否为大写字母
- islower(char c) // 判断是否为小写字母
- isdigit(char c) // 判断字符是否为数字

#### 转化类

- tolower(char c) // 大写字母转小写
- toupper(char c) // 小写字母转大写

#### 字符串操作

- strcat(char *dst, const char *src) // src 添加到 dst 末尾，会自动添加'\0'
- strcpy(char *dst, const char *src) // 把从src地址开始且含有\0结束符的字符串复制到以dest开始的

### 题解

先判断是邮件还是电话，按照要求转化即可。另外输入已经保证符合要求，所以函数内不再做合法性判断。
```C
char *cover_email(char *s)
{
    int s_len = strlen(s);
    int res_len = s_len + 7;
    char *res = (char *)malloc(sizeof(char) * res_len);
    memset(res, 0, res_len);
    res[0] = isupper(s[0]) ? tolower(s[0]) : s[0];
    for (int i = 1; i < 6; i++) {
        res[i] = '*';
    }
    int at_i = 0;
    while (s[at_i] != '@' && s[at_i] != '\0') {
        at_i++;
    }
    if (s[at_i] == '@') {
        res[6] = isupper(s[at_i - 1]) ? tolower(s[at_i - 1]) : s[at_i - 1];
    }
    strncat(res, s + at_i, s_len - at_i);
    for (int i = 7; i < strlen(res); i++) {
        res[i] = isupper(res[i]) ? tolower(res[i]) : res[i];
    }
    return res;
}

char *cover_diag(const char *S)
{
    int i = 0;
    int len = strlen(S);
    char *digits = (char *)malloc(sizeof(char) * (len + 3));
    memset(digits, 0, len + 3);
    char *res = (char *)malloc(sizeof(char) * (len + 3));
    memset(res, 0, len + 3);
    int digits_i = 0;
    while (S[i] != '\0') {
        if (isdigit(S[i])) {
            digits[digits_i++] = S[i];
        }
        i++;
    }
    // 全是国内号码
    if (digits_i == 10) {
        strcpy(res, "***-***-");
        for (int i = 6; i < digits_i; i++) {
            res[8 + i - 6] = digits[i];
        }
        res[12] = '\0';
        return res;
    }
    int inter_digit = digits_i - 10;
    res[0] = '+';
    for (int i = 0; i < inter_digit; i++) {
        res[i + 1] = '*';
    }
    res[inter_digit + 1] = '-';
    strcat(res, "***-***-");
    len = strlen(res);
    for (int i = digits_i - 4; i < digits_i; i++) {
        res[len + i - digits_i + 4] = digits[i];
    }
    return res;
}

char *maskPII(char *S)
{
    char *isEmal = strchr(S, '@');
    if (isEmal != 0) {
        return cover_email(S);
    }
    return cover_diag(S);
}

```
下面的注释比较详细了，就是从左到右找']'， 之后处理每一个解码

```
#include <stdio.h>
#include <malloc.h>
#include <mem.h>
#include <ctype.h>

#define  MAX_LEN 10240

char* decodeString(char* s) {
    char *result = malloc(sizeof(char) * MAX_LEN);
    memset(result, '\0', MAX_LEN);
    char tmp[MAX_LEN] = {'\0'};
    char str[MAX_LEN] = {'\0'};
    strncpy(tmp + 1, s, strlen(s)); // 为了方便后边循环，不能直接用tmp
    char * p = tmp + 1;
    char *c_begin; // 需要展开的字符串的起始位置
    char *n_p; // 查找数字指针
    int num; // 需要展开的数字

    while (*p != '\0') {
        if (*p == ']') {
            *p = '\0';
            int last_len = strlen(p + 1);
            c_begin = p - 1;

            // 字符串计算和位置
            while (*c_begin != '[') {
                c_begin--;
            }
            *c_begin = '\0';
            int str_len = strlen(c_begin + 1);
            strncpy(str, c_begin + 1, str_len); // 将字符串备份

            // 数字计算和指针位置
            n_p = c_begin - 1;
            while (isdigit(*n_p)) {
                n_p--;
            }
            num = atoi(n_p + 1);

            memmove(n_p + 1 + num * str_len, p + 1, last_len); // 后面的字符串后移
            // 字符串展开
            for (int i = 0; i < num; i++) {
                memmove(n_p + 1 + i * str_len, str, str_len);
            }
            p = n_p + num * str_len;

            memset(n_p + 1 + num * str_len + last_len, '\0', (tmp + MAX_LEN) - (n_p + 1 + num * str_len + last_len)); // 脏字符清理
            memset(str, '\0', MAX_LEN); // 清空前面缓存的字符串
        }
        p++;
    }
    strncpy(result, tmp + 1, strlen(tmp + 1));
    return result;
}
```

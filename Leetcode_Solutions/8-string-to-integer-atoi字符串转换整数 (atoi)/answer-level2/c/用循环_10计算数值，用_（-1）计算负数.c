### 解题思路
此处撰写解题思路

### 代码

```c
bool Valid(const char ch)
{
    if (ch != '+' && ch != '-' && !isdigit(ch)) {
        return false;
    }
    return true;
}

int myAtoi(char * str){
    
    int len = strlen(str);
    int i;
    for (i = 0; i < len; i++) {
        if (!isspace(str[i])) {
            break;
        }
    }
    char *src = &str[i];
    if (!Valid(src[0])) {
        return 0;
    }
    len = strlen(src);

    int flag = src[0] == '-' ? -1 : 1;

    long long ret = 0;
    i = !isdigit(src[0]) ? 1 : 0;
    for (; i < len && isdigit(src[i]); i++) {
        ret = ret * 10 + (src[i] - '0');
        if (ret > INT_MAX) {
            break;
        }
    }
    ret *= flag;
    ret = ret > INT_MAX ? INT_MAX : ret;
    ret = ret < INT_MIN ? INT_MIN : ret;
    return (int)ret;
}
```
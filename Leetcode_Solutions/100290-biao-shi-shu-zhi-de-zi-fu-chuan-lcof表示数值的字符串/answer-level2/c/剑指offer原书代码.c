代码主题是原书的，主要纪念一下leetcodeleetcode这个测试用例，前空格后空格坑了我好几分钟时间，厉害厉害。
```
bool scanUnsignedInt(char **ps) {
    const char *before = *ps;

    while (**ps != '\0' && **ps >= '0' && **ps <= '9') {
        ++(*ps);
    }

    return *ps > before;
}
bool scanInt(char **s) {
    if (**s == '+' || **s == '-') 
        ++(*s);
    return scanUnsignedInt(s);
}
bool isNumber(char* s){
    if (s == NULL) return false;
    while (*s == ' ') {
        ++s;
    }
    bool numeric = scanInt(&s);

    if (*s == '.') {
        ++s;

        numeric = scanUnsignedInt(&s) || numeric;
    }

    if (*s == 'e' || *s == 'E') {
        ++s;

        numeric = numeric && scanInt(&s);
    }
    while (*s == ' ')
        ++s;
    return numeric && *s == '\0';
}
```

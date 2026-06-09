# 搞清楚条件即可，存在A > 1 or 三个联系的L即为false。掉到理解题的坑里了，认为LLALL也是false。
```
/*bool checkRecord(char * s){
    int absent = 0;
    int late = 0;
    while(*s != '\0') {
        if (*s == 'A') {
            absent++;
        }
        if (*s == 'L') {
            late++;
        }else {
            late = 0;
        }
        if (absent > 1 || late > 2) {
            return false;
        }
        s++;
    }
    return true;
}*/
bool checkRecord(char * s){
    if (strstr(s,"LLL") != NULL) {
        return false;
    }
    int absent = 0;
    while(*s != '\0') {
        if (*s == 'A') {
            absent++;
        }
        if (absent > 1) {
            return false;
        }
        s++;
    }
    return true;
}

```

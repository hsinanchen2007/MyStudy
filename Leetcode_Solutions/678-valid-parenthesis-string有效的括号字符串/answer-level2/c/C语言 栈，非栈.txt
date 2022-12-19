两个计数器，一个存左括号最小可能值，一个存最大可能值
遇到左括号，两个可能值分别加一；
遇到右括号，分别减一，但是最小值不能为0；
遇到星号，最大值加一，最小值减一，且不小于0；
如果过程中，最大值小于0了说明右括号多了，返回false；
如果最后结果，最小值最后为0说明可以配对成功返回true；
```
#define MAX(x, y) x > y? x : y
bool checkValidString(char * s){
    int len = strlen(s);
    if (len == 0) {
        return true;
    }
    int min = 0, max = 0;
    for (int k = 0; k < len; k++) {
        if (s[k] == '(') {
            min++;
            max++;
        } else if (s[k] == ')') {
            min = MAX(min - 1,0);
            max--;
        } else if (s[k] == '*') {
            min = MAX(min - 1,0);
            max++;
        } else {
            printf("error input %s", s[k]);
        }

        if ( max < 0) {
            return false;
        }
    }
    if (min == 0) {
        return true;
    }
    return false;
}
```


### 解题思路
没啥特别的思路。

### 代码

```c

int find1stNonSpace(char *str, int begin) {
    for (int i = begin; i < strlen(str); i++) {
        if (str[i] != ' ') return i;
    }

    return -1;
}

inline bool isDigit(char *str, int i) {
    return (str[i] >= '0' && str[i] <= '9');
}

inline bool isSign(char *str, int i) {
    return (str[i] == '-') || (str[i] == '+');
}

int findEndDigit(char *str, int begin) {
    int i;
    for (i = begin; i < strlen(str); i++) {
        if (!isDigit(str, i)) break;
    }

    return i-1;
}

#define INT_MAX (pow(2,31)-1)
#define INT_MIN (0-pow(2,31))

int convertNum(char *str, int begin, int end, int sign) {
    int ans = 0;
    for (int i = begin; i <= end; i++) {
        if (ans > INT_MAX/10 || ans < INT_MIN/10) return sign==1 ? INT_MAX : INT_MIN;
        ans = ans * 10;
        int num = sign==1 ? (str[i]-'0') : (0 - (str[i]-'0'));
        if (ans > INT_MAX - num || ans < INT_MIN - num) return sign==1 ? INT_MAX : INT_MIN;
        ans = ans + num;
    }

    return ans;
}

int myAtoi(char * str){
    if (!str) return 0;
    if (strlen(str) == 0) return 0;
    
    int begin = find1stNonSpace(str, 0);
    if (begin == -1) return  0;

    if (!isDigit(str, begin) && !isSign(str, begin)) return 0;

    int sign = 1;
    if (isSign(str, begin)) {
        sign = str[begin] == '-' ? -1 : 1;
        begin++;
    }

    int end = findEndDigit(str, begin);
    int num = convertNum(str, begin, end, sign);
    return num;
}
```
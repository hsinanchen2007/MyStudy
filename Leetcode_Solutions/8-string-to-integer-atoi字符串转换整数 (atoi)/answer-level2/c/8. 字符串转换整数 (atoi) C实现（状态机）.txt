### 解题思路
此处撰写解题思路

### 代码

```c
#define START 0
#define SIGNED 1
#define NUMBER 2
#define END 3
#define INT_MIN -2147483648
#define INT_MAX 2147483647

inline long long Min(long long a, long long b)
{
    return a < b ? a : b;
}

const char table[4][4] = {
    {START, SIGNED, NUMBER, END},
    {END, END, NUMBER, END},
    {END, END, NUMBER, END},
    {END, END, END, END}
};

char GetCol(char c)
{
    if (c == ' ') {
        return 0;
    } else if (c == '+' || c == '-') {
        return 1;
    } else if (c <= '9' && c >= '0') {
        return 2;
    } else {
        return 3;
    }
}

int myAtoi(char * str){
    long long ret = 0;
    char state = START;
    int idx = 0;
    bool isPos = true;
    while (str[idx] != '\0') {
        state = table[state][GetCol(str[idx])];
        if (state == NUMBER) {
            ret *= 10;
            ret += str[idx] - '0';
        } else if (state == SIGNED) {
            if (str[idx] == '-') {
                isPos = false;
            }
        } else if (state == END) {
            break;
        }
        if (isPos) {
            ret = Min(INT_MAX, ret);
        } else {
            ret = Min(-INT_MIN, ret);
        }
        ++idx;
    }
    if (!isPos) {
        return -ret;
    }
    return ret;
}


```
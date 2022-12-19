### 解题思路
    题解状态机思路很棒，之前做字符串总是缝缝补补，调试没过的情况就修正一下，导致代码量很大而且有的地方会重复处理。
    本人前一题解用了官方题解的思路写了一遍，以后遇到这类字符串问题要考虑状态机处理。

### 代码

```c
#define INT_MIN -2147483648
#define INT_MAX 2147483647
#define IDXLIM 12

int myAtoi(char * str){
    long long ret = 0;
    int len = strlen(str);
    bool isPos = true;
    int cnt = 0;
    bool startZero = false;
    for (int i = 0; i < len; i++) {
        if (str[i] != ' ') {
            if (str[i] == '-' || str[i] == '+') {
                if (str[i + 1] < '0' || str[i + 1] > '9') {
                    return ret;
                }
            } else {
                if (str[i] < '0' || str[i] > '9') {
                    return ret;
                }
            }
        }
        if (str[i] >= '0' && str[i] <= '9') {
            if (i > 0 && str[i - 1] == '-') {
                isPos = false;
            }
            int idx = i;
            if (str[idx] == '0') {
                startZero = true;
            }
            while (str[idx] >= '0' && str[idx] <= '9') {
                int digit = str[idx] - '0';
                if (str[idx++] != '0') {
                    startZero = false;
                }
                ret *= 10;
                ret += digit;
                if (!startZero && ++cnt > IDXLIM) {
                    break;
                }
            }
            break;
        }
    }
    if (!isPos) {
        ret = -ret;
        if (ret < INT_MIN) {
            return INT_MIN;
        }
        return ret;
    }
    if (ret > INT_MAX) {
        return INT_MAX;
    }
    return ret;
}

```
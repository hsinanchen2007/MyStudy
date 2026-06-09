### 解题思路
    /*
     * 注意特殊条件
     *
     * 核心操作是将字符转化为整数：
     * num = num * 10 + (str[i] - '0');
     *
     * 但要考虑各种特殊条件，例如首字符为空格，
     * 首字符为字母，首字符为正负号等。
     * 通过对各种条件逐一处理，可以完成转化。
     * */
### 代码

```cpp
int strToInt(std::string str) {
    int i = 0;

    // 处理首字符为空格的情况
    while (i < str.length()) {
        if (str[i] != ' ') {
            break;
        }

        i++;
    }
    str.erase(0, i);

    // 处理首字符为正负号的情况
    // 正负数标志
    int minus = 1;
    if (str[0] == '-') {
        minus = -1;
        str.erase(0, 1);
    } else if (str[0] == '+') {
        str.erase(0, 1);
    }

    // 处理字符串为空(包括删除完空格、正负号后)
    if (str.empty()) {
        return 0;
    }

    // 处理首字符不为数字的情况
    if (str[0] <= '0' || str[0] >= '9') {
        return 0;
    }

    long long int num = 0;
    i = 0;
    // 对字符串进行转化
    while (i < str.length() && str[i] >= '0' && str[i] <= '9') {
        // 核心操作
        num = num * 10 + (str[i] - '0');

        // 处理整数溢出的情况
        if (minus * num > INT_MAX) {
            return INT_MAX;
        }

        if (minus * num < INT_MIN) {
            return INT_MIN;
        }

        i++;
    }

    // 返回带符号的整数
    return num * minus;
}
```
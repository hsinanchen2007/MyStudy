这里使用了负数int来存储数字，原因是INT32_MIN=-2147483648, INT32_MAX=2147483647，负数的绝对值的最大值比正数的绝对值最大值多1.

步骤：
1. 跳过空格；

2. 若存在符号位，读取符号位，存储到`bool`变量`minus`中，正数时`minus=false;`. 负数时`minus=true;`；
3. 读取数字，将数字存储在变量`v`中，使用`v = v * 10 - (str[i] - '0')`的方式更新数字。变量v存储的数值为非正整数。在每次更新前，根据条件`v < INT32_MIN / 10 || v * 10 < INT32_MIN + u`判断v是否会在更新时越界，若会越界，根据minus变量返回`INT32_MIN`或`INT32_MAX`；
4. 读取完所有数字后，v仍然为非正的整数。若`minus`为`true`，直接返回v. 若`minus`为`false`, 首先判断`v`是否为INT32_MIN, 若`v`等于`INT32_MIN`, 说明读取的数字为+2147483648, 不能用有符号的`int32`存储，返回`INT32_MAX`；若`v`不等于`INT32_MIN`，返回`-v`.

```c++
class Solution {
public:
    int myAtoi(string str) {
        const int slen = str.size();
        if (slen == 0) return 0; // 空字符串
        int i = 0; // str的下标
        while (i < slen && str[i] == ' ') ++i; // 跳过空格
        if (i >= slen) return 0;
        // read sign
        char c = str[i];
        bool minus = false;
        if (c == '-') {
            minus = true;
            ++i;
        } else if (c == '+') ++i;
        int v = 0;
        bool valid = false;
        while (i < slen && str[i] >= '0' && str[i] <= '9') {
            valid = true;
            int u = str[i] - '0';
            // v * 10 - u >= INT32_MIN
            // v * 10 >= INT32_MIN + u
            if (v < INT32_MIN / 10 || v * 10 < INT32_MIN + u) return minus ? INT32_MIN : INT32_MAX;
            v = v * 10 - u;
            ++i;
        }
        if (!valid) return 0;
        if (minus) return v;
        if (v == INT32_MIN) return INT32_MAX;
        return -v;
    }
};
```
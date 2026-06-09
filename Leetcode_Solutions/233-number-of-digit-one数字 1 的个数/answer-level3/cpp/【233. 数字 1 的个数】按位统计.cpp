## 思路
参考《程序员代码面试指南》
先统计最高位为1的个数，在统计其它位为1的个数
### 代码
```c++
class Solution {
public:
    int countDigitOne(int n) {
        if (n < 1) {
            return 0;
        }
        int len = getLen(n);
        if (len == 1) {
            return 1;
        }
        int tmp = pow(10, len-1);
        int first = n / tmp;
        int firstOne = first == 1 ? n % tmp + 1 : tmp;
        int otherOne = first * (len - 1) * (tmp / 10);
        return firstOne + otherOne + countDigitOne(n%tmp);
    }
    int getLen(int n) {
        int c = 0;
        while (n) {
            ++c;
            n /= 10;
        }
        return c;
    }
};
```

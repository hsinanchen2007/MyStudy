### 解题思路
每次记录当前数字的最后一位，然后删除最后一位。

每次将反转结果rev*10并加上最后一位pop

参考[官方题解](https://leetcode-cn.com/problems/reverse-integer/solution/zheng-shu-fan-zhuan-by-leetcode/)

### 代码

```cpp
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        // cout << "INT_MAX = " << INT_MAX << endl;
        // INT_MAX = 2147483647
        // cout << "INT_MIN = " << INT_MIN << endl;
        // INT_MIN = -2147483648
        while (x != 0) {
            int pop = x % 10;   // 取最后一位
            x /= 10;    //      // 去掉最后一位
            // 如果反转之后的值大于INT_MAX/10,或者反转之后的值等于INT_MAX/10并且个位值大于7,说明会发生上溢，返回0
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            // 如果反转之后的值小于INT_MIN/10,或者反转之后的值等于INT_MIN并且个位值小于-8,说明下溢，返回0
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            // 如果不会溢出那么rev
            rev = rev * 10 + pop;
        }
        return rev;
    }
};
```
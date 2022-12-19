### 解题思路
注意溢出和正负号的处理即可

### 代码

```cpp
class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while(x)
        {
            if(abs(res) > INT_MAX / 10) return 0;
            res = res * 10 + x % 10;//x为负时,%运算得到的符号也为负,数字部分与x为正时的结果相等.故这样做不需要处理符号
            x /= 10;
        }
        return res;
    }
};
```
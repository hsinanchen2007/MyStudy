### 解题思路
这道题就是翻转一下，不用担心正负的问题，因为取个位数的时候，%就保留了正负符号的。
需要注意的是溢出问题，即数值范围为 [−231,  231 − 1]，在CPP中为INT_MIN, INT_MAX
怎么计算这个溢出呢，rev = rev * 10 + pop
rev * 10 + pop > INT_MAX =>rev > (INT_MAX - pop) / 10

但为什么在程序中可以不减pop来判断呢，这是因为如果是整数，pop需要大于7，如果是负数，pop需要小于-8,
但是x的取值就是2的32次方，pop是x的第一位，只能为1或者2.

### 代码

```cpp
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        if(x == 0 || x == NULL) return 0;
        while(x != 0){
            int pop = x % 10;
            x /= 10;
            if(rev > INT_MAX / 10) return 0;
            if(rev < INT_MIN / 10) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};
```
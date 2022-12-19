### 解题思路
每次取最高位和最低位比较，如果不相等就返回false。全相等就为true。

### 代码

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int temp = 1;   // 记录数字的最高位数-1,可以/10取最高位
        int pop = 0;
        int high = 0;

        while(x / temp >= 10){
            temp *= 10;
        }

        while(x > 0){
            pop = x % 10;   // 取个位
            high = x / temp;    // 取最高位
            if(pop != high) return false;
            x %= temp;    // 去掉最高位
            x /= 10;    // 去掉最低位
            temp /= 100;     
        }
        return true;
    }
};
```
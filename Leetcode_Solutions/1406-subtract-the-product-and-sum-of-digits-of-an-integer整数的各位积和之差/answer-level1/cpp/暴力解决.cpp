### 解题思路
拆解暴力计算

### 代码

```cpp
class Solution {
public:
    int subtractProductAndSum(int n) {
        int product{1};
        int addition{0};
        int remainder{0};
        while(n > 0)
        {
            remainder = n % 10;
            n = n / 10;
            product = product * remainder;
            addition += remainder;
        }
        return product - addition;
    }

};
```
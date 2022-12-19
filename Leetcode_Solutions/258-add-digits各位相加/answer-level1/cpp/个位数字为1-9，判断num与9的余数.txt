### 解题思路
从基本情况开始考虑
1. 1~9 直接返回
2. 10 ~ 18 发现其个位又从1~9
如此发现，每9个连续的数，最后的个位结果会重复出现，
故只需判断num % 9，判断余数
### 代码

```cpp
class Solution {
public:
    int addDigits(int num) {
        if (num <= 0) {
            return 0;
        }
        int mod = num % 9;
        return mod == 0 ? 9 : mod;
    }
};
```
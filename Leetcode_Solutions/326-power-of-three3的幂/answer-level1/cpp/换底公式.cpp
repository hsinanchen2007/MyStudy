### 解题思路
若n是3的幂，那么log3(n)一定是个整数，由换底公式可以的得到log3(n) = log10(n) / log10(3),只需要判断log3(n)是不是整数即可
同理该公式可以推广到n的幂

### 代码

```cpp
class Solution {
public:
    bool isPowerOfThree(int n) {
        double res = log10(n) / log10(3);
        return res - (int)res == 0?true:false;
    }
};
```
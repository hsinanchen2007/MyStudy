## 思路
参考[官方题解](https://leetcode-cn.com/problems/water-and-jug-problem/solution/shui-hu-wen-ti-by-leetcode-solution/)

### 代码
时间复杂度：O(log(min(x, y)))，取决于最大公约数辗转相除法
空间复杂度：O(1)
```cpp
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        return z == 0 || (x + y >= z && z % gcd(x, y) == 0);
    }
};
```
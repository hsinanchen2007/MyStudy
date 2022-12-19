1. 异或运算，0^0 == 0, 0^1 == 1, 1^0 == 1, 1^1 == 0 可以把x和y中相同位置0，不同位置1 。
2. 求和不同位的个数。
```
class Solution {
public:
    int hammingDistance(const int x, const int y) {
        return bitset<32>(x^y).count();
    }
};
```

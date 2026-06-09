### 思路

| | | | | |
-- | -- | -- | -- | -- |
4 | 0 | 1 | 0 | 0 |
14 | 1 | 1 | 1 | 0 |
2 | 0 | 0 | 1 | 0 |
1 | 0 | 0 | 0 | 1 |
第一列，有1个1,3个0，它们之间相互距离是3
第二列，有2个1，2个0，它们之间相互距离是4
观察得出，每位的之间相互距离即为： 0出现个数 * 1出现个数。

### 代码

```cpp
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int size = nums.size(), res = 0;
        for (int i = 0; i < 32; ++i) {
            int cnt = 0;
            for (int n : nums) {
                if (n & (1 << i)) ++cnt;
            }
            res += cnt * (size - cnt);
        }
        return res;
    }
};
```
### 解题思路
遍历所有bit位0~31，
遍历当前bit位下，nums中所有数对应bit位中为1的个数ones, bit位为0的个数zeros = nums.size() - ones
当前bit位能够产生的hammingDistance = zeros * ones
如此遍历完毕所有的32位即可
### 代码

```cpp
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        if (nums.size() <= 1) {
            return 0;
        }
        int res = 0;
        int sz = nums.size();
        long flag = 1;
        for (int bit = 0; bit < 32; ++bit) {
            int ones = 0;
            for (int i = 0; i < sz; ++i) {
                ones += (nums[i] & flag) ? 1 : 0;
            }
            res += (sz - ones) * ones;
            flag <<= 1;
        }
        return res;
    }
};
```
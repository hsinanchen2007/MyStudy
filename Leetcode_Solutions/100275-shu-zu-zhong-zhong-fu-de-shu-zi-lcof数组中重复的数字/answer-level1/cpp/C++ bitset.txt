### 解题思路
bitset搞定，每个数字占一个位。如果重复出现了1，那直接返回。

### 代码

```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        bitset<100003> sset;
        for (int i =0; i<nums.size(); i++) {
            if (sset.test(nums[i])) {
                return nums[i];
            }
            sset.set(nums[i]);
        }
        return 0;
    }
};
```
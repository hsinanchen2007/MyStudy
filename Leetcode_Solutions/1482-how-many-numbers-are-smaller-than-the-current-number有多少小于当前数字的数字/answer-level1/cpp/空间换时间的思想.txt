### 解题思路
时间复杂度O(n+S)
空间复杂度O(S)

### 代码

```cpp
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int size = nums.size();
        vector<int> count(101, 0);
        vector<int> smaller(size, 0);
        for (int i = 0; i < size; ++i) ++count[nums[i]];
        for (int i = 1; i < 101; ++i) count[i] += count[i - 1];
        for (int i = 0; i < size; ++i) {
            if (nums[i]) smaller[i] = count[nums[i] - 1];
        }
        return smaller;
    }
};
```
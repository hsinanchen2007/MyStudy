### 解题思路
时间复杂度O(n)
空间复杂度O(1)

### 代码

```cpp
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int size = nums.size();
        vector<int> smaller(size);
        for (int i = 0; i < size; ++i) {
            int count = 0;
            for (int j = 0; j < size; ++j) {
                if (nums[j] < nums[i]) ++count;
            }
            smaller[i] = count;
        }
        return smaller;
    }
};
```
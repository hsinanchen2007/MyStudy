### 解题思路
由题知，a[i] 位于 [1,n]之间，考虑将a[i]放置于数组中的第i个位置即可，
### 代码

```cpp
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        if (nums.size() <= 1) {
            return vector<int>();
        }
        
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == i + 1) {
                continue;
            }
            
            while (nums[i] != i + 1 && nums[i] != 0) {
                if (nums[nums[i] - 1] == nums[i]) {
                    res.push_back(nums[i]);
                    nums[i] = 0;
                    break;
                }
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        return res;
    }
};
```
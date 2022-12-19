### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> vec;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                vec.push_back(nums[i]);
            }
        }
        return vec;
    }
};
```
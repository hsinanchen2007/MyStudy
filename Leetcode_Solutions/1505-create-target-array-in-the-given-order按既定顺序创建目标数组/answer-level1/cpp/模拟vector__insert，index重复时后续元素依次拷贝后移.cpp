### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int sz = nums.size();
        vector<int> res;
        for (int i = 0; i < sz; ++i) {
            int idx = index[i];
            if (idx + 1 > res.size()) {
                res.push_back(nums[i]);
            } else {
                res.push_back(-1);
                for (int j = res.size() - 1; j > idx; --j) {
                    res[j] = res[j - 1];
                }
                res[idx] = nums[i];
            }
        }
        return res;
    }
};
```
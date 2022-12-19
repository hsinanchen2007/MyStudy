### 解题思路
假设集合大小是n,美剧0..2^n-1，一共2^n个数。
每个数表示一个子集，假设这个数的二进制表示的第i位是1，则表示该子集包含第i个数，否则表示不包含。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() == 0) {
            return res;
        }

        for (int i = 0; i < 1 << nums.size(); i++) {
            vector<int> now;
            for (int j = 0; j < nums.size(); j++) {
                if (i >> j & 1) {
                    now.push_back(nums[j]);
                }
            }
            res.push_back(now);
        }
        return res;
   }
};
```
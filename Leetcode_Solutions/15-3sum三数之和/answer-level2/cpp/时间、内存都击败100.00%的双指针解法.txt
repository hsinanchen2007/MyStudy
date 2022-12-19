### 解题思路
![屏幕快照 2020-03-18 07.36.24 AM.png](https://pic.leetcode-cn.com/966893a8e8fdeed1c84acdf656fe8d61509ec0bca07f3a0d5c51f676a3ccd8ae-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-03-18%2007.36.24%20AM.png)
同样是双指针法，当找到了一组值后，就可以去重了，分别遍历i, j, k，走到不相等为止

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        size_t j, k = 0;
        int target = 0;
        int twosum = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) break;
            target = -nums[i];
            j = i + 1; k = nums.size() - 1;
            while (j < k) {
                twosum = nums[j] + nums[k];
                if (twosum < target) {
                    j++;
                } else if (twosum > target) {
                    k--;
                } else {
                    res.push_back(vector<int>{-target, nums[j], nums[k]});
                    
                    while (i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;

                    while (j + 1 < k && nums[j + 1] == nums[j]) j++;
                    while (j < k && nums[k] == nums[k-1]) k--;
                    j++; k--;
                }
            }
        }
        return res;
    }
};
```
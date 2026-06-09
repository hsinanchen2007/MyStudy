### 解题思路
动态规划，
T(n) = max(T(x)) + 1 (nums[x] < nums[n] && x < n)  
### 代码

```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0; 
        int len = nums.size();
        vector<int> vv(len, 1);
        int res = 1;
        for (int i = 0; i < len; i++) {
            int max_l = 0;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    max_l = max(max_l, vv[j]);
                }
            }
            vv[i] = max_l + 1;
            res = max(res, vv[i]);
        }

        return res;
    }
};
```
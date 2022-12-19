### 解题思路
1、外层循环嵌固定一个数值然后，套一个2sum的部分。
2、用map的hash完成2sum部分会超时，因为find的过程是O(logn)。
3、现在采用的是先排序再维护左右双下标向中间推进找答案。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> rst;
        sort(nums.begin(),nums.end());
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            if (i > 0 and nums[i] == nums[i-1]) continue;
            int l = i+1, r = len-1;
            while (l < r) {
                int s = nums[i] + nums[l] + nums[r];
                if (s < 0) l++;
                else if (s > 0) r--;
                else {
                    rst.push_back(vector<int> {nums[i], nums[l], nums[r]});
                    while (l+1<r and nums[l]==nums[l+1]) l++; l++;
                    while (r-1>l and nums[r]==nums[r-1]) r--;r--;
                }
            }
        }
        return rst;
    }
};
```
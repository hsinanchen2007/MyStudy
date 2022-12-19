```
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return dfs(nums, 0, nums.size());
    }
    int dfs(vector<int>& nums, int le, int ri) {
        if(ri - le <= 1) return 0;    // 这里的ri为边界，取不到
        int mid = (le + ri) >> 1;     // 直接相加有时候可能会溢出
        int res = dfs(nums, le, mid) + dfs(nums, mid, ri);  // Divide
        sort(nums.begin()+le, nums.begin()+mid);
        for(int i=mid; i<ri; i++) {
            res += nums.begin() + mid - upper_bound(nums.begin()+le, nums.begin()+mid, nums[i]);
        }
        return res;
    }
};
```

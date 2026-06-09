```
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //return solve(nums{, 0, nums.size());
        return solve2(nums);
    }

    int solve2(vector<int>& nums){
        /*
            d[i]:以nums[i]结尾的解
            d[i] = max{nums[i], d[i-1] + nums[i]}   实际上，由d[i-1]的正负性决定
        */
        int n = nums.size();
        if(n == 0) return 0;
        int d[n], ans = nums[0];
        d[0] = nums[0];
        for(int i = 1; i < n; i++){
            d[i] = max(nums[i], d[i-1] + nums[i]);
            ans = max(d[i], ans);
        }
        return ans;
    }

    int solve(vector<int>nums, int x, int y){ //[x, y)
        if(y - x == 1) return nums[x];
        int mid = x + (y-x)/2;
        int ans = max(solve(nums, x, mid), solve(nums, mid, y));
        int lSum = 0, lMax = INT_MIN;
        for(int i = mid - 1; i >= x; i--){
            lSum += nums[i];
            lMax = max(lMax, lSum);
        }
        int rSum = 0, rMax = INT_MIN;
        for(int i = mid; i < y; i++){
            rSum += nums[i];
            rMax = max(rMax, rSum);
        }
        ans = max(ans, lMax + rMax);
        return ans;
    }
};
```
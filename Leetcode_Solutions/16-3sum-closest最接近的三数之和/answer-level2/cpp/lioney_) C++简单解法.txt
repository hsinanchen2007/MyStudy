```
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2], diff = abs(res - target) ;
        for(int i=0; i<nums.size()-2; i++) {
            int l = i+1, r = nums.size()-1;
            while(l<r) {
                int sum = nums[i] + nums[l] + nums[r];
                int d = abs(sum - target);
                if(d < diff) {
                    res = sum;
                    diff = d;
                }
                if(sum < target)
                    l++;
                else
                    r--;
            }
        }
        return res;
    }
};
```

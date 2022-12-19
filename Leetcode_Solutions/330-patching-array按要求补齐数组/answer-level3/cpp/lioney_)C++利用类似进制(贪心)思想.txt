```
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int res = 0, i = 0;
        long miss = 1;
        while(miss <= n) {
            if(i<nums.size() && nums[i] <= miss) {
                miss += nums[i++];
            }
            else {
                miss += miss;
                res += 1;
            }
        }
        return res;
    }
};
```

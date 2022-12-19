```
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if(nums.empty()) return 0;
        int L =0, R=nums.size()-1;
        while(L<R) {
            int mid = (R-L)/2+L;
            if(nums[mid] == mid) {
                L = mid+1;
            } else if(nums[mid] > mid) {
                R = mid;
            }
        }
        return nums[L]>L?--nums[L] : ++nums[L];
    }
};
```

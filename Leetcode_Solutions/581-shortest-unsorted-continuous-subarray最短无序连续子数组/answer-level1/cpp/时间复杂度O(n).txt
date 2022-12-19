```
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        vector<int> left(nums.size(), false);
        vector<int> right(nums.size(), false);
        
        
        int l_max = nums[0];
        for(int i = 0; i < nums.size(); i ++) {
            if(l_max <= nums[i]) {
                l_max = nums[i];
            } else {
                left[i] = true;
            }
        }
        
        int r_min = nums[nums.size() - 1];
        for(int i = nums.size() - 1; i >= 0; i --) {
            if(r_min >= nums[i]) {
                r_min = nums[i];
                
            } else {
                right[i] = true;
            }
        }
        
        int res_l = -1;
        for(int i = 0; i < nums.size(); i ++) {
            if(left[i] != 0 || right[i] != 0) {
                res_l = i;
                break;
            }
        }
        
        int res_r = nums.size();
        for(int i = nums.size() - 1; i >= 0; i --) {
            if(left[i] != 0 || right[i] != 0) {
                res_r = i;
                break;
            }
        }
        
        if(res_l == -1 && res_r == nums.size()) return 0;
        else return res_r - res_l + 1;
    }
};
```
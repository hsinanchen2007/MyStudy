```
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        
        if(nums.size() < 3) return true;
        
        int l = 0;
        for(int i = 1; i < nums.size() ;i ++) {
            if(nums[i] >=nums[i - 1]) {
                l = i;
            } else {
                break;
            }
        }
        if(l == nums.size()) return true;
        
        int r = nums.size() - 1;
        for(int j = nums.size() - 2; j >= 0; j --) {
            if(nums[j] <= nums[j + 1]) {
                r = j;
            } else {
                break;
            }
        }
        if(r == 0) return true;
        
        cout << l << r << endl;
        
        if(l + 1 != r) {
            return false;
        }
        if(l == 0 || r == nums.size() - 1) return true;
        
        if(l > 0 && nums[l - 1] <= nums[r]) return true;
        if(r < nums.size() - 1 && nums[l] <= nums[r + 1]) return true;
        return false;
    }
};
```
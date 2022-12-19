是修改a[i]还是a[i+1]取决于a[i]的最小值a[i-1]是否是小于等于a[i+1]或者a[i+1]的最大值a[i+2]是否是大于等于a[i]。
```
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if(nums.size() < 3) return true;
        bool flag = false;
        for(int i = 0; i < nums.size()-2; i++) {
            if(nums[i] > nums[i+1]) {
                if(!flag) {
                    flag = true;
                    if(i > 0 && nums[i-1] > nums[i+1] && nums[i] > nums[i+2]) return false;
                }
                else return false;
            }
        }
        return !flag || nums[nums.size()-2] <= nums[nums.size()-1];
    }
};
```

一个简单的暴力解法，28ms



```
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int val;
        int i = 0; 
        while(i < n - 1){
            if(nums[i] != nums[i + 1]){
                return nums[i];
            }
            if(nums[i] == nums[i + 1]){
                i = i + 2;
            }
        }
        return nums[n - 1];
    }
};
```

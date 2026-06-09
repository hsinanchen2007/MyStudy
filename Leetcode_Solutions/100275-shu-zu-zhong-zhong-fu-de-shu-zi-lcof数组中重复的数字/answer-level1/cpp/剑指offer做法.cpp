```
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        // hash记录
        //unordered_map<int,int>Mp;
        for(int i=0;i<nums.size();i++){
            while(nums[i] != i){
                if(nums[i] == nums[nums[i]]) return nums[i];
                swap(nums[nums[i]], nums[i]);
            }
        }
        return 1;
    }
};
```

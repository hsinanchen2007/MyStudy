```
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // 抽屉原理 异或交换两个变量的值
        for(int i=0;i<nums.size();i++){
            while(nums[i] != nums[nums[i]-1])
                swap(nums,i,nums[i]-1);
        }
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i+1)
                res.push_back(i+1);
        }
        return res;
    }
    
    void swap(vector<int>& nums, int idx_1, int idx_2){
        if(idx_1==idx_2)
            return;
        else{
            nums[idx_1] = nums[idx_1]^nums[idx_2];
            nums[idx_2] = nums[idx_1]^nums[idx_2];
            nums[idx_1] = nums[idx_1]^nums[idx_2];
        }
    }
};
```

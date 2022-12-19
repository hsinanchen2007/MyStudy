```
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int nums_size = nums.size();
        sort(nums.begin(),nums.end());
        
        vector<vector<int>> ret;
        
        for(int i=0;i<nums_size-3;i++){
            for(int j=i+1;j<nums_size-2;j++){
                for(int low = j+1,high = nums_size-1 ; low < high ; ){
                    if(nums[i]+nums[j]+nums[low]+nums[high] < target){
                        low++;
                    }else if(nums[i]+nums[j]+nums[low]+nums[high] > target){
                        high--;
                    }else{
                        vector<int> v_temp = {nums[i],nums[j],nums[low],nums[high]};
                        ret.push_back(v_temp);
                        
                        while(low < high && nums[low] == nums[low+1])//去重
                            low++;
                        while(low < high && nums[high] == nums[high-1])//去重
                            high--;
                        
                        low++;high--;
                    }
                }
                while(j<nums_size-2 && nums[j] == nums[j+1])//去重
                    j++;
            }
            while(i<nums_size-3 && nums[i] == nums[i+1])//去重
                i++;
        }
        
        return ret;
    }
};
```

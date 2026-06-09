### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> ans;
        if(nums.size() <= 3)
            return ans;
        
        //排序，O(nlogn)
        sort(nums.begin(),nums.end());
        /**
        1. 暴力方法 O(n^4)
        2. 采用双指针，O(n^3)
        */
        for(int i=0;i<nums.size()-3;i++){
            if(i>0 && nums[i] == nums[i-1])
                     continue;
            for(int j = i+1;j<nums.size()-2 ; j++){
                //防止重复 [-2,-1,-1 , ...]  两个-1 ， j至少计算1次
                if(j>i+1 && nums[j] == nums[j-1])
                    continue;
                int l = j+1;
                int r = nums.size() - 1;
                while(l < r){

                    if(nums[i] + nums[j] + nums[l] + nums[r] < target){
                        l++;
                    }else if(nums[i] + nums[j] + nums[l] + nums[r] > target){
                        r--;
                    }else{
                        int tmp[4] = {nums[i],nums[j],nums[l],nums[r]};
                        ans.push_back(vector<int>(tmp,tmp+4));
                        //要先去除重复的可能
                        while(l<r && nums[l] == nums[l+1])
                            l++;
                        while(l<r && nums[r-1] == nums[r])
                            r--;

                        //继续往下，一大一小才有可能等于target,eg : 1-6 , 2-5
                        l++;
                        r--;
                    }
                }
                
            }
        }
        return ans;
        
    }
};
```
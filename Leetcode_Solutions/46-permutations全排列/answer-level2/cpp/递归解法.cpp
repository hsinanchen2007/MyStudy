### 解题思路


### 代码

```cpp
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector <int>> res;
        permuteevery(res,nums,0);
        return res;
    }
    
    void permuteevery(vector<vector<int>> &res , vector<int> nums, int start){
        if (start == nums.size()){
            res.push_back(nums);
            return;
        }
        else{
            for (int i=start;i<nums.size();i++){
                swap(nums[i],nums[start]);
                permuteevery(res,nums,start+1);
                swap(nums[i],nums[start]);
                } 
        }
        
    
    }
};
```
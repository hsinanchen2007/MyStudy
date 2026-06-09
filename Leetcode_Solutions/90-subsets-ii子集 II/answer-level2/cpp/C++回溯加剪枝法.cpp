### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>path;
        sort(nums.begin(),nums.end());
        for(int k=0;k<=nums.size();k++){
            backtrack(0,k,path,nums);
        }
        return res;
    }

   void backtrack(int first , int k ,vector<int>&path,vector<int>&nums){
       if(path.size() == k){
           res.push_back(path);
           return; 
       }
       for(int i = first;i<nums.size();i++){
           if( i>first && nums[i-1] == nums[i] ) continue;
           path.push_back(nums[i]);
           backtrack(i+1,k,path,nums);
           path.pop_back();
       }
   }
 private : vector<vector<int>>res;
};
```
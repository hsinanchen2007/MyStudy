### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>path;
        for(int k=0;k<=nums.size();k++){
            backtrack(0,k,path,nums);
        }
     return res;
    }

 void backtrack(int start,int k,vector<int>&path,vector<int>&nums){
     if(path.size()==k){
         res.push_back(path);
         return ;
     }
     for(int i= start;i<nums.size();i++){
         path.push_back(nums[i]);
         backtrack(i+1,k,path,nums);
         path.pop_back();
     }
 }

private:vector<vector<int>>res;
};
```
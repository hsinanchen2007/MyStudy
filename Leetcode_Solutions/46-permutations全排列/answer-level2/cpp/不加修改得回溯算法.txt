### 解题思路
1，判断做出得选择是否满足终止条件
2，执行选择
3，退回上一步得选择

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        backtrack(nums,res,temp);
        return res;
    }
 
     void backtrack(vector<int> &nums,vector<vector<int>> &res,vector<int> temp){
         //判断z选择
         if(temp.size()==nums.size()){
             res.push_back(temp);
             return;
         }
            
         for(int j=0;j<nums.size();j++){
        //做出选择
            vector<int>::iterator it = find(temp.begin(),temp.end(),nums[j]);
            if(it != temp.end()){
                continue;
            }
            temp.push_back(nums[j]);
            backtrack(nums,res,temp);
        //退回上一步得选择
            temp.pop_back();

         }
     }
};
```
### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>temp;
        help(res,temp,candidates,target,0);
        return res;
    }
    void help(vector<vector<int>>&res,vector<int>&temp,vector<int>&candidates,int target,int level){
        if(target == 0){                                         //防止重复加个level参数，只选取自己和自己之后的数
            res.push_back(temp);
            return;
        }
        if(target < 0){
            return;
        }
        int len = candidates.size();
        for(int i = level;i < len;i++){
                temp.push_back(candidates[i]);
                target -= candidates[i];
                help(res,temp,candidates,target,i);
                target += candidates[i];
                temp.pop_back();
            }
        
        
    }
};
```
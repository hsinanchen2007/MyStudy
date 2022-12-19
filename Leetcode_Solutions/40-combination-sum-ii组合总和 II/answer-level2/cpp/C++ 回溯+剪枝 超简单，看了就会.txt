发现题解中C++的代码剪枝写的不是很好。于是就把自己的代码给大家做参考了。至于思想和官方想法一样。就不赘述了。
```
class Solution {
public:
    vector<vector<int>> ret;
    vector<int> tmp;
    
    void helper(int index,vector<int>& candidates,int target){
        if(target < 0)
            return;
        if(target == 0){
            ret.push_back(tmp);
            return;
        }
        
        for(int i=index;i<candidates.size();i++){
            if(i!=index && candidates[i] == candidates[i-1])
                continue ;
            
            tmp.push_back(candidates[i]);
            helper(i+1,candidates,target - candidates[i]);
            tmp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        helper(0,candidates,target);
        return ret;
    }
};
```

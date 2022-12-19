1. 第一版 

```
class Solution {
public:
    
    vector<vector<int>> res;
    
    void DFS(vector<int> candidates,int target,vector<int> v,int pre)
    {
        for(int i=0;i<candidates.size();i++)
        {
            vector<int> temp = v;    
            int candidates_i = candidates[i];
            int temptarget = target - candidates_i;
            if(candidates_i<pre) continue；
            if(temptarget>0)
            {    
                temp.push_back(candidates_i);
                DFS(candidates, temptarget, temp, candidates_i);
            }
            else if(temptarget<0) break;
            else if(temptarget==0) 
            {
                temp.push_back(candidates_i);
                res.push_back(temp);  
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.size()==0) return {{}};
        sort(candidates.begin(),candidates.end());
        vector<int> v;
        DFS(candidates, target, v, INT_MIN); 
        return res;
    }
};
```

2. 第二版，时间复杂度差不多高...要剪枝才行，继续改。
```
class Solution {
public:
    
    vector<vector<int>> res;
    
    void DFS(vector<int> candidates,int target,vector<int> v,int pre)
    {
        for(int i=0;i<candidates.size();i++)
        {
            vector<int> temp = v;    
            int candidates_i = candidates[i];
            int temptarget = target - candidates_i;
            
            if(candidates_i<pre) continue;
            if(temptarget>0)
            {    
                temp.push_back(candidates_i);
                DFS(candidates, temptarget, temp, candidates_i);
            }
            else if(temptarget<0) continue;
            else if(temptarget==0) 
            {
                temp.push_back(candidates_i);
                res.push_back(temp);  
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.size()==0) return {{}};
        vector<int> v;
        DFS(candidates, target, v, INT_MIN); 
        return res;
    }
};
```

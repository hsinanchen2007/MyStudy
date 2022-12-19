### 解题思路
1.首先进行预处理，对原数组进行排序和删除比target大的数据
2.使用递归和回溯，将和为target的temp数组加入res；
3.剪枝：temp加入新数据的和大于target了；
4.去重：一开始会有重复出现，看其他答案受到启发，可以通过大小来判断，不让比之前小的数据加入temp；

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> candidates_new;
        vector<vector<int>> res;
        vector<int> temp;
        for(int i=0;i<candidates.size();i++){ // 删掉比target大的数据
            if(candidates[i]>target) break;
            candidates_new.push_back(candidates[i]);
        }
        dfs(candidates_new,res,temp,target);
        return res; 
    }
    void dfs(vector<int>& candidates_new,vector<vector<int>>& res,vector<int>& temp, int target){
        if(accumulate(temp.begin(),temp.end(),0)==target){
            res.push_back(temp);
        }
        for(int i=0;i<candidates_new.size();i++){
            if(temp.size()>0&&candidates_new[i]<temp[temp.size()-1]) continue; //一开始会有重复出现，看其他答案受到启发，可以通过大小来判断，不让比之前小的数据加入temp；
            temp.push_back(candidates_new[i]);
            if(accumulate(temp.begin(),temp.end(),0)>target){
                temp.pop_back();
                continue;
            }
            dfs(candidates_new,res,temp,target);
            temp.pop_back();
        }
    }
};
```
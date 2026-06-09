### 解题思路
一个思路；两种写法
一是target减数字
二是使用accumulate计算数组和。


### 代码1

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> candidates_new;
        vector<vector<int>> res;
        vector<int> temp;
        for(int i=0;i<candidates.size();i++){ // 删掉比target大的数据
            if(candidates[i]>target) break;
            candidates_new.push_back(candidates[i]);
        }
        dfs(candidates_new,res,temp,0,target);
        return res; 
    }
    void dfs(vector<int>& candidates_new,vector<vector<int>>& res,vector<int>& temp, int start, int target){
        if(accumulate(temp.begin(),temp.end(),0)==target){
            res.push_back(temp);
        } 
        for(int i=start;i<candidates_new.size();i++){
            if(i > start && candidates_new[i] == candidates_new[i - 1]) continue;
            temp.push_back(candidates_new[i]);
            if(accumulate(temp.begin(),temp.end(),0)>target){
                temp.pop_back();
                continue;
            }
            dfs(candidates_new,res,temp,***i+1***,target); //一开始死活做不对永远有重复的，原来是这里写错了，应该是i+1，我写的是start+1；
            temp.pop_back();
        }
    }
};
```
### 代码2

```cpp
class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;
    vector<int> candidates_new;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        for(int i=0;i<candidates.size();i++){ // 删掉比target大的数据
            if(candidates[i]>target) break;
            candidates_new.push_back(candidates[i]);
        }
        dfs(0,target);
        return res; 
    }
    void dfs(int start, int remain){
        if(remain==0) {
            res.push_back(temp);
            return;
        } 
        if(start == candidates_new.size() || remain < 0)
        {
            return;
        }

        for(int i=start;i<candidates_new.size();i++){
            if(i > start && candidates_new[i] == candidates_new[i - 1]) continue;
            temp.push_back(candidates_new[i]);
            dfs(i+1,remain - candidates_new[i]);
            temp.pop_back();
        }
    }
};
```

### 解题思路
![1586001106(1).png](https://pic.leetcode-cn.com/d65dae0aa3cda0af492461bb54a8105c1ae6aa0a231a767d80441848a0091ff4-1586001106\(1\).png)
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> res;
    vector<int> ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int len = candidates.size();
        if(len==0)  return res;
        sort(candidates.begin(),candidates.end());
        dfs(candidates,len,target,0);
        return res;
    }
    void dfs(vector<int>& candidates,int len,int target,int st){
        if(target==0){
            res.push_back(ans);
            return;
        }
        for(int i=st;i<len;++i){
            if(i>st&&candidates[i]==candidates[i-1]) //剪枝
                continue;
            if(target-candidates[i]>=0){
                ans.push_back(candidates[i]);
                dfs(candidates,len,target-candidates[i],i+1);
                ans.pop_back();
            }
            else //剪枝
                return;
        }
    }
};
```
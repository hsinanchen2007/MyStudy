### 解题思路
这是一个树的题目。使用vector代替邻接表，记录边。然后使用dfs层层遍历每一个当前位置的子节点，取最大值便能得到答案啦~

### 代码

```cpp
class Solution {
public:
vector<vector<int> > son;
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        son.resize(n);
        int ans=0;
        for(int i=0;i<manager.size();i++){
            if(i!=headID){
                son[manager[i]].push_back(i);
            }
            
        }ans=dfs(headID, informTime);
        return ans;
    }

   int dfs(int x,vector<int>& informTime)
    {
        int res=0;
        for(auto s:son[x]) res=max(res, dfs(s, informTime));
        return informTime[x]+res;
    }
};
```
回溯的过程中用一个数组代替 比如 temp={1,2,0}代表了皇后的位置在第一行1处，第二行2处，第三行0处
然后在回溯的过程中主要寻找有哪些地方还可以放皇后，然后就这样递归下去。

```
class Solution {
    vector<vector<int>> res;
    void dfs(vector<int> &que , int n){
        if(que.size() == n){
            res.push_back(que);
            return;
        }
        //然后找可以下的地方
        vector<bool> vis(n,true);
        int index = que.size();
        for(int i = 0;i<index;i++){
            int q = que[i];
            vis[q] = false;
            if(q+(index-i)<n) vis[q+(index-i)] = false;
            if(q-(index-i)>=0) vis[q-(index-i)] = false;
        }
        
        for(int i = 0;i<vis.size();i++){
            if(vis[i]){
                que.push_back(i);
                dfs(que,n);
                que.pop_back();
            }
        }
        return; 
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> tmp;
        dfs(tmp,n);
        vector<vector<string>> ans;
        for(auto mp: res){
            vector<string> temp;
            for(auto p:mp){
                string t(n,'.');
                t[p] ='Q';
                temp.push_back(t);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
```

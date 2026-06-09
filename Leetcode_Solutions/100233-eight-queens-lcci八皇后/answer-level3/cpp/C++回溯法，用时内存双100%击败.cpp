
### 代码

```cpp
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void dfs(int n){
        if(temp.size()==n){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<n;i++){
            int j=0;
            for(;j<temp.size();j++){
                if(temp[j]==i||temp.size()-j==i-temp[j]||temp.size()-j==temp[j]-i)
                break;
            }
            if(j==temp.size()){
                temp.push_back(i);
                dfs(n);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        dfs(n);
        string qq(n,'.');
        vector<vector<string>> an;
        for(int i=0;i<ans.size();i++){
            vector<string> tt;
            for(int j=0;j<n;j++){
               string ww=qq;
               ww[ans[i][j]]='Q';
               tt.push_back(ww);
            }
            an.push_back(tt);
        }
        return an;
    }
};
```
### 解题思路
dfs解法

### 代码

```cpp
class Solution {
public:
    
    
    int count=0;
    int vis[100];
    vector<vector<string>> ans;
    vector<vector<string>> solveNQueens(int n) {
        //存在每一行选择的列
        vector<int> cols;
        cols.push_back(0);
        fill(vis,vis+n+1,0);
        dfs(1,n,cols);
        return ans;
    }

    void dfs(int row,int n,vector<int>& cols){
        if(row==n+1){
            count++;
            vector<string> v;
            for(int x=1;x<=n;x++){
                string s="";
                for(int y=1;y<=n;y++){
                    if(y==cols[x]){
                        s=s+'Q';
                    }
                    else{
                        s=s+'.';
                    }
                }
                v.push_back(s);
            }
            ans.push_back(v);
            return;
        }
        //遍历所有列
        for(int i=1;i<=n;i++){
            //当前的行列(row,i);
            //不能喝之前已经选择的列相同
            if(vis[i]==1) continue;
            //之前选择的行列(j,cols[j]);
            int flag=true;
            for(int j=1;j<cols.size();j++){
                //不能和之前选择的列在同一斜线上
                if(abs(j-row)==abs(cols[j]-i)){
                    flag=false; break;
                }
            }
            if(flag){
                vis[i]=1;
                cols.push_back(i);
                dfs(row+1,n,cols);
                cols.pop_back();
                vis[i]=0;
            }
        }
    }
};
```
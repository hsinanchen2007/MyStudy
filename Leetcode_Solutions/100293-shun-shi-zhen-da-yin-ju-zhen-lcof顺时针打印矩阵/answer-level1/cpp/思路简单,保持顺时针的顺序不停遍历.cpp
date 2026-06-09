### 解题思路
一直重复右，下，左，上的顺序直至所有相邻结点都已经被访问过后就返回

### 代码

```cpp
class Solution {
public:
    vector<int> ans;
    int vis[110][110];
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size()==0) return ans;
        int m=matrix.size();
        int n=matrix[0].size();
        memset(vis,0,sizeof(vis));
        bool flag=true;
        int i=0,j=0;
        vis[i][j]=1;
        ans.push_back(matrix[i][j]);
        
        while(flag){
            flag=false;
            //向右走到头
            while(j+1<n&&vis[i][j+1]==0){
                //flag=true表示还有路可走
                flag=true;
                j++;
                vis[i][j]=1;
                ans.push_back(matrix[i][j]);
            }
            while(i+1<m&&vis[i+1][j]==0){
                //flag=true表示还有路可走
                flag=true;
                i++;
                vis[i][j]=1;
                ans.push_back(matrix[i][j]);
            }

            while(j-1>=0&&vis[i][j-1]==0){
                //flag=true表示还有路可走
                flag=true;
                j--;
                vis[i][j]=1;
                ans.push_back(matrix[i][j]);
            }

            while(i-1>=0&&vis[i-1][j]==0){
                //flag=true表示还有路可走
                flag=true;
                i--;
                vis[i][j]=1;
                ans.push_back(matrix[i][j]);
            }
            //表示已经到了最终的结点
            if(!flag){
                return ans;
            }
        }
        return ans;
    }
};
```
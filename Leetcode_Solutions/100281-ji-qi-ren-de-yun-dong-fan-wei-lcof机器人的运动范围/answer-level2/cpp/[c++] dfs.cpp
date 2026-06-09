### 解题思路
从（0,0）开始， dfs遍历即可 ，需要设置访问数组

### 代码

```cpp
class Solution {
public:
    int res = 0;
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    
    int movingCount(int m, int n, int k) {
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        vis[0][0] = true;
         helper(0,0,m,n,k,vis);
         return res;
        
    }
    void helper(int i,int j,int m,int n,int target,vector<vector<bool>>& vis ){
        res++;
       
        for(int k=0;k<4;k++){
            int x = i+dir[k][0];
            int y = j+dir[k][1];
            if(x>=0 && x<m && y>=0 && y<n && !vis[x][y]){
                int tmp = 0,tx = x, ty = y;
                vis[x][y] = true;
                while(tx){
                    tmp+=tx%10;
                    tx/=10;
                }
                while(ty){
                    tmp+=ty%10;
                    ty/=10;
                }
                if(tmp<=target){
                    cout<<tmp<<"-";
                    helper(x,y,m,n,target,vis);
                }
            }
        }
        return ;
    }
};
```
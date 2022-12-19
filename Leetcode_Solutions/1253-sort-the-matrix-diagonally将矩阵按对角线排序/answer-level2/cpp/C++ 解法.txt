### 解题思路
取对角线排序再赋值
### 代码

```cpp
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        for(int i = 0;i<m-1;i++) sortmat( mat,0,i,m,n);
        for(int i = 1;i<n-1;i++) sortmat( mat,i,0,m,n);
        return mat;
    }
private: 
    void sortmat(vector<vector<int>>& mat,int x,int y,int m,int n){
        vector<int> ans;
        int x1 = x;
        int y1 = y;
        while(x1 <n && y1 < m){
            ans.push_back(mat[y1][x1]);
            x1++;
            y1++;
        }
        sort(ans.begin(),ans.end());
        int p = 0;
        while(x <n && y < m){
            mat[y][x] = ans[p++];
            x++;
            y++;
        }
    }
};
```
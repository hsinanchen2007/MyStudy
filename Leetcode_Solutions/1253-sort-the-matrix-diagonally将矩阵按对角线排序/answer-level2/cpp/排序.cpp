### 解题思路
![image.png](https://pic.leetcode-cn.com/4dc2dabe46c57bdd40ef49a857fcbc8d6f30c21d2cee538f17d8066856211fdb-image.png)

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        if(mat.size()==0)
        return mat;
        else if(mat[0].size()==0)
        return mat;
        int m=mat.size();
        int n=mat[0].size();
        map<int,vector<int>>mp;
        map<int,int>curr;
        for(int i=-n+1;i<=m-1;i++)
        {
            mp[i]=vector<int>();
            curr[i]=0;
        }
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<n;j++)
            {
                mp[i-j].push_back(mat[i][j]);
            }
        }
        for(int i=-n+1;i<=m-1;i++)
        {
            sort(&mp[i][0],&mp[i][0]+mp[i].size());
        }
        vector<vector<int>>re;
        for(int i=0;i<m;i++)
        {
            re.push_back(vector<int>());
            for(int j=0;j<n;j++)
            {
               re[i].push_back(mp[i-j][curr[i-j]++]);
            }
        }
        return re;
    }
};
```
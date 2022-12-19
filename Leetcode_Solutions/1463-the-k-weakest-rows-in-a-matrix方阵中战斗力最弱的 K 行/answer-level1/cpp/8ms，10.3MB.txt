### 解题思路
首先是统计战力值，这一步各题解大同小异
第二步我是让战力从i=0开始，到i=mat[0].size为止，符合条件就push_back,若b.size==k则return

### 代码

```cpp
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int i,j,m=mat.size(),n=mat[0].size(),a[m]={0};
        vector<int> b;
        
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
            {
                a[i]+=mat[i][j];
            }
        for(i=0;i<=n;i++)
        for(j=0;j<m;j++)
        {
            if(a[j]==i)
            {
             b.push_back(j);   
             if(b.size()==k) return b;
            }
        }
        return {0};
    }
};
```
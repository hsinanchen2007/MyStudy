### 解题思路
结构体存储行号及该行的军人数，通过sort的cmp对其实行排序

### 代码

```cpp
class Solution {
public:
    struct ass{
        int n;
        int m; 
    };
    static bool cmp(struct ass a,struct ass b){
        if(a.m!=b.m)
            return a.m<b.m;
        else
            return a.n<b.n;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        struct ass e[mat.size()];
        for(int i=0;i<mat.size();i++){
            e[i].n=i;
            int flag=0;
            for(int j=0;j<mat[i].size();j++)
                if(mat[i][j]==0){
                    e[i].m=j;
                    flag=1;
                    break;
                }
            if(flag==0)
                e[i].m=mat[i].size();
        }
        sort(e,e+mat.size(),cmp);
        vector<int> res;
        for(int i=0;i<k;i++)
            res.push_back(e[i].n);
        return res;
    }
};
```
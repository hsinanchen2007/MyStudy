![1111111111.JPG](https://pic.leetcode-cn.com/456e2107d7ad0f2d0d21a7b7c9d8794e6a870dc39ef5f9289b2e8b6c578cc287-1111111111.JPG)
第一次写题解
```
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1&&n==1)return 1;
        vector<vector<int>> res(m,vector<int>(n));//创建大小为m*n的数组
        for(int i=0;i<m;++i){
            res[i][0]=1;
        }
        for(int i=0;i<n;++i){
            res[0][i]=1;
        }
        for(int i=1;i<m;++i){
            for(int j=1;j<n;++j){
                res[i][j]=res[i][j-1]+res[i-1][j];
            }
        }
        return res[m-1][n-1];
    }
};

```


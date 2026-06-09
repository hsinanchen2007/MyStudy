### 解题思路
参考https://leetcode-cn.com/problems/spiral-matrix/solution/cxiang-xi-ti-jie-by-youlookdeliciousc-3/

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n==0) return {};
        vector<vector<int>> ans(n,vector<int>(n,n*n));
        int u = 0;
        int d = n-1;
        int l = 0;
        int r = n-1;
        int cur = 1;
        while(true){
            for(int i=l; i<=r; ++i) ans[u][i] = (cur++);
            if(++u>d) break;
            for(int i=u; i<=d; ++i) ans[i][r] = (cur++);
            if(--r<l) break;
            for(int i=r; i>=l; --i) ans[d][i] = (cur++);
            if(--d<u) break;
            for(int i=d; i>=u; --i) ans[i][l] = (cur++);
            if(++l>r) break;
        }
        return ans;
    }
};
```
### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
    vector<bool> col, diag1, diag2;
    int res = 0;
    // 尝试在第index行放皇后
    void dfs(int n, int index) {
        if (index == n) {
            res++;
            return;
        }
        for(int i = 0; i < n; i++) {
            if(!col[i] && !diag1[i+index] && !diag2[index-i+n-1]) {
                col[i]=true;
                diag1[index+i]=true;
                diag2[index-i+n-1]=true;
                dfs(n,index+1);
                col[i]=false;
                diag1[index+i]=false;
                diag2[index-i+n-1]=false;
            }
        }
        return;
    }
public:
    int totalNQueens(int n) {
        col = vector<bool>(n, false);
        diag1 = diag2 = vector<bool>(2*n-1, false);
        dfs(n,0);
        return res;
    }
};
```
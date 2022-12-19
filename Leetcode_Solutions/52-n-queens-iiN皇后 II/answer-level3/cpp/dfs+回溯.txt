### 解题思路
dfs搜索 回溯减短时间

### 代码

```cpp
class Solution {
public:
    int n;
    int C[111];
    int ans = 0;
    
    void nqueen(int cnt)
    {
        if (cnt == n)ans++;
        else
        {
            for (int i = 0; i < n; i++)
            {
                bool ok = true;
                
                C[cnt] = i;
                for (int j = 0; j < cnt; j++)
                    if (C[cnt]==C[j] || cnt-C[cnt]==j-C[j] || cnt+C[cnt]==j+C[j])
                    {
                        ok = false;
                        break;
                    }
                if (ok)nqueen(cnt+1);
            }
        }
    }
    int totalNQueens(int n) {
        this->n = n;
        nqueen(0);
        return ans;
    }
};
```
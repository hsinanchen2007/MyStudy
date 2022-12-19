### 解题思路
DFS，判断是否边界或能否被访问后，进入下个位置DFS.

### 代码

```cpp
class Solution {
public:
    int visited[100][100] = {0};
    int res = 0;
    int M = 0;
    int N = 0;
    int K = 0;
    int calculateK(int m,int n)
    {
        int k=0;
        while(m!=0)
        {
            k = k+m%10;
            m = m/10;
        }
        while(n!=0)
        {
            k = k+n%10;
            n = n/10;
        }
        return k;
    }

    void dfs(int m,int n)
    {
        if(calculateK(m,n)>K)
        {
            return;
        }
        res++;
        visited[m][n] = 1;
        if(m-1>=0&&visited[m-1][n]!=1) dfs(m-1,n);
        if(m+1<=M-1&&visited[m+1][n]!=1) dfs(m+1,n);
        if(n-1>=0&&visited[m][n-1]!=1) dfs(m,n-1);
        if(n+1<=N-1&&visited[m][n+1]!=1) dfs(m,n+1);

    }

    int movingCount(int m, int n, int k) {
        M = m;
        N = n;
        K = k;
        res = 0;
        dfs(0,0);
        return res;
    }
};
```
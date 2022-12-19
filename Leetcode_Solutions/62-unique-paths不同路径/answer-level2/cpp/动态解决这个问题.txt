### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        int a[m][n] = {0};
        if(m==1&&n==1) return 1;
        a[0][0]=0;
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(i==0 && j==0) continue;
                else if(i==0) a[i][j]=1;
                else if(j==0) a[i][j]=1;
                else a[i][j] = a[i-1][j]+a[i][j-1];
            }
        }
        return a[m-1][n-1];
    }
};
```
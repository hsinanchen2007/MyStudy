### 解题思路
用a[i][j]表示A个数为i，复制j个A时的步数，a[n][n]-1即为所求结果

### 代码

```cpp
class Solution {
public:
    int minSteps(int n) {
        int a[n+1][n+1]={0},i,j;
        a[1][1]=1;
        for(i=1;i<n+1;i++)
         for(j=1;j<=i;j++)
        {
            if(a[i][j]!=0&&i+j<=n)
            {
                if((a[i+j][j]==0)||a[i][j]<a[i+j][j])
                {
                    a[i+j][j]=a[i][j]+1;
                    if(a[i+j][i+j]==0||a[i+j][j]+1<a[i+j][i+j])
                    {
                        a[i+j][i+j]=a[i+j][j]+1;
                    }
                }
            }
        }
        return a[n][n]-1;
        
    }
};
```
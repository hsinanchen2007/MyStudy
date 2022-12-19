### 解题思路
1. 行坐标和列坐标的数位之和小于等于k、
2. 当前格子的左边格子或者上边格子可以移动到

满足上述两个条件，则表明当前格子可以移动到

### 代码

```cpp
class Solution {
public:
    int movingCount(int m, int n, int k) {
        int cnt = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==0 && j==0)
                {
                    cnt+=1;
                    visited[i][j] = true;
                } 
                else if(i==0 && j!=0 && cal_sum(j)<=k && visited[i][j-1])
                {
                    cnt+=1;
                    visited[i][j] = true;
                } 
                else if(j==0 && i!=0 && cal_sum(i)<=k && visited[i-1][j])
                {
                    cnt ++;
                    visited[i][j] = true;

                }
                else if(i>0 && j>0 &&cal_sum(i)+cal_sum(j)<=k && (visited[i-1][j] || visited[i][j-1]))
                {
                    cnt ++;
                    visited[i][j] = true;                   
                }
            }
        }
        return cnt;
    }
    int cal_sum(int m)
    {
        int s = 0;
        while(m>0)
        {
            s += m%10;
            m = m/10;
        }
        return s;
    }
};
```
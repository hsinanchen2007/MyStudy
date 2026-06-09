### 解题思路
1. 每个立方体ans+6
2. 上下贴面-2
3. 相邻贴面-1
4. 遍历每个位置
5. return ans
![image.png](https://pic.leetcode-cn.com/64fd7a6858ca88f9e48b10c39a14b1e3ea139335c78d07b296a4b4c181304967-image.png)

### 代码

```cpp
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int ans=0;
        int len=grid.size();
        for(int i=0;i<len;i++)
        {
            for(int j=0;j<len;j++)
            {
                ans+=grid[i][j]*6;
                if(grid[i][j]>0) ans-=(grid[i][j]-1)*2;
                if(i>0&&grid[i-1][j])
                {
                    ans-=min(grid[i-1][j],grid[i][j]);
                }
                if(i<len-1&&grid[i+1][j])
                {
                    ans-=min(grid[i+1][j],grid[i][j]);
                }
                if(j>0&&grid[i][j-1])
                {
                    ans-=min(grid[i][j-1],grid[i][j]);
                }
                if(j<len-1&&grid[i][j+1])
                {
                    ans-=min(grid[i][j+1],grid[i][j]);
                }
            }
        }
        return ans;
        

    }
};
```
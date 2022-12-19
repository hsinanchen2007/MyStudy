### 解题思路
思路很简单，创建一个二维的棋盘，机器人看看该点的范围是否超过了k，然后判断该点的左边和上边有没有被走过，如果没被走过，那也到不了这个点。

### 代码

```cpp
class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<int>> temp(m,vector<int>(n,0));
        int count = 1;
        temp[0][0] = 1;
        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if((i % 10 + i / 10 + j % 10 + j / 10) <= k)//该点是小于k的情况
                {
                    if(i >= 1 && temp[i-1][j] == 1)//判断他的左边或者上面是否被走过
                    {
                        temp[i][j] = 1;
                        count += 1;
                        continue;
                    }
                    if(j >= 1 && temp[i][j - 1] == 1)
                    {
                        temp[i][j] = 1;
                        count += 1;
                        continue;
                    }
                }
            }
        }
        return count;
    }
};
```
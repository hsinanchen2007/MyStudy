
简单题，直接遍历每个格子，位数之和不能大于k那也就是 **条件1: i%10 + i/10 + j%10 + j/10 <= k**
注意机器人只能四个方向移动，那么第i,j个格子能到达的必要条件还有一个:**条件2: map[i-1][j] || map[i][j-1]** (从小到大遍历的话，只能从上面或者左边来)
满足两个条件，即可标记 `map[i][j] = 1` 然后答案+1
注意初始条件:`map[0][0] = 1`,因此答案最小是1

```
class Solution {
public:
    int movingCount(int m, int n, int k) {
        int count = 1;
        int map[100][100]= { 0 };
        map[0][0] = 1;   //第一个格子必定可以到
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(i==0&&j==0) continue;
                if(i%10 + i/10 + j%10 + j/10 <= k )
                    if((i>0 && map[i-1][j]) || (j>0 && map[i][j-1]))
                    {
                        map[i][j]=1;
                        count++;
                    }
            }
        return count;
    }
};
```

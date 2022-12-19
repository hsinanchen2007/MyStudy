### 解题思路
个人比较喜欢递推写法，所以写了递推版动态规划而不是记忆搜索类型。
首先judge函数帮我们求出两个下标的每位数字之和，方便以后判断是否大于K；
接着分析状态转移方程，一般坐标型动态规划都开一个二维数组，这道题也不例外，我们开 bool 类型数组
 dp[m][n] 来表示机器人是否能到达这个格子，能到达这个格子的条件是：
1.这个格子的上面或者左面的格子可以到达，在这里我们省略了两个方向，因为我们递推这个数组的时候i,j都是从小到大，所以省略了两个方向。
2.judge(i,j)<=k，满足这两个条件，就可以认定这个格子可以到达。
下面给出状态转移方程：
dp[m][n] = (dp[m-1][n] || dp[m][n-1]) && judge(i,j)<=k
            左边可到达 或者 右边可到达       位数字和不大于k
在递推每个格子的状态的时候，同时记录一共有多少个格子可到达，递推之后判断一下如果这个格子可到达，就在总数上加一；
初始条件 dp[0][0] = true;
计算顺序 m 从 0 到 m    n 从 0到n
边界条件 当m等于0的时候，也就是说左边就是墙了，所以就不用考虑左边了，同理n等于0也是

滚动数组优化：其实也没这个必要...因为优化也是从O(mn)优化到O(n) (外层遍历m 内层遍历n的时候，反之则优化到O(m)) ,由于不确定n 和m 那个比较小所以优化效果不稳定，（6.2MB -> 5.9MB）。我们发现在确定格子的状态的时候是先确定一列格子，再确定一列，并且格子的状态只与前一列和上一个格子有关，所以数组不用开
dp[m][n] 可以优化成dp[2][n] ，设置两个数字分别代表新的一列和旧的一列，这两列来回交替即可~~

### 代码

```cpp
class Solution {
    int judge(int x,int y)
    {
        int ans = 0;
        while(x!=0)
        {
            ans+=x%10;
            x = x/10;
        }
        while(y!=0)
        {
            ans+=y%10;
            y = y/10;
        }
        return ans;
    }
public:
    int movingCount(int m, int n, int k) {
        int ans = 0;

        bool dp[2][n];
        int old = 0,N = 1;

        for(int i=0;i<m;++i)
        {   
            old = N;
            N = 1-N;
            for(int j=0;j<n;++j)
            {
                dp[N][j] = false;
                if(i==0 && j==0)
                {
                    dp[N][j] = true;
                    ++ans;
                    continue;
                }
                if(i==0)
                {
                    dp[N][j] = dp[N][j-1] && (judge(i,j)<=k);
                    if(dp[N][j])    ++ans;
                    continue;
                }
                if(j==0)
                {
                    dp[N][j] = dp[old][j] && (judge(i,j)<=k);
                    if(dp[N][j])    ++ans;
                    continue;
                }
                dp[N][j] = (dp[old][j] || dp[N][j-1]) && (judge(i,j)<=k);
                if(dp[N][j])    ++ans;
            }
        }

        return ans;
    }
};
```
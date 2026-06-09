不骗你，真的就是自底向上！

思路：从三角形的底部开始走回三角形的顶部

分析：
1. 对于除了三角形底部的节点来说，它到达下一层的最短路径就是选下一层中离他最近的邻居——状态转移。
2. 三角形底部节点就只能自己和自己走动了...——边界条件（1）
3. 于是从底部往顶部走，我们知道了从终点到起点的所有结果。 
...
4. 留给第一层的节点不多了！到底是选左边邻居还是右边邻居呢？-> step 1.

代码：
```
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        if(!m) return 0;
        int n = triangle[m-1].size();
        vector<int> dp(n, INT_MAX);
        for(int i=m-1; i>=0; i--)
            for(int j = 0; j<triangle[i].size(); j++)
            {
                if(i == m-1)
                    dp[j] = triangle[i][j];
                else
                    dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
            }
        return dp[0];
    }
};
```
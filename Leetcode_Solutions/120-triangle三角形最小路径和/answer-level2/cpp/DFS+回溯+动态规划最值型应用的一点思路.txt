最容易想到的是遍历所有路径,用到的是搜索算法-深度优先搜索,需要记录层数信息,路径值，下一行中相邻的结点**索引**
因此分别设置**depth，value，index变量**，value还运用到了回溯算法的思想
```
    int min = INT_MAX;
    void dfs(vector<vector<int>>& triangle, int depth, int value, int index)
    {
        if(depth < triangle.size()) 
        {
            if(depth == triangle.size() - 1 && value + triangle[depth][index] < min) min = value + triangle[depth][index];
            dfs(triangle, depth + 1, value + triangle[depth][index], index);
            dfs(triangle, depth + 1, value + triangle[depth][index], index + 1);
        }
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        dfs(triangle, 0, 0, 0);
        return min;
    }
```
不用说，这种方法必定超时,但是方法和思路值得借鉴
吐槽一下，被绊倒在倒数第二个测试用例，巨尼玛长.. :-D

因此能引出第二种方法，DP大法，对于最值型的问题，可以考虑DP，基本思路都是"备忘录"记录着上一步的最值，求当前的最值
DP最重要一步是先写出状态转移方程
此题状态转移方程为 dp[x][index] = dp[x - 1][index] + min(triangle[x][index], triangle[x][index + 1])(自顶先下)
我是自底向上,这样有什么好处呢？利用原数组不用开新的空间   
因此可以把状态转移方程写成这样
triangle[x - 1][index] = triangle[x][index] + min(triangle[x][index], triangle[x][index + 1])
```
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i = triangle.size() - 1; i >= 1; i--)
            for(int j = 0; j < triangle[i - 1].size(); j++)
                triangle[i - 1][j] = triangle[i - 1][j] + min(triangle[i][j], triangle[i][j + 1]);
        return triangle[0][0];  
    }
```
考虑特殊边界问题（只有一行），循环执行条件是两行或以上，不满足条件所以直接返回triangle[0][0]
所以此代码符合，完美代码~
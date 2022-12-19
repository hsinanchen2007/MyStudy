给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。

```
例如，给定三角形：

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
```
> 如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。

**使用二维数组的dp动态规划**
`dp[i][j]`表示走到第i行j列的最小路径和
则转移方程 `dp[i][j] = min(dp[i-1][j-1],dp[i-1][j])+triangle[i][j];` 因为只能上一层的左和右两个元素可以走到`[i][j]`
> 需要考虑左右两侧的特俗情况  左右两侧只有固定的路径可达
```c
// 216 三角形最小路径和
int minimumTotal(vector<vector<int>>& triangle) {
    int row = triangle.size();
    if(row==0) return 0;
    int col = triangle[row-1].size();

    vector<vector<int>> dp(row+1,vector<int> (col+1,INT32_MAX));
    dp[0][0] = triangle[0][0];

    int min_val = INT32_MAX;
    for(int i=1;i<row;i++){
        int col_ = triangle[i].size();
        for(int j=0;j<col_;j++){
            if(j==0) {
                dp[i][j] = dp[i-1][j]+triangle[i][j];
            }else if(j==col_-1){
                dp[i][j] = dp[i-1][j-1]+triangle[i][j];
            }else{
                dp[i][j] = min(dp[i-1][j-1],dp[i-1][j])+triangle[i][j];
            }
        }
    }
    for(int j=0;j<col;j++){
        min_val = min(min_val,dp[row-1][j]);
    }
    return min_val;
}


```

**压缩状态方程空间O(n)**
>其实我们dp时候每次只用到上一层数据,如果我们倒着,从底向上可以优化成O(n)空间的

```bash
           |= triangle[n-1,c]       if n-1 is the last row. 
f(n-1, c) -|
           |= min{f(n,c) + triangle[n-1,c], f(n,c+1) + triangle[n-1,c]}


/*input
     *  {{2},
        {3,4},
       {6,5,7},
      {4,1,8,3}};
如果正序遍历的话, dp[j] = dp[j],dp[j-1] , 因为计算当前层 dp[j]需要用到 上一层的dp[j-1] 和 上一层的dp[j], 但是dp[j-1]已经更新为当前层的值, 
 而在计算当前层的dp[j]时,需要用到上一层的dp[j-1],但是计算当前层dp[j]前,已经更新过dp[j-1],可以从下面结果中看出

 * 2  \  \  \
 * 5  9  \  \
 * 11 14 21 \
 * 15 15 23 26
 * 
 * 倒序的话,dp[j] = min(dp[j],dp[j+1]), dp[j](当前层,更新) = dp[j](上一层.未更新),dp[j+1](上一层,未更新)
 * 计算当前层dp[j] 需要用到 上一层的dp[j] 和 dp[j+1], 相当于dp[j] 更新为当前层值,dp[j+1] 等待下一个迭代更新
 * 
 * */
```



```c
int minimumTotal(vector<vector<int>>& triangle) {
    int row = triangle.size();
    if(row==0) return 0;

    vector<int> dp(row,0);
    for(int i=0;i<row;i++)
        dp[i] = triangle[row-1][i];

    for(int i=row-2;i>=0;i--){
    //
        for(int j=0;j<i+1;j++){
            dp[j] = min(dp[j],dp[j+1]) + triangle[i][j];
        }
    }
    return dp[0];
}


```
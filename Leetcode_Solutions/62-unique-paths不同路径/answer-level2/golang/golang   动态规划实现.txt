```go
/**
 1. 定义状态 dp[i][j] 为当前 i*j 的路径总数
 2. 递推方程 dp[i][j] = dp[i-1][j]+dp[i][j-1]
 3. 状态初始化 dp[i][1]=1 dp[1][j]=1
 4. 最终结果  dp[m-1][n-1]
 5. 优化每次仅用到 dp[i-1][j] 和 dp[i][j-1] 所以可将dp优化为一个一维数组中:cur[j] += cur[j-1]
     a) cur 长度取 n 防止溢出
     b) 方程为 cur[j] += cur[j-1] 等价于 cur[j] = cur[j] + cur[j-1] cur[i]每行遍历只更新一次,也就是说cur[j]原有的值代表的是上一行p[i-1],[j]的值,而cur[j-1] 是在本行遍历刚更新过的值因此是dp[i][j-1]的值!
*/
func uniquePaths(m int, n int) int {
   cur := make([]int,n)
   for i:=0;i<n;i++{
       cur[i] = 1
   }
   for i:=1;i<m;i++{
       for j:=1;j<n;j++{
         cur[j] += cur[j-1]
       }
   }
   return cur[n-1]
}
```

## 方法1，典型动态规划

### 解题思路
此题和之前的“抢劫”题很像，是一个动态规划的典型题目。  
对于每个预约，只能选择接或不接。  
如果接，则上一个状态必须是不接。  
如果不接，上一个状态可以是接，也可以不接。  

每个点有两个状态（接，不接），因此需要定义一个二维数组用于存储。  

因此，dp方程是：  
dp[k][接] = dp[k-1][不接] + nums[k]  
dp[k][不接] = max(dp[k-1][接],dp[k-1][不接])  

### 代码

```golang
func massage(nums []int) int {
    n:= len(nums)
    if n == 0 {
        return 0
    }
    dp := make([][]int,n )
    for i := range dp {
        dp[i] = make([]int,2) // [0]定义为接，[1]定义为不接
    }
    dp[0][0]= nums[0]
    dp[0][1] = 0
    max := func (a,b int) int{
        if a>b{
            return a
        }
        return b
    }
    for i:=1;i<n;i++{
        dp[i][0] = dp[i-1][1] + nums[i]
        dp[i][1] = max(dp[i-1][0],dp[i-1][1])
    }
    return max(dp[n-1][0],dp[n-1][1])
}
```
### 复杂度分析
时间，空间复杂度都是 O(N)

## 方法2，空间优化的动态规划

### 解题思路
对于dp问题，如果题目要求不用保存历史记录，可以把空间从O(N)简化至O(1). 用二维数组的好处是，可以得到所有时间点的最优解。而本题只要最终解。所以可以仅用两个变量解决问题。

### 代码
```golang
func massage(nums []int) int {
    n:= len(nums)
    if n == 0 {
        return 0
    }
    work := nums[0]
    rest := 0
    max := func (a,b int) int{
        if a>b{
            return a
        }
        return b
    }
    for i:=1;i<n;i++{
        work,rest = rest+nums[i], max(work,rest) // 这里使用了go的连续赋值特性，可以省掉声明一个中间变量。如果是JAVA，就必须声明中间变量了
    }
    return max(work,rest)
}
```

### 复杂度分析
时间复杂度是 O(N)， 空间复杂度为O(1)

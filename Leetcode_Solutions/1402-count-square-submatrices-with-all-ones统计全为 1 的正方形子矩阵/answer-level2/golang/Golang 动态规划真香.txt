- 同样借用两个动态规划可以解题

## 有多少个连续的1

- 设nums[i][j]为从nums[i][0]开始以nums[i][j]结尾的连续1的个数
- 初始值：nums[i][0] = matrix[i][0]
- 状态转移：
    - matrix[i][j] == 0时，nums[i][j]=0
    - 否则nums[i][j]=nums[i][j-1]+1

## 有多少个包含1的正方形矩阵

- 设dp[i][j]为前面i行以及dp[i][0]到dp[i][j]组成的图形中包含的正方形个数
- 初始值 dp[0][0]=matrix[0][0]; dp[0][i]=dp[0][i-1]+matrix[0][i] (i>0)
- 状态转移： i>0,n为matrix数组的列数
    - dp[i][0] = dp[i-1][n-1] + matrix[i][0]
    - 当matrix[i][j] == 0 时，dp[i][j] = dp[i][j-1]
    - 否则 dp[i][j] = dp[i][j-1] + 以matrix[i][j]为右下角的正方形的个数
        求解需要用到nums数组


## 代码实现

    func countSquares(matrix [][]int) int {
        if matrix == nil || len(matrix) == 0 {
            return 0
        }
        m := len(matrix)
        n := len(matrix[0])
        dp := make([][]int, m)
        nums := make([][]int, m)
        for i:=0;i<m;i++{
            dp[i] = make([]int, n)
            nums[i] = make([]int, n)
        }
        dp[0][0],nums[0][0] = matrix[0][0],matrix[0][0]
        for i:=1;i<n;i++ {
            dp[0][i] = dp[0][i-1]
            nums[0][i] = 0
            if matrix[0][i] == 1 {
                dp[0][i]++
                nums[0][i] = nums[0][i-1] + 1
            } 
        }
        for i:=1;i<m;i++ {
            dp[i][0] =dp[i-1][n-1] + matrix[i][0]
            nums[i][0] = matrix[i][0]
            for j:=1;j<n;j++ {
                if matrix[i][j] == 0 {
                    nums[i][j] = 0
                    dp[i][j] = dp[i][j-1]
                } else {
                    nums[i][j] = nums[i][j-1] + 1
                    dp[i][j] = dp[i][j-1]+1
                    minWid := nums[i][j]
                    for k:=2;k<=min(i+1,nums[i][j]);k++ {
                        if k > minWid {
                            break
                        }
                        if nums[i-k+1][j] >= k {
                            dp[i][j]++
                        } else {
                            break
                        }
                        minWid = min(minWid,nums[i-k+1][j])
                    }
                }
            }
        }
        return dp[m-1][n-1]

    }

    func min(a,b int) int {
        if a < b {
            return a
        }
        return b
    }
### 解题思路
自顶向下，记忆最优结果，取最小值

### 代码
python
```python 2

class Solution(object):
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        if not triangle:
            return 0
        dp = [[0 for j in range(len(i))] for i in triangle]
        dp[0][0] = triangle[0][0]
        #处理左边边
        for i in range(1,len(triangle)):
            dp[i][0] += dp[i-1][0] + triangle[i][0]
        #处理右边边
        for j in range(1,len(triangle)):
            dp[j][-1] += dp[j-1][-1] + triangle[j][-1]
        #处理中间
        if len(triangle)>2:
            for i in range(2,len(triangle)):
                for j in range(1,len(triangle[i])-1):
                    dp[i][j] += min(dp[i-1][j-1],dp[i-1][j])+triangle[i][j]
        return min(dp[-1])
```


golang
``` go
func minimumTotal(triangle [][]int) int {
	n := len(triangle)
	if n == 0{
		return 0
	}
	var dp = make([][]int,n)
	for i,v := range triangle{
		dp[i] = make([]int,len(v))
	}
	dp[0][0] = triangle[0][0]
	for i:=1;i<n;i++{
		dp[i][0] += dp[i-1][0] + triangle[i][0]
	}
	for j:=1;j<n;j++{
		dp[j][len(triangle[j])-1] += dp[j-1][len(triangle[j-1])-1] + triangle[j][len(triangle[j])-1]
	}
	if n > 2{
		for i:=2;i<n;i++{
			for j:=1;j<(len(triangle[i])-1);j++{
				dp[i][j] += min(dp[i-1][j-1],dp[i-1][j])+triangle[i][j]
			}
		}
	}
	return minArr(dp[n-1])
}

func min(a,b int)int{
	if a > b{
		return b
	}
	return a
}

func minArr(l []int) (min int) {
	min = l[0]
	for _, v := range l {
		if v < min {
			min = v
		}
	}
	return
}
```
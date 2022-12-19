### 解题思路
考虑当前数字只能跟下一行的最多相隔一列相加，那么
左边界的转移方程为：A[i][j] + min(dp[i+1][j],dp[i+1][j+1])
右边界的转移方程为：A[i][j] + min(dp[i+1][j-1],dp[i+1][j])
剩下数字（中间）的转移方程为：A[i][j] + min(dp[i+1][j-1],min(dp[i+1][j],dp[i+1][j+1]))

### 代码
go
```golang
func minFallingPathSum(A [][]int) int {
	n := len(A)
	if n==0{
		return 0
	}
	var dp = make([][]int,n)
	for i,_:= range dp{
		dp[i] = make([]int,n)
	}
	dp[n-1] = A[n-1]
	for  i:= n-2;i>=0;i--{
		for j:=0;j<n;j++{
			if j-1 < 0{
				dp[i][j] = A[i][j] + min(dp[i+1][j],dp[i+1][j+1])
			}else if( j+1 == n){
				dp[i][j] = A[i][j] + min(dp[i+1][j-1],dp[i+1][j])
			}else{
				dp[i][j] = A[i][j] + min(dp[i+1][j-1],min(dp[i+1][j],dp[i+1][j+1]))
			}
		}
	}
	sort.Ints(dp[0])
	return dp[0][0]
}

func min(a,b int)int{
	if a > b{
		return b
	}
	return a
}
```

python

```python
class Solution(object):
    def minFallingPathSum(self, A):
        """
        :type A: List[List[int]]
        :rtype: int
        """
        if not A:
            return 0
        n = len(A)
        dp = [[0 for i in range(n)] for j in range(n)] 
        dp[-1] = A[-1]
        for i in range(n-2,-1,-1):
            for j in range(0,n):
                #左边界
                if j-1 < 0:
                    dp[i][j] = A[i][j] + min(dp[i+1][j],dp[i+1][j+1])
                #右边界
                elif j+1 == n:
                    dp[i][j] = A[i][j] + min(dp[i+1][j-1],dp[i+1][j])
                #中间
                else:
                    dp[i][j] = A[i][j] + min(dp[i+1][j-1],dp[i+1][j],dp[i+1][j+1])
        return min(dp[0])
```

java
```java
	public int minFallingPathSum(int[][] A) {
		int n = A.length;
		if (n==0){
			return 0;
		}
		int[][] dp = new int[n][n];
		dp[n-1] = A[n-1];
		for (int i= n-2;i>=0;i--){
			for (int j=0;j<n;j++){
				if (j-1 < 0){
					dp[i][j] = A[i][j] + Math.min(dp[i+1][j],dp[i+1][j+1]);
				}else if(j+1 == n){
					dp[i][j] = A[i][j] + Math.min(dp[i+1][j-1],dp[i+1][j]);
				}else{
					dp[i][j] = A[i][j] + Math.min(dp[i+1][j-1],Math.min(dp[i+1][j],dp[i+1][j+1]));
				}
			}
		}
		
		
		Arrays.sort(dp[0]);
		return dp[0][0];
    }
```

## 动态规划三部

设dp[i][j]表示p[:i]能否正则匹配s[:j]，m为p的长度，n为s的长度，则dp[m][n]即为所求

### 状态转移方程

1. `p[i-1] == s[j-1] || p[i-1] == '.'`时, `dp[i][j] = dp[i-1][j-1]`
2. `dp[i-1]=='*'`时，分两种情况
    a. `p[i-2] == s[j-1] || p[i-2] == '.'`时, `dp[i][j] = dp[i][j-1] || dp[i-2][j-1] || dp[i-2][j]`
    b. 否则，`dp[i][j] = dp[i-2][j]`

### 初始值

可以确定dp[i][0], dp[0][j]得值

求解dp[0][j]
1. 当j=0时，`dp[0][0]=true`
2. 否则`dp[0][j]=false`

求解dp[i][0]
1. 当i为基数时，`dp[j][0]=false`
2. 当i为偶数时并且`p[i-1] == '*'`时，`dp[i][0]=dp[i-2][0]`


## 代码

    func isMatch(s string, p string) bool {
    	m, n := len(p)+1, len(s)+1
    	dp := make([][]bool, m)
    	for i := 0; i < m; i++ {
    		dp[i] = make([]bool, n)
    	}
    	
    	//初始值
    	dp[0][0] = true
    	for i:=2;i<m;i++ {
    		if i % 2 == 0 && p[i-1] == '*'{
    			dp[i][0] = dp[i-2][0]
    		}
    	}
    
    	for i := 1; i < m; i++ {
    		for j := 1; j < n; j++ {
    			if p[i-1] == s[j-1] || p[i-1] == '.' {
    				dp[i][j] = dp[i-1][j-1]
    			} else if p[i-1] == '*' {
    				if i > 1 { //防止脚标越界
    					if p[i-2] == s[j-1] || p[i-2] == '.' {
    						dp[i][j] = dp[i][j-1] || dp[i-2][j-1] || dp[i-2][j]
    					} else {
    						dp[i][j] = dp[i-2][j]
    					}
    				}
    			}
    		}
    	}
    	return dp[m-1][n-1]
    }
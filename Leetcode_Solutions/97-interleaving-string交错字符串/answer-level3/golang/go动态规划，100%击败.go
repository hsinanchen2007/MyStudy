![image.png](https://pic.leetcode-cn.com/9e27dd1975bd7b1dd9c58fbf3ffb6fa0a5c2729a909f8495280261c8bacf9d03-image.png)

```
if len(s1)+len(s2) != len(s3) {
		return false
	}
	s1 = "#" + s1
	s2 = "#" + s2
	s3 = "#" + s3
	dp := make([][]bool, len(s1))
	for i := 0; i < len(s1); i++ {
		dp[i] = make([]bool, len(s2))
	}
	// 0,j
	dp[0][0] = true
	for j := 1; j < len(s2); j++ {
		if dp[0][j-1] && s2[j] == s3[j] {
			dp[0][j] = true
		} else {
			break
		}
	}
	for i := 1; i < len(s1); i++ {
		if dp[i-1][0] && s1[i] == s3[i] {
			dp[i][0] = true
		} else {
			break
		}
	}
	for i := 1; i < len(s1); i++ {
		for j := 1; j < len(s2); j++ {
			if dp[i][j-1] && s2[j] == s3[i+j] {
				dp[i][j] = true
			}
			if !dp[i][j] && dp[i-1][j] && s1[i] == s3[i+j] {
				dp[i][j] = true
			}
		}
	}
	return dp[len(s1)-1][len(s2)-1] 
```

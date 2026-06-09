看了解答区的大佬的[思路](https://leetcode-cn.com/problems/generate-parentheses/solution/zui-jian-dan-yi-dong-de-dong-tai-gui-hua-bu-lun-da/)后才恍然大悟，膜拜的同时用go 写了一遍

代码：

```go [go]

func generateParenthesis(n int) []string {
	if n ==0 {
		return nil
	}

	var result = make([][]string,n+1)
	result[0] = []string{""}
	result[1] = []string{"()"}

	for i := 2; i < n+1; i++ {
		for j := 0; j < i; j++ {
			for _, str1 := range result[j] {
				for _, str2 := range result[i-1-j] {
					el := "("+str1+")"+str2
					result[i] = append(result[i],el)
				}
			}
		}
	}

	return result[n]
}
```
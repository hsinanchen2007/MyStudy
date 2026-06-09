### 解题思路
此处撰写解题思路

### 代码

```golang

// 131. 分割回文串 https://leetcode-cn.com/problems/palindrome-partitioning/
func partition(s string) [][]string {

	curList := make([]string, 0)
	result := make([][]string, 0)
	dfs(curList, s, &result)
	return result

}

func dfs(curList []string, left string, result *[][]string) {

	if left == "" {
		tmp := make([]string, len(curList))
		copy(tmp, curList)
		*result = append(*result, tmp)
		return
	}

	for i := range left {

		if ispalindrome(left[:i+1]) {
			dfs(append(curList, left[:i+1]), left[i+1:], result)
		}

	}

	return
}

func ispalindrome(s string) bool {
	count := len(s)
	if count == 1 {
		return true
	}
	for i := 0; i < count/2; i++ {
		if s[i] != s[count-i-1] {
			return false
		}
	}

	return true
}

```
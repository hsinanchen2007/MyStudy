### 解题思路
这中排列组合问题，用dfs可以很容易得到答案，对go还不太熟，之前一直以为参数用slice传递和cpp中的引用类似，今天才发现不完全是这样。想要修改传递进来的slice的内容，需要通过指针才行，具体的大家可以自己查查资料。

### 代码

```golang
func letterCombinations(digits string) []string {
    if digits == "" {
		return nil
	}
    letters := []string{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs","tuv", "wxyz"}

    ans := make([]string, 0)
    dfs(digits, 0, letters, "", &ans)
    return ans
}

func dfs(digits string, loc int, letters []string, cur string, ans *[]string) {
    if loc == len(digits) {
        *ans = append(*ans, cur)
        return
    }

    for _, ch := range letters[int(digits[loc] - '0')] {
        dfs(digits, loc + 1, letters, cur + string(ch), ans)
    }
}
```
### 解题思路
map计算每个字母的出现次数
偶数的直接求和，
非1奇数的减掉一就是偶数。
回文有奇数和偶数两种情况。
偶数的情况：即都是偶数没有1个奇数的字母，判断是否存在一个字母的情况，没有，直接求和即可。
奇数情况的回文：计算完偶数后，判断是否存在一个字母的情况（奇数个字母的也算有）
在和的基础上加1即可。

### 执行结果
执行用时 :0 ms, 在所有 Go 提交中击败了100.00%的用户
内存消耗 :2.2 MB, 在所有 Go 提交中击败了17.24%的用户
### 代码

```golang
func longestPalindrome(s string) int {
	if len(s) == 0 {
		return 0
	}
	sMap := generateMap(s)
	var count = 0
	var max = 0
	var isExist = false
	for _, v := range sMap {
		if v%2 == 0 {
			count += v
		}
		if v == 1{
			isExist = true
		}
		if v % 2 == 1 && v > 1 {
			isExist = true
			max += v-1
		}
	}
	if isExist{
		return count+max+1
	}
	return count + max
}

func generateMap(S string) map[string]int {
	m := make(map[string]int)
	for _, v := range S {
		m[string(v)] = m[string(v)] + 1
	}
	return m
}
```
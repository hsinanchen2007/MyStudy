### 解题思路
思路：遍历，map统计字符出现次数：相同字符出现次数为偶数，直接累加；为奇数，-1；如果存在奇数的情况，总数再+1。
ps：数组比map内存小

### 代码

```golang
func longestPalindrome(s string) int {
	//occurrence := make([]int, 52)
	var occurrence [52]int
	//occurrence := [52]int{}

	for i := 0; i < len(s); i++ {
		//'a' > 'A'
		if 'a' <= s[i] {
			occurrence[s[i]-'a' + 26] += 1
		}else {
			occurrence[s[i]-'A'] += 1
		}
	}

	sum := 0
	flag := false
	for _, occ := range occurrence {
		if occ%2 == 0 {
			sum += occ
		}else {
			flag = true
			sum += occ - 1
		}
	}
	if flag {
		sum++
	}
	return sum
}
```
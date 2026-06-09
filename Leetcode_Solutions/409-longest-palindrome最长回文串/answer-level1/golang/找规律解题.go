### 解题思路
回文字符串中，要么所有的元素都是偶数个，要么有一个元素是奇数个，可以根据这一点建立一个 map 来索引原始字符串中所有的元素。  
然后遍历该 map 找出可以得到的最长出现次数为偶数的元素个数 `r`，如果 map 中有出现奇数次的元素，那么最后返回结果时 `r+1`  

### 代码

```golang
func longestPalindrome(s string) int {
	var cases = make(map[string]int)
	for i := 0; i < len(s); i++ {
		c := string(s[i])
		if _, ok := cases[c]; ok {
			cases[c] += 1
		} else {
			cases[c] = 1
		}
	}

	var result int
	var maxOdd int
	for _, v := range cases {
		if v%2 == 0 {
			result += v
		} else if v-1 >= 2 {
			result += v - 1
			maxOdd = 1
		} else {
			maxOdd = 1
		}
	}
	return result + maxOdd
}
```
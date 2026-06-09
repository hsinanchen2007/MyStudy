### 解题思路

判断字符串个数 如果是偶数直接作为长度相加 如果是奇数 则取偶数部分 因为go 除法运算int类型只会获取整数部分，所以直接可以计算

最后判断整体长度 如果小于s 则可以判断到还有个奇数的可以+1 

### 代码

```golang
func longestPalindrome(s string) int {
if len(s) <= 0 {
		return 0
	}

	strmap := make(map[byte]int)

	for i:=0; i<len(s); i++ {
		strmap[s[i]]++
	}

	maxsize :=0

	for _ , v := range strmap {
		maxsize += (v / 2) * 2
	}

	if(len(s) > maxsize) {
		maxsize++
	}
	return maxsize

}
```
### 解题思路
从前后开始遍历，调换i,j位置的值，直到 i <= j

### 代码

```golang
func reverseString(s []byte) {
	j := len(s) - 1
	for i := 0; i < j; i++ {
		s[i], s[j] = s[j], s[i]
		j--
	}
}

```
### 解题思路
golang的byte操作性能远远高于操作string的性能

其余不再赘述

### 代码

```golang
func lengthOfLongestSubstring(s string) int {
    val := []byte(s)
    var valLen = len(val)
    var first = 0
	var byteArray = make([]int, 128)
	var maxLen = 0
	var l = 0
	for i := 0; i< valLen;i ++ {
		if byteArray[val[i]] >= first {
			first = byteArray[val[i]]
		}
		byteArray[val[i]] = i + 1
		l = i - first + 1
		if l > maxLen {
			maxLen = l
		}
	}
	return maxLen
}
```
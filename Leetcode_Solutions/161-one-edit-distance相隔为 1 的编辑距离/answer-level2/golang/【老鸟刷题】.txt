### 解题思路
两个字符串必须满足：长度相等或者相差一，两种情况分别处理
1）长度相等，则必须满足有一个不相等的字符
2）长度相差一，遍历较短的字符串A，如果A串某个位置i的字符与B串不等，则余下的字符必须与B串对应位置+1的字符一一相等

### 代码

```golang
func isOneEditDistance(s string, t string) bool {
	var longStr string
	var shortStr string
	if len(s) > len(t) {
		longStr = s
		shortStr = t
	}else {
		longStr = t
		shortStr = s
	}
	if len(s) != len(t) && len(longStr) - len(shortStr) != 1 {
		return false
	}
	if s == t {
		return false
	}
	
	if len(s) == len(t) {
		cnt := 0
		for i:=0; i<len(s); i++ {
			if s[i] != t[i] {
				cnt ++
			}
			if cnt >= 2 {
				return false
			}
		}
		return true
	}

	notEquelCnt := 0
	for i:=0; i<len(shortStr); i++ {
        if shortStr[i] != longStr[i+notEquelCnt] {
        	if notEquelCnt == 0 {
				if shortStr[i] != longStr[i+1] {
					return false
				}
			}
        	notEquelCnt++
        	if notEquelCnt > 1 {
        		return false
			}
		}
	}
	return true
}
```
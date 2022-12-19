### 解题思路
解题思路：
1. 取needle长度lenN, haystack长度lenH
2. 循环(lenH - lenN) 次，每次截取haystack[i:i+lenN]字符串，与needle比对是否相等

> 注意先剔除特殊情况

### 代码

```golang
func strStr(haystack string, needle string) int {
    // 判断特殊情况
	lenH, lenN := len(haystack), len(needle)

	if lenN == 0 {
		return 0
	}

	if lenN > lenH {
		return -1
	}

	if haystack == needle {
		return 0
	}

	for i := 0; i <= lenH-lenN; i++ {
		if haystack[i:i+lenN] == needle {
			return i
		}
	}

	return -1
}
```
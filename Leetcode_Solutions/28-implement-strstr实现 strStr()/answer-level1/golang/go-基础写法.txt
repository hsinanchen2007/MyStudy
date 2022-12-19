### 解题思路
1.利用for循环进行解答
2.特殊条件取出，避免进入for循环
3.可利用切片进行比较

### 代码

```golang
func strStr(haystack string, needle string) int {
	if needle == "" {
		return 0
	}
	if haystack == needle {
		return 0
	}
	lennum := len(needle)
	if len(haystack) < lennum {
		return -1
	}
	ld := 0
	for i := lennum; i <= len(haystack); i++ {
		if haystack[ld:i] == needle {
			return ld
		}
		ld++
	}
	return -1
}
```
###运行结果
![1.png](https://pic.leetcode-cn.com/9f29218d201ca375eb58048eba8a24e2fc0e899b9a417c67c6c9773e85a2312d-1.png)

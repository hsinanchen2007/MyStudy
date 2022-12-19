### 解题思路

- 1,分割字符串为字符串数组
- 2，用`for range`反转字符串数组
- 3，将反转后的字符串数组再拼接成一个完整的字符串并返回

### 代码

```golang
import "strings"

func reverseWords(s string) string {
	var reserseSeg []string
	//分割字符串
	seg := strings.Fields(s)
	//反转字符串数组
	for i := len(seg) - 1; i >= 0; i-- {
		reserseSeg = append(reserseSeg, seg[i])
	}
	//将字符串数组里的元素拼接成一个字符串并返回
	return strings.Join(reserseSeg, " ")
}
```
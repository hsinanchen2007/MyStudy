### 解题思路

双指针法。p前，i后如果S[p] != S[i],则则将p到i这一段压缩，就是将S[p]和i-p链接在结果字符串尾部。循环结束不要忘记把最后一段也算上。最后返回两个字符串中短的那一个。

### 代码

```golang
func compressString(S string) string {
	if len(S) == 0 {
		return ""
	}
	p := 0
	res := ""
	for i := 0;i < len(S);i++ {
		if S[i] != S[p] {
			res += string(S[p])
			res += strconv.Itoa(i - p)
			p = i
		}
		if i == len(S) - 1 {	//别忘记把最后一段也算上
			res += string(S[p])
			res += strconv.Itoa(i - p + 1)
		}
	}
	if len(S) <= len(res) {
		return S
	}
	return res
}
```
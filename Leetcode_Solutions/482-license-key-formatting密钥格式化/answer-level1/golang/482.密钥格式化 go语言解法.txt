### 解题思路

比较直观的方法，缺点是耗时长。先把字母转存在切片中，根据字母数和K取余得到的余数决定第一组放几个。用循环拼接字符串，取flag为标志位，用于控制在拼接字符串的时候加入'-'。

### 代码

```golang
func licenseKeyFormatting(S string, K int) string {
	res := ""
	tmp := []byte{}
	for i := 0;i < len(S);i++ {
		if S[i] !='-' {
			t := S[i]
			if t >= 96 {
				t = t - 32
			}
			tmp = append(tmp,t)
		}
	}
	if len(tmp) == 0 {
		return ""
	}
	l := len(tmp) % K
	res = string(tmp[0:l])
	flag := 0
	for j := l;j < len(tmp);j++ {
		if flag % K == 0 {
			res = res + "-"
			flag = 0
		}
		res = res + string(tmp[j])
		flag++
	}
	if res[0] == '-' {
		res = res[1:]
	}
	return res
}
```
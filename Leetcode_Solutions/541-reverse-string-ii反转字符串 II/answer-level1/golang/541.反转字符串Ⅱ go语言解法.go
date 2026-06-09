### 解题思路

方法比较粗暴，把字符串字母逐个加入临时字符串中，用flag标志位来控制何时需要反转，当flag=2k-1时，将这一组连接在结果字符串后面即可。

### 代码

```golang
func reverseStr(s string, k int) string {
	res := ""
	tmp := ""
	flag := 0
	for i := 0;i < len(s);i++ {
		if flag == k {
			tmp = reverse(tmp)
		}
		tmp += string(s[i])
		if flag == 2 * k - 1 {
			res += tmp
			tmp = ""
			flag = 0
			continue
		}
		flag++
		if i == len(s) - 1 {
			if flag <= k {
				tmp = reverse(tmp)
			}
			res += tmp
		}
	}
	return res
}
func reverse(s string) string {
	tmp := []byte{}
	for i := len(s) - 1;i >= 0;i-- {
		tmp = append(tmp,s[i])
	}
	return string(tmp)
}
```
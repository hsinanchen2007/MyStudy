### 1、如图，每个红框内可以视为一组，把整个字符串按 2n-2 切割

`[[L E E T C O], [D E I S H I], [R I N G _ _]]`

![WX20190917-145303@2x.png](https://pic.leetcode-cn.com/85b81aa1fa68841d3851153d4df91f2aeeac3f57728fc1a1871313641c5f158e-WX20190917-145303@2x.png)


### 2、那么，我们先把每一组的第一位输出
`L D R`

![WX20190917-144822@2x.png](https://pic.leetcode-cn.com/9c2e13a5c1833c16f4d016b9382ef39d1d582f9800b07b595f3175732c9b4d40-WX20190917-144822@2x.png)


如图，此时字符串还剩下
`[[E E T C O], [E I S H I], [I N G _ _]]`

对于每一组，其实只是要输出首尾两端的字母就行了
第一次输出: `E O E I I`
第二次输出: `E C I H N`
第三次输出: `T S G`

### 3、代码
```
func Min(x, y int) int {
	if x < y {
		return x
	}
	return y
}
func convert(s string, numRows int) string {
	// 16 ms, 6.7 MB
	if len(s) < 2 || numRows < 2 {
		return s
	}
	div := numRows + (numRows - 2)

	// 将字符串按V字形来切分为数组
	divS := []string{}
	for i := 0; i < len(s); i += div {
		divS = append(divS, s[i:Min(i+div, len(s))])
	}
	// 将数组中每个元素的第一位取出
	res := ""
	for _, each := range divS {
		res += string(each[0])
	}

	// 使用i, j两个游标来从两端取值
	for i, j := 1, div-1; i <= j; i, j = i+1, j-1 {
		for _, each := range divS {
			if i < len(each) {
				res += string(each[i])
			}
			if j < len(each) && i != j {
				res += string(each[j])
			}
		}
	}
	return res
}
```
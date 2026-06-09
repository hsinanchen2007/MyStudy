### 解题思路

所以实际是根据循环次数，不断对前面这个数进行描述
从2开始输出的结果是：字符个数+所描述的字符...拼接起来的字符串

例如：5 111221 站着5这里看4所代表的数"1211"是1个1，1个2，2个1 
个数:1 + 字符:1 + 个数:1 + 字符:2 + 个数:2 + 字符:1
"1"+"1"+"1"+"2"+"2"+"1"

1 1
2 11 站在2这里看"1"是1个1
3 21 站在3这里看"11"是2个1
4 1211 站着4这里看"21"是1个2，1个1
5 111221 站着5这里看"1211"是1个1，1个2，2个1 



### 代码

```golang
func countAndSay(n int) string {
	if n == 1 {
		return "1"
	}
	var s = "1"
	var ret string
	for i := 1; i < n; i++ {
		var c int
		var b byte
		ret = ""
		for k := 0; k < len(s); k++ {
			if b != s[k] {
				if c > 0 {
					ret += fmt.Sprint(c) + string(b)
				}
				b = s[k]
				c = 1
			} else {
				c++
			}
		}
		ret += fmt.Sprint(c) + string(b)
		s = ret
	}

	return ret
}
```
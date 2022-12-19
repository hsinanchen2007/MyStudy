![38报数.png](https://pic.leetcode-cn.com/345859e99786075042917e7502921126e50339295aac92cf5141277c541d1932-38%E6%8A%A5%E6%95%B0.png)
n = 1 --> "1"
n = 2 --> "11"
n = 3 --> "21"
n = 4 --> "1211"
n = 5 --> "111221"
n = 6 --> "312211"
...
从上面可以看出一个规律，就是下一个数就是上一个数连续的一段子串对应的那个重复的字符所代表的的数字的一个计数表示形式，那么我们就去循环上一个数，并且标记第一个数字，当后面遇到第一个不为这个数字的时候，就把这个数字重复的次数转换成字符串并加上这个数字转换成的字符串
```
func countAndSay(n int) string {
    if n == 1 {
		return "1"
	}
	sum := "1"
	tmpStr := ""
    lenth := len(sum)
	tmp := sum[0]
	num := 0
    j := 0 
	for i := 1; i < n; i++ {
		lenth = len(sum)
		tmp = sum[0]
		num = 0 
		for j = 0; j < lenth; j++ {
			if sum[j] == tmp {
				num = num + 1
			} else {
				tmpStr = tmpStr + strconv.Itoa(num) + string(tmp)
				tmp = sum[j]
				num = 1
			}

			if j == lenth-1 {
				tmpStr = tmpStr + strconv.Itoa(num) + string(tmp)
			}
		}
		sum = tmpStr
		tmpStr = ""
	}
	return sum
}
```


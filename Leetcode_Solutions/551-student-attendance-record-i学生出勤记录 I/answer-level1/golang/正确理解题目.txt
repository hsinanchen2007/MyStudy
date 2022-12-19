不知道是出题人的错，还是我语文水平太次，在leetcode刷题常有理解错题意的时候。
本题题目中  “不超过两个连续的'L'（迟到）” ，我理解成了 'LL' 不能超过两个
结果题目想表达的意思是不能出现 'LLL....'   。。。。。
好吧，正确理解了题意之后，

对于 LLL 这种情况， 可以用go的  Contains 解决掉
对于 A 不能超过1个。就遍历一次喽（可提前结束）
代码如下：
```
func checkRecord(s string) bool {
	absent := 0
	if strings.Contains(s, "LLL") {
		return false
	}
	for _, v := range s {
		if v == 'A' {
			absent++
		}
		if absent > 1 {
			return false
		}
	}
	if absent > 1 {
		return false
	}
    return true
}
```

运行结果：
![image.png](https://pic.leetcode-cn.com/1f087cd94e3c4652248ac5f8e3ea9400926d41c695ff8a091d0186d602f9e71b-image.png)

![1221、分割平衡字符串.png](https://pic.leetcode-cn.com/d647e3af02f03b697f56920af16da458e45732bbcd59d40304c9d1c19373b890-1221%E3%80%81%E5%88%86%E5%89%B2%E5%B9%B3%E8%A1%A1%E5%AD%97%E7%AC%A6%E4%B8%B2.png)
根据题目要求，其实只需要统计'R'与'L'的数量，当两个字符的数量相等时就表示可以进行分割，这里不需要对已统计的清零，，因为每次划分时两个字符数量是相等的
```
func BalancedStringSplit(s string) int {
    var res = 0
	var rNum = 0
	var lNum = 0
	for i := 0; i < len(s); i++ {
		if s[i] == 'R' {
			rNum++
		} else {
			lNum++
		}
		if rNum == lNum {
			res = res + 1
		}
	}
	return res
}
```


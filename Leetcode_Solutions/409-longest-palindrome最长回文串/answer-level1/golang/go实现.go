### 解题思路
1、比较中心点
2、有中心店的话，是奇数的个数 ，边去1个 变成偶数

### 代码

```golang
package main

//最长回文串
//给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。
//
//在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。
func longestPalindrome(s string) int {
	if len(s) <= 1 {
		return len(s)
	}
	var charMap = make(map[byte]int)
	for i := 0; i < len(s); i++ {
		charMap[s[i]]++
	}
	var maxLenght = 0
	var flag = 0 // 是否是中心点

	for key, value := range charMap {
		if value%2 == 0 {
			maxLenght = maxLenght + value
		} else {
			maxLenght = maxLenght + charMap[key] - 1 //奇数的话 ，去掉1个
			flag = 1
		}
	}
	return maxLenght + flag
}

```
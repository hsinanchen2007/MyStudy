### 解题思路
map统计每个字母出现的次数，统计奇数个数的字母，大于1则false.(奇数个数等于1的时候放在回文字符串最中间即可)
![image.png](https://pic.leetcode-cn.com/52ebfb384c8d7d826342959fed0b315c5ca05ee5ad4d7c9264f166a051e59ad0-image.png)

### 代码

```golang
func canPermutePalindrome(s string) bool {
	var map1 = make(map[byte]int)
	for i:=0;i<len(s);i++{
		map1[s[i]]++
	}
	var count = 0
	for _,v :=range map1{
		if v % 2 != 0{
			count++
		}
	}
	if count>1{
		return false
	}else{
		return true
	}
}
```
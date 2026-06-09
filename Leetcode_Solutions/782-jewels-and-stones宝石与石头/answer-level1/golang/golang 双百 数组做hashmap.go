#### 解题思路

解题思路如注释所示

#### 参考代码

```go
func numJewelsInStones(J string, S string) int {
	list:= ['z'-'A'+1]int{}
	count:=0

	//遍历J将其中的字母装入哈希表(数组)
	for _,value := range J {
		list[value-'A']++
	}

	//遍历S统计有多少字母在哈希表里
	for _,value := range S {
		if list[value-'A'] != 0 {
			count++
		}
	}

	return count
}
```

**更多题解可以在我的[github](https://github.com/LZH139/leetcode_Go)上看到，每天都在持续更新，觉得还不错的话，记得点个小星星哈，谢谢啦**

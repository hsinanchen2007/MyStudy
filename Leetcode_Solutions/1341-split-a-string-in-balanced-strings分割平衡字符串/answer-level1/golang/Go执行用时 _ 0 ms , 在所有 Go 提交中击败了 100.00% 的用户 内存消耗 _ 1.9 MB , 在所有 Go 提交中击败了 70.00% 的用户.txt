### 解题思路
此处撰写解题思路
变量r_target，l_target标记'R'和'L'的次数
遍历一遍字符串，遇到'R',r_target++ 遇到'L'，l_target++
判断只要r_target==l_target res++
返回res即可
### 代码

```golang
func balancedStringSplit(s string) int {
	r_target := 0
	l_target := 0
	res := 0
	l := len(s)
	if l < 2 {
		return 1
	}
	for i := 0; i < l; i++ {
		if s[i] == 'R' {
			r_target++
		}
		if s[i] == 'L' {
			l_target++
		}
		if r_target == l_target {
			res++
		}

	}
	return res
}
```
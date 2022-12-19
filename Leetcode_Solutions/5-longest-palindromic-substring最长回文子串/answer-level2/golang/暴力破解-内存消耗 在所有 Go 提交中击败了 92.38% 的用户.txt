### 解题思路

#### 暴力破解

##### 主要思路
1. 找到所有的字符串
2. 判断一个字符串是否回文

##### 边界条件
- 长度为1的字符串
- 长度不为1的不重复字符串
- 长度不为1的无回文字符串的字符串

##### 判断是否回文的方法
###### 思路： 
1. 设置两个头尾指针 i 和 j
2. 判断s[i] === s[j]
3. 若相等， i++, j++, 直到 j - i <= 1,说明是回文； 回到步骤2
4. 若不相等，则直接判断s不是回文字符串


### 代码

```golang
func longestPalindrome(s string) string {
    if len(s) < 2 {
		return s
	}
    ans := 0
	ssstart, ssend := 0, 0
	for i := 0; i < len(s) - 1; i++ {
		for j := i + 1 ; j <= len(s); j++ {
			x := jugePalindrome(s, i, j-1)
			if x == 1 {
				if ans < len(s[i:j]) {
					ssstart = i
					ssend = j
					ans = len(s[i:j])
				}
			}
		}
	}
    if ans == 0 {
		ssend = 1
	}
	return s[ssstart:ssend]
}

func jugePalindrome(s string, start int, end int) int {
	if end - start < 1 {
		return 0
	}
	le := (end - start) / 2 + 1
	oldstart := start
	for i:= oldstart; i < le + oldstart; i++{
		if  s[start] != s[end] {
			return 0
		}
		start ++
		end --
	}
	return 1
}

```
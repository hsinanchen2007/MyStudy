![微信图片_20200309202714.png](https://pic.leetcode-cn.com/6c9e864ec0e79c767b957d5809a131eb7c6fa2c161ea662d1bbdd8c2443f3a48-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200309202714.png)

解题方法： 自上而下 存储计算结果
1. 当p为空时，此时若s为空，返回true，若s不为空，说明不匹配，返回false
2. 当p只有1个字符时：
	2.1 s为空，不匹配返回false
	2.2 s不为空，满足s的第一个字符和p的第一个字符匹配，或者p的第一个字符为'.'。则s和p都往后移动一个字符，看看后面是否匹配。
	2.3 如果s不为空，且不满足2.2的条件，说明不匹配，返回false
3. 当p的字符数大于两个的时候
	3.1 p的第二个字符为`*`,此时有两种情况   eg：s="ab..." p="a*..." 
	3.1.1 s的第一个字符和p的第一个字符相等或p的第一个字符为'.'
		此时有3种继续向后的方案
		1. s向后移一个字符，p向后移动两个字符  此时`*`的作用的是前面的字符a出现1次  即p变为"a..."
		2. s向后移一个字符，p不变  此时`*`的作用的是前面的字符a出现2次(当下匹配出现两次，`*`还保留)  即p变为"aa*...."
		3. s移动，p移动两个字符,此时`*`的作用的是前面的字符a出现0次。即跳过`*`和前面的一个字符
	3.1.2 不满足3.1.1的情况
		说明s和p的第一个字符不匹配，但是由于p的第二个字符`*`,可以把p的第一个字符去掉。
		此时s不变，p向后移动两个字符
	3.2 p的第二个字符不为`*`
		比较s和p的第一个字符是否匹配，是的话，就s和p都向后移动一个字符，比较后面的，反之不匹配。

由于go语言的bool数组初始化为false
我们新建一个int二维数组，用于保存计算结果

下面是完整代码：
1： true
0：未计算过
-1：false
```go []
func isMatch(s string, p string) bool {
	dp := make([][]int, len(s)+1)
	for i := 0; i <= len(s); i++ {
		dp[i] = make([]int, len(p)+1)
	}
	return isMatchCore(s, p, 0, 0, dp)
}
func isMatchCore(s, p string, i, j int, dp [][]int) bool {
	if dp[i][j] == 1 {
		return true
	} else if dp[i][j] == -1 {
		return false
	}
	flag := false
	if j == len(p) {
		if i == len(s) {
			flag = true
		} else {
			flag = false
		}

	}
	if j == len(p)-1 {
		if i == len(s) {
			flag = false
		} else if s[i] == p[j] || p[j] == '.' {
			flag = isMatchCore(s, p, i+1, j+1, dp)
		} else {
			flag = false
		}
	}
	if j < len(p)-1 {
		if p[j+1] == '*' {
			if i <= len(s)-1 && (s[i] == p[j] || p[j] == '.') {
				flag = isMatchCore(s, p, i+1, j+2, dp) || isMatchCore(s, p, i+1, j, dp) || isMatchCore(s, p, i, j+2, dp)
			} else {
				flag = isMatchCore(s, p, i, j+2, dp)
			}

		} else if i <= len(s)-1 && (s[i] == p[j] || p[j] == '.') {
			flag = isMatchCore(s, p, i+1, j+1, dp)
		}

	}
	if flag == true {
		dp[i][j] = 1
	} else {
		dp[i][j] = -1

	}
	return flag

}
```



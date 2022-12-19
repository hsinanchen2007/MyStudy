### 解题思路
此处撰写解题思路

动态规划
1.如果 s[i-1]='(' and s[i]=')' , dp[i]=dp[i-2]+2 也就是dp[i]是dp[i-2]追加了一个"()"
2.如果 s[i-1]也有最大有效括号，就看s[i-1]的有效括号的最左边字符left是否是'(', 也就是看s[left],s[i] 是否包裹了 s[i-1]
	- dp[i]=dp[i-1]+2
	- 这个是否要再判断最新的s[i]的最大有效括号左边S[left]是否也有有效括号，拼接到左边
	- dp[i] = dp[i]+dp[left]  ; left = i-dp[i-1]-2

### 代码

```golang
func longestValidParentheses(s string) int {

	sLen := len(s)
	pArray := make([]int, sLen+1)

	if sLen < 2 {
		return 0
	}

	if s[0] == '(' && s[1] == ')' {
		pArray[2] = 2
	} else {
		pArray[2] = 0
	}

	var maxLen int
	// i表示前面第i个字符，
	for i := 3; i < sLen+1; i++ {

		if pArray[i-1] > maxLen {
			maxLen = pArray[i-1]
		}

		if s[i-1] == '(' {
			pArray[i] = 0
			continue
		}

		// 当前是）,

		//上一个是（
		if s[i-2] == '(' {
			pArray[i] = pArray[i-2] + 2
			continue
		}

		//如果上一个是）

		//上一个没有 有效括号
		if pArray[i-1] == 0 {
			continue
		}

		// fmt.Println(s, i, pArray[i-1])

		//上一个最大有效括号的左边的那个字符，看是否为（
		//如果超过了，就不能构成外包裹的括号
		if i-1-pArray[i-1]-1 < 0 {
			continue
		}

		//如果是），也不能构成外包裹的括号
		if s[i-1-pArray[i-1]-1] == ')' {
			continue
		}

		//加上包裹 pArray[i-1]  的外层括号
		pArray[i] = pArray[i-1] + 2

		//考虑左边是否还有相邻的有效括号，进行拼接
		if i-pArray[i-1]-2 >= 0 {
			pArray[i] += pArray[i-pArray[i-1]-2]
		}

	}

	if pArray[sLen] > maxLen {
		maxLen = pArray[sLen]
	}

	// fmt.Println(pArray)
	return maxLen

}
```
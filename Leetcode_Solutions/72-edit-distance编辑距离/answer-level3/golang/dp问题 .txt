### 解题思路
// 动态规划，每次遇到不匹配的字符，有三种操作。分别穷举。 最后返回最小的
/* f(m)(n) = min{ f(m-1)(n-1) + 1
				  f(m-1)(n) + 1
  				  f(m)(n-1) + 1}
*/

### 代码

```golang
// 动态规划，每次遇到不匹配的字符，有三种操作。分别穷举。 最后返回最小的
/* f(m)(n) = min{ f(m-1)(n-1) + 1
				  f(m-1)(n) + 1
  				  f(m)(n-1) + 1}
*/
func minDistance(word1 string, word2 string) int {
	bin := make([][]int, len(word1)+1)
	for i := 0; i < len(bin); i++ {
		bin[i] = make([]int, len(word2)+1)
		bin[i][0] = i
	}
	for i := 0; i <= len(word2); i++ {
		bin[0][i] = i
	}
	bin[0][0] = 0

	for m := 1; m < len(bin); m++ {
		for n := 1; n < len(bin[0]); n++ {
			if word1[m-1] == word2[n-1] {
				bin[m][n] = bin[m-1][n-1]
			} else {
				bin[m][n] = min(bin[m-1][n], bin[m][n-1], bin[m-1][n-1]) + 1
			}
		}
	}
	return bin[len(word1)][len(word2)]
}

func min(a, b, c int) int {
	if a > b {
		a = b
	}
	if a > c {
		a = c
	}
	return a
}

```
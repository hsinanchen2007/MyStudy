### 解题思路

分两种情况考虑  

- 第一种，n为偶数时，前一半数为正整数，从1开始`append`进`result`数组，后一半为负数`append`进数组；
- 第二种，n为奇数时，前一半数为正整数，从1开始`append`进`result`数组，后一半为负数，但是注意，要从0开始`append`进数组；最后返回数组即可。

### 代码

```golang
func sumZero(n int) []int {

	var result []int
	//偶数
	if n%2 == 0 {
		for i := 1; i <= n/2; i++ {
			result = append(result, i)
		}
		for j := 1; j <= n/2; j++ {
			jj := j * (-1)
			result = append(result, jj)
		}
		return result
	} else {
		for i := 1; i <= n/2; i++ {
			result = append(result, i)
		}
		for j := 0; j <= n/2; j++ {
			jj := j * (-1)
			result = append(result, jj)
		}
		result[n/2] = 0
		return result
	}
}
```
### 解题思路
此处撰写解题思路

前0 ~ i-1 个字符一样，不同的i字符，后面都有(n-1-i)! 个方式

从左到右要求第i个位置的字符，只需要将 最新的k/(n-1-i)! 

### 代码

```golang
func getPermutation(n int, k int) string {

	if n > 9 || n <= 0 {
		return ""
	}

	s := []byte("123456789")
	result := make([]byte, n)

	var factorial = []int{1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880} //阶乘0-10
	if k > factorial[n] {
		return ""
	}

    //关键步骤
	k = k - 1

	for i := n - 1; i >= 0; i-- {
		
		id := k / factorial[i]
		k = k - factorial[i]*id
		
		result[n-i-1] = s[id]
		s = append(s[:id], s[id+1:]...)
		
	}

	return string(result)

}
```
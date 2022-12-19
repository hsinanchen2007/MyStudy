### 解题思路
没啥好解释的，就数组构建map，然后判断是否存在就OK了

### 代码

```golang
func numJewelsInStones(J string, S string) int {
  	isJewel := make(map[byte]bool, len(J))
	for i := range J {
		isJewel[J[i]] = true
	}

	res := 0
	for i := range S {
		if isJewel[S[i]] {
			res++
		}
	}

	return res
}

```
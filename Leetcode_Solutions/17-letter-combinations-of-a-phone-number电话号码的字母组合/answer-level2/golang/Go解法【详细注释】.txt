### 解题思路
**队列**：先进先出。把已经拼接过的结果插到尾部，然后待拼接的从头部出去，直到走完digits

### 代码

```golang
func letterCombinations(digits string) []string {
	if digits == "" || len(digits) == 0 {
		return nil
	}
	m := []string{" ", "*", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}
	var res []string
	res = append(res, "")
	// 迭代每个数字
	for i := 0; i < len(digits); i++ {
		// 由当前遍历到的字符，取字典表中查找对应的字符串
		// byte类型的数字-'0' = int类型数字
		letters := m[digits[i]-'0']
		// 预先定义size，防止变化
		size := len(res)
		// 计算出队列长度后，将队列中的每个元素挨个拿出来,和letter里面的拼接
		for j := 0; j < size; j++ {
			// 每次都从队列中拿出第一个元素
			tmp := res[0]
			res = res[1:]
			// 然后跟"def"这样的字符串拼接，并再次放到队列尾部
			for k := 0; k < len(letters); k++ {
				res = append(res, tmp+string(letters[k]))
			}
		}
	}
	return res
}
```
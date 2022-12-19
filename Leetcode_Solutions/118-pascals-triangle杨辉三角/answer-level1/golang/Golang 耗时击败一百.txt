### 解题思路
杨辉三角形，第一行是 1 不会变，从第二行开始，我们可以理解
1. 这一行的数据是上一行的数据最前面加上一个 0 
2. 然后两两相加得到之后
3. 再在末尾加上 1 元素

例如 第二行 [1,1] 是第一行 [1] 变为 [0,1] 两两相加得到 [1] 再末尾补上 1 得到 [1,1]

需要特别注意，题目中说的是非负整数，有可能是 0，然后 numRows 为 1 也是固定返回 [][]int{{1}} 的

### 代码

```golang
func generate(numRows int) [][]int {
	var ret [][]int

	if numRows == 0 {
		return ret
	}

	ret = append(ret, []int{1})

	if numRows >= 2 {
		for i := 1; i < numRows; i++ {
			var newLine []int

			line := append([]int{0}, ret[i-1]...)
			for j := 0; j < len(line)-1; j++ {
				newLine = append(newLine, line[j]+line[j+1])
			}

			newLine = append(newLine, 1)
			ret = append(ret, newLine)
		}
	}

	return ret
}
```
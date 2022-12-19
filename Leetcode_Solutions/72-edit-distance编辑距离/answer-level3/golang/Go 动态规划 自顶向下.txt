参考思路：[自底向上 和自顶向下](https://leetcode-cn.com/problems/edit-distance/solution/zi-di-xiang-shang-he-zi-ding-xiang-xia-by-powcai-3/)

思考总结：

依然是最小化问题的思考方向，先做 空 与 空 之间的转换，然后换成一个字符，到多个字符的推论。
操作上的优先级：无操作 > 插入 > 替换 > 删除  （可作为参考用）

代码如下：

```golang
func minDistance(word1 string, word2 string) int {
	lS, lD := len(word1), len(word2)
	res := buildBase(word1, word2)
	// 自顶向下构建二维数组
	for i := 0; i < lS; i++ {
		for j := 0; j < lD; j++ {
			if word1[i] == word2[j] {
				res[i+1][j+1] = res[i][j]
			} else {
				min := math.Min(math.Min(float64(res[i+1][j]), float64(res[i][j+1])), float64(res[i][j]))
				res[i+1][j+1] = int(min) + 1
			}
		}
	}
	//printSlice(word1, word2, res)
	return res[lS][lD]
}

// 构建初始数组结构
func buildBase(word1 string, word2 string) [][]int {
	lS, lD := len(word1), len(word2)
	base := make([][]int, lS+1)
	for i := 0; i <= lS; i++ {
		row := make([]int, lD+1)
		row[0] = i
		base[i] = row
	}
	for i := 0; i <= lD; i++ {
		base[0][i] = i
	}
	return base
}

// 可视化打印
func printSlice(word1 string, word2 string, s [][]int) {
	fmt.Printf("[X]\t")
	for i := 0; i < len(s[0]); i++ {
		if i == 0 {
			fmt.Printf("[\"\"]\t")
		} else {
			fmt.Printf("[%s]\t", string(word2[i-1]))
		}
	}
	fmt.Println()
	for line, row := range s {
		if line == 0 {
			fmt.Printf("[\"\"]\t")
		} else {
			fmt.Printf("[%s]\t", string(word1[line-1]))
		}
		for _, v := range row {
			fmt.Printf(" %d\t", v)
		}
		fmt.Println()
	}
}

```

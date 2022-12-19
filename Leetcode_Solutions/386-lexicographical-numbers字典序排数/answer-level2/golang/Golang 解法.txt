主要思想就是把字典序理解成一颗前缀树。然后每个节点的最左节点就是本节点剩十（如果小于等于n的话），本节点的右兄弟节点就是本节点加一（如果小于等于n，且不进位，就是各位数不为9）。生成树的图其他解题都有我就不画了。
```
func lexicalOrder(n int) []int {
	ret := make([]int, 0)
	num := 1
	for {
		if num <= n {
			ret = append(ret, num)
			num *= 10
		} else {
			num /= 10
			for num % 10 == 9 {
				num /= 10
			}
			if num == 0 {
				break
			}
			num++
		}
	}
	return ret
}
```

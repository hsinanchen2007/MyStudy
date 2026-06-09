递归求和，分别求出左子树和右子树的和，然后再加上节点本身的值。求出sum后，用一个map保存全局的sum对应的出现频率。并且用一个max保存最大频率。
```
func findFrequentTreeSum(root *TreeNode) []int {
	var res []int
	var max int
	var middle = make(map[int]int)
	dfsFindFrequentTreeSum(root, &middle, &res, &max)
	return res
}

func dfsFindFrequentTreeSum(root *TreeNode, middle *map[int]int, res *[]int, max *int) int {
	if root == nil {
		return 0
	}
	left := dfsFindFrequentTreeSum(root.Left, middle, res, max)
	right := dfsFindFrequentTreeSum(root.Right, middle, res, max)
	cur := left + right + root.Val
	(*middle)[cur]++
	if (*middle)[cur] > *max {
		*res = []int{cur}
		*max = (*middle)[cur]
	} else if (*middle)[cur] == *max {
		*res = append(*res, cur)
	}
	return cur
}
```

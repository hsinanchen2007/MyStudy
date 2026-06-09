```
var m map[int] int
func findFrequentTreeSum(root *TreeNode) []int {
	if root==nil {
		return []int{}
	}

	m:=make(map[int] int)
	roll(root, m)

	biggest:=0
	var result []int
	for k,v := range m {
		if v>biggest {
			result=make([]int, 0)
			result=append(result, k)
			biggest=v
		} else {
			if v == biggest {
				result=append(result, k)
			}
		}
	}
	return result
}

func roll(node *TreeNode, m map[int] int) int {
	var leftSum int
	if node.Left!=nil {
		leftSum=roll(node.Left, m)
	}

	var rightSum int
	if node.Right!=nil {
		rightSum=roll(node.Right, m)
	}
	m[node.Val+leftSum+rightSum]++
	return node.Val+leftSum+rightSum
}
```

```
import "sort"

func recoverTree(root *TreeNode) {
	if root == nil {
		return
	}
	result := inOrderTravelse(root)
    sort.Ints(result)
	exchange(root, &result)
	return
}

func inOrderTravelse(root *TreeNode) []int {
	result := make([]int, 0)
	if root != nil {
		result = append(result, inOrderTravelse(root.Left)...)
		result = append(result, root.Val)
		result = append(result, inOrderTravelse(root.Right)...)
	}
	return result
}

func exchange(root *TreeNode, result *[]int) {
	if root != nil {
        exchange(root.Left, result)
        root.Val = (*result)[0]
        *result = (*result)[1:]
        exchange(root.Right, result)
	}
}
```
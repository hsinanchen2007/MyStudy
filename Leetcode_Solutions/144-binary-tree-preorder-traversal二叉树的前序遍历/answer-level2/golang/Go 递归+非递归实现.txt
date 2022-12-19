# **递归实现**
```
func preorderTraversal(root *TreeNode) []int {
    if root == nil{
        return nil
    }
    
    res := []int{}
    res = append(res,root.Val)
    tmp := preorderTraversal(root.Left)
    res = append(res,tmp...)
    tmp2 := preorderTraversal(root.Right)
    res =append(res,tmp2...)
    return res
}

```


# **非递归实现**
```
   func preorderTraversal(root *TreeNode) []int {
	if root == nil {
		return []int{}
	}
	stack, res := []*TreeNode{}, []int{}
	stack = append(stack, root)
	for len(stack) != 0 {
		node := stack[len(stack)-1]
		stack = stack[:len(stack)-1]
		
			res = append(res, node.Val)
		
		if node.Right != nil {
			stack = append(stack, node.Right)
		}
		if node.Left != nil {
			stack = append(stack, node.Left)
		}
	}
	return res
}  
}
```


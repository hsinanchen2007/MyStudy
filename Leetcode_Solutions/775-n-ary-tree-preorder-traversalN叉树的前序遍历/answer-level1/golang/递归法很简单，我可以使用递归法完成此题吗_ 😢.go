# dfs
```golang
var res []int

func preorder(root *Node) []int {
	res = []int{}
	dfs(root)
	return res
}

func dfs(root *Node)  {
	if root != nil {
		res = append(res, root.Val)
        for _,n := range root.Children {
		    dfs(n)      
        }
	}
}
```

# dfs 迭代
```golang
func preorder(root *Node) []int {
	var res []int
	var stack = []*Node{root}
	for 0 < len(stack) {
		for root != nil {
			res = append(res, root.Val) //前序输出
			l := len(root.Children)
			if 0 < l {
				for i := l - 1; 0 < i; i-- {
					stack = append(stack, root.Children[i]) //入栈
				}
				root = root.Children[0]
			} else {
				break
			}
		}
		root = stack[len(stack)-1] //出栈
		stack = stack[:len(stack)-1]
	}
	return res
}
```

#    
[Go版本 Github](https://github.com/temporaries/leetcode)
[对应模板 Github](https://github.com/temporaries/leetcode/blob/master/templates/tree)
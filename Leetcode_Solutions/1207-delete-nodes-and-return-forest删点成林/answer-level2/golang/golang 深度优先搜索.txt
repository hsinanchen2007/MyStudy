### 解题思路
  采用深度优先搜索，从最底层开始处理，删除不彻底的问题

### 代码

```golang
func delNodes(root *TreeNode, to_delete []int) []*TreeNode {
	res := make([]*TreeNode,0,len(to_delete)*2)
	if root == nil{
		return nil
	}
	if len(to_delete) == 0{
		res = append(res,root)
		return res
	}
	m := make(map[int]bool,len(to_delete))
	for _,v := range to_delete{
		m[v] = true
	}
	var dfs func(p,child *TreeNode)
	dfs = func(p,child *TreeNode) {
        if child == nil{
            return
        }
		if child.Left != nil{
			dfs(child,child.Left)
		}
		if child.Right != nil{
			dfs(child,child.Right)
		}
		if m[child.Val]{
			if child.Left != nil{
				res = append(res,child.Left)
			}
			if child.Right != nil{
				res = append(res,child.Right)
			}
			if p.Left == child{
				p.Left = nil
			}else{
				p.Right = nil
			}
		}


	}
	dfs(root,root.Left)
	dfs(root,root.Right)
	if !m[root.Val]{
		res = append(res,root)
	}else{
		if root.Left != nil{
			res = append(res,root.Left)
		}
		if root.Right != nil{
			res = append(res,root.Right)
		}
	}
	return res
}
```
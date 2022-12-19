#思路
```
通过str传参构造奇偶路径
当len(str)>2时&&路径删的祖父节点是偶数时候，累加
dfs递归如上
```
#代码
```

func dfs(root *TreeNode,str string) int {
	if root == nil{
		return 0
	}else{
		var left,center,right int
		if len(str) >= 2 && str[len(str)-2:len(str)-1] == "2"{
				center = root.Val
		}
		if root.Val % 2 == 0{
			str = str + "2"
		}else{
			str = str + "1"
		}
		left = dfs(root.Left,str)
		right = dfs(root.Right,str)
		return left + center + right
	}
}

func sumEvenGrandparent(root *TreeNode) int {
	return dfs(root,"")
}
```


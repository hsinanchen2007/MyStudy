**思路**
```
1.判断平衡---->求解左右节点的深度   （递归求解）
2.一个节点不平衡---->整个树不平衡 （递归传达）
```

**代码**

```

func helper(root *TreeNode)(int,bool){
	if root == nil{
		return 0,true
	}else{
		var leftLevel,leftFlag = helper(root.Left)
		var rightLevel,rightFlag = helper(root.Right)
		if leftLevel - rightLevel >=2 || rightLevel - leftLevel >=2{
			return 0,false
		}
		var level int
		if leftLevel > rightLevel {
			level = leftLevel
		}else{
			level = rightLevel
		}
		return level+1,leftFlag && rightFlag
	}
}

func isBalanced(root *TreeNode) bool {
	var _,result = helper(root)
	return result
}
```

**思路**
```
将树的左子树、右子树分别拆分对比
1. left,right都是nil             ---->true
2. left,right一个nil,一个不是nil  ----->false
3. left,right都存在：
            1. 比较值
            2. 递归获取left,right
```
**代码**

```
func helper(left,right *TreeNode) bool{
	if left == nil && right == nil{
		return true
	}else if left == nil || right== nil{
		return false
	}else{
		var l = helper(left.Left,right.Left)
		var r = helper(left.Right,right.Right)
		var c = left.Val == right.Val
		return l && r && c
	}
}

func isSymmetric(root *TreeNode) bool {
	if root == nil{
		return  true
	}else{
		return helper(root.Left,root.Right)
	}
}
```

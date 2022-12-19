### 解题思路

递归法来做，分四种情况：
1.当前节点左右孩子都为空
2.当前节点只有右孩子
3.当前节点只有左孩子
4.当前节点左右孩子都有

### 代码

```golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func tree2str(t *TreeNode) string {
	if t == nil {
		return ""
	}
	if t.Left == nil && t.Right == nil {  //情况1
		return strconv.Itoa(t.Val)
	}
	if t.Right == nil {					  //情况2	
		return strconv.Itoa(t.Val) + "(" + tree2str(t.Left) + ")"
	}
	//情况3，4
	return strconv.Itoa(t.Val) + "(" + tree2str(t.Left) + ")(" + tree2str(t.Right) + ")"   
}
```
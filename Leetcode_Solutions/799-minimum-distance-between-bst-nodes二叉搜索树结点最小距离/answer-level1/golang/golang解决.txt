二叉树中序遍历,分治法思想,每个问题都可以分成3个节点之间的差值比较(注意取绝对值),使用全局变量保存上一个节点变量和上一对之差,用递归来进行遍历:
var pre *TreeNode
var min int

func minDiffInBST(root *TreeNode) int {
	min = 10000 //设置个很大的数,使得开始时节点值必然比此值要小
     getnodes(root)
	return min
}

func getnodes(root *TreeNode) {

	if root == nil {
		return
	}
	getnodes(root.Left)
	if pre != nil {
		tmp := root.Val - pre.Val
        if tmp < 0 {
			tmp = tmp - tmp*2 //取绝对值
		}
		if min > tmp {
			min = tmp
		}
	}
	pre = root
	getnodes(root.Right)

}
### 解题思路
利用二叉搜索树的中序遍历的有序性，找出需要调整的值，通过值查找相应节点，调换两个节点的值

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
func recoverTree(root *TreeNode)  {
tt := &TT{}
	tt.LDR1(root)
	var m []int
	m = append(m, tt.P...)
	sort.Slice(tt.P, func(i, j int) bool {
		return tt.P[i] < tt.P[j]
	})
	var l, r int
	for i := 0; i < len(m); i++ {
		if m[i] != tt.P[i] {
			l = m[i]
			r = tt.P[i]
			break
		}
	}

	var lroot =&Tree{}
	lroot.H(root, l, r)
}

type Tree struct {
	T *TreeNode
}

func (t *Tree) H(root *TreeNode, l, r int) bool {
	if root == nil {
		return true
	}
	if root.Val == l && t.T == nil {
		t.T = root
	} else if root.Val == l && t.T != nil && t.T.Val != l {
		t.T.Val = l
		root.Val = r
		return false
	}
	if root.Val == r && t.T == nil {
		t.T = root
	} else if root.Val == r && t.T != nil &&  t.T.Val != r {
		t.T.Val = r
		root.Val = l
		return false
	}
	if !t.H(root.Left, l, r) {
		return false
	}
	if !t.H(root.Right, l, r) {
		return false
	}
	return true
}
func (t *TT) LDR1(root *TreeNode) {
	if root == nil {
		return
	}
	t.LDR1(root.Left)
	t.P = append(t.P, root.Val)
	t.LDR1(root.Right)
}

type TT struct {
	P []int
}
```
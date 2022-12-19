```
func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
	pParents, qParents, path := make([]*TreeNode, 0), make([]*TreeNode, 0), make([]*TreeNode, 0)
	qParentsMap := make(map[*TreeNode]struct{})
	findPath(root, p, q, path, &pParents, &qParents, qParentsMap)
	for i := len(pParents) - 1; i >= 0; i-- {
		if _, ok := qParentsMap[pParents[i]]; ok {
			return pParents[i]
		}
	}
	return nil
}

func findPath(root *TreeNode, p *TreeNode, q *TreeNode, path []*TreeNode, pParents *[]*TreeNode, qParents *[]*TreeNode, qpMap map[*TreeNode]struct{}) {
	if len(*pParents) > 0 && len(*qParents) > 0 {
		return
	}
	if root != nil {
		path = append(path, root)
		if root.Val == p.Val {
			*pParents = append(*pParents, path...)
		} else if root.Val == q.Val {
			*qParents = append(*qParents, path...)
			for _, index := range path {
				qpMap[index] = struct{}{}
			}
		}
		findPath(root.Left, p, q, path, pParents, qParents, qpMap)
		findPath(root.Right, p, q, path, pParents, qParents, qpMap)
	}
}
```
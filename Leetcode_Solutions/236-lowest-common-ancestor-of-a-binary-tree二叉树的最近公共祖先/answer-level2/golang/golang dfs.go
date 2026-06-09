### 解题思路
思路：
1. dfs搜出来所有路径
2. 找出p获取q或者的路径以及位置
3. 遍历两个路径，找到位置的最小值对应的节点或者最后一个相同的节点，即是结果

### 代码

```golang
/**
 * Definition for TreeNode.
 * type TreeNode struct {
 *     Val int
 *     Left *ListNode
 *     Right *ListNode
 * }
 */

func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
	allPaths := make([][]*TreeNode, 0)
	dfs(root, []*TreeNode{}, &allPaths)

	var pn, qn, pv, qv int
	for i, v := range allPaths {
		for j, n := range v {
			if n == p {
				pn = i
                pv = j
			}

			if n == q {
				qn = i
                qv = j
			}
		}
	}
    fmt.Println(allPaths, pn, qn)
	var i int
	var res *TreeNode
	for i < len(allPaths[pn])&& i < len(allPaths[qn]) &&i<=pv && i <=qv && allPaths[pn][i] == allPaths[qn][i] {		
		res = allPaths[pn][i]
        i++
	}

	return res
}

func dfs(root *TreeNode, tmp []*TreeNode, res *[][]*TreeNode) {
	if root == nil {
		return
	}

	if root.Left == nil && root.Right == nil {
		t := make([]*TreeNode, 0)
		t = append(t, tmp...)
		t = append(t, root)

		*res = append(*res, t)
	}

	dfs(root.Left, append(tmp, root), res)
	dfs(root.Right, append(tmp, root), res)
}

```
### 解题思路

看小姐姐的视频

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
func postorderTraversal(root *TreeNode) []int {

	if root == nil {
		return nil
	}

	var pre, cur *TreeNode
	result := make([]int, 0)
	s := make([]*TreeNode, 0)
	s = append(s, root)
	sLen := 1
	for {

		if sLen == 0 {
			return result
		}

		cur = s[sLen-1]

		//往下走
		if pre == nil || cur == pre.Left || cur == pre.Right {
			if cur.Left != nil {
				s = append(s, cur.Left)
				sLen++
			} else if cur.Right != nil {
				s = append(s, cur.Right)
				sLen++
			}
		} else if cur.Left == pre { //往上走
			if cur.Right != nil {
				s = append(s, cur.Right)
				sLen++
			}
		} else { // pre = cur //走到最左边点
			result = append(result, cur.Val)
			s = s[:sLen-1]
			sLen--
		}

		pre = cur

	}

}

```
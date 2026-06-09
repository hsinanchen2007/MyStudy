### 解题思路
    //第一圈建立虚线连接，到了最左之后返回，一路向右right
    //第二圈是原本的中序输出顺序，在此时作比较
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
func recoverTree(root *TreeNode) {
	var pre, first, second, maxRight *TreeNode
	for root != nil {
		if root.Left != nil {
			maxRight = root.Left
			for maxRight.Right != nil && maxRight.Right != root {
				maxRight = maxRight.Right
			}
            //找到前驱节点，尚未建立虚线连接
			if maxRight.Right != root {
				maxRight.Right = root
				root = root.Left
			} else {
                //第二次到此，此时该放入中序队列了
				maxRight.Right = nil
				if maxRight != nil && maxRight.Val > root.Val {
					if first == nil {
						first = maxRight
					}
					second = root
				}
				pre = root
				root = root.Right
			}
		} else {
            //往左再无节点，到了队列头部了，该放入中序队列了
			if pre != nil && pre.Val > root.Val {
				if first == nil {
					first = pre
				}
				second = root
			}
			pre = root
			root = root.Right
		}
	}
	first.Val, second.Val = second.Val, first.Val
}

```
### 解题思路

![image.png](https://pic.leetcode-cn.com/9ecb0f5330e37828c60ba8c52f83866433110f6ba36d34b135fe34aa0fbf2b04-image.png)

递归思想
- 对于递归的每一步
- 如果节点都为空，返回true
- 如果节点非空切值相等返回true
- 其他情况均为false

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
func isSameTree(p *TreeNode, q *TreeNode) bool {
    if p == nil && q == nil {
        return true
    }else if p!= nil && q != nil && p.Val == q.Val {
        return isSameTree(p.Left, q.Left) && isSameTree(p.Right, q.Right)
    }else {
        return false
    }
}
```
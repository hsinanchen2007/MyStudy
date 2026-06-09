![1.PNG](https://pic.leetcode-cn.com/a42283f7cc69711c8cd05917d00630dc847adce6af560bb291f2f20a5a8a3036-%E6%8D%95%E8%8E%B7.PNG)
[965. 单值二叉树]()
### 解题思路
遍历二叉树

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
func isUnivalTree(root *TreeNode) bool {
    val := root.Val
    flag := true
    isUnivalT(root, &val, &flag)
    return flag
}

func isUnivalT(root *TreeNode, val *int, flag *bool) {
    if root == nil || !(*flag) {
        return 
    }
    if root.Val != *val {
        *flag = false
        return
    }
    isUnivalT(root.Left, val, flag)
    isUnivalT(root.Right, val, flag)
}
```
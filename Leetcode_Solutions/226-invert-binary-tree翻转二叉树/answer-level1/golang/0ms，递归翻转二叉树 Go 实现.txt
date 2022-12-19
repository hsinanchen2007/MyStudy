
![image.png](https://pic.leetcode-cn.com/f20714ccb67321d7a36241d4bf9064e7b6eff79b8a45baf578b18583dbf71c27-image.png)

递归翻转二叉树

代码
```
func invertTree(root *TreeNode) *TreeNode {
    if root == nil {
        return root
    }
    invertTree(root.Left)   // 翻转左子树
    invertTree(root.Right)  // 翻转右子树
    root.Left, root.Right = root.Right, root.Left   // 翻转当前左右节点
    return root
}
```
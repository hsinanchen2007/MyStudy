### 解题思路
![image.png](https://pic.leetcode-cn.com/36d2f8773949e18db1f3caa68a851ab668d8d50e54f7c88a61a4a4bfdff02e4b-image.png)
观察题目描述，其实很容易得出一个结论：二叉树的镜像即为原二叉树所有左右节点互换位置即可。
我们要做的就是：
1、判断当前节点是否是nil，如果是nil，可以直接返回 （边界条件）
2、如果不是nil，根节点保持不变，把左右子树节点互换，递归

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
func mirrorTree(root *TreeNode) *TreeNode {
    if root == nil {
        return root
    }
    
    root.Left, root.Right = mirrorTree(root.Right), mirrorTree(root.Left)

    return root
}
```

### Golang学习请关注我 

微信公众号：互联网技术窝
     
![qrcode.png](https://pic.leetcode-cn.com/5915f33eec0f89e3549818d49cc9d7c8234288cb7e5a51cc770509eb4bee6150-qrcode.png)
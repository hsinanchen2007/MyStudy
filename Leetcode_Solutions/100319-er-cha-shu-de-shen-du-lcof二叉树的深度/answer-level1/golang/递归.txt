### 解题思路
深度即为根节点到叶子节点的最大数。

我们可以使用先序遍历：
1、根节点。上次节点数目+1
2、算出左子树的高度和由子树的深度
3、取左子树和右子树深度的最大值

我们使用递归的边界条件：当节点为nil的时候，返回上一次所求的深度    

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
func maxDepth(root *TreeNode) int {
    var f func(*TreeNode, int)int
    f = func(node *TreeNode, deep int) int {
        if node == nil {
            return deep
        }
        deep ++ 
        left := f(node.Left, deep)
        right := f(node.Right, deep)
        if left >= right {
            return left
        }

        return right
    }
    return f(root, 0)
}
```

### 微信公众号请关注：互联网技术窝
![qrcode.png](https://pic.leetcode-cn.com/05a2993ea199e003326550ead325347d1f98710f03217a75e9ba898cbd57ea97-qrcode.png)

### 运行结果
![image.png](https://pic.leetcode-cn.com/0e26b9480c21328418022399798f5fc584a8a9e8aa00fdae13dfb3ddf4e4270c-image.png)

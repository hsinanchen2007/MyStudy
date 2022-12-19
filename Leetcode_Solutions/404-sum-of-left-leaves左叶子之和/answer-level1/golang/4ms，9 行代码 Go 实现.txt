
![image.png](https://pic.leetcode-cn.com/7db53f7c304024cb90be1c51d6f288c519631623542723c7f5fa997325c999cc-image.png)

递归判断每个节点的左节点是否为叶子节点：  
* 如果左节点是叶子节点，那么加上左节点的值，并继续递归遍历右子树；
* 如果左节点不是叶子节点，那么继续遍历左子树和右子树；

```
func sumOfLeftLeaves(root *TreeNode) int {
    if root == nil {
        return 0
    }
    if root.Left != nil && root.Left.Left==nil && root.Left.Right==nil {
        return root.Left.Val + sumOfLeftLeaves(root.Right)
    }
    return sumOfLeftLeaves(root.Left) + sumOfLeftLeaves(root.Right)
}
```
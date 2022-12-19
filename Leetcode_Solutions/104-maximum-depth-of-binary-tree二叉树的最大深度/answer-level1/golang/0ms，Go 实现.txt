
![image.png](https://pic.leetcode-cn.com/bef4dba958d845648897c652f2b8f835772bb0ae9d9be38955981968c98b7d17-image.png)

代码
```
func maxDepth(root *TreeNode) int {
    if root == nil {    // 终止条件
        return 0
    } else {            // 获得左子树和右子树的深度，返回最大深度
        ldepth := maxDepth(root.Left) + 1
        rdepth := maxDepth(root.Right) + 1
        if ldepth > rdepth {
            return ldepth
        }
        return rdepth
    }
}
```
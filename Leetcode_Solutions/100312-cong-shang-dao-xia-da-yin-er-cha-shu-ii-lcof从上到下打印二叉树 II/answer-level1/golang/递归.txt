

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
func levelOrder(root *TreeNode) [][]int {
    ret := make([][]int, 1000)
    var f func(*TreeNode, int)int

    f = func(node *TreeNode, deep int)int {
        if node == nil {
            return deep
        }

        ret[deep] = append(ret[deep], node.Val)
        tmpLeft := f(node.Left, deep + 1)
        tmpRight := f(node.Right, deep + 1)

        if tmpLeft >= tmpRight {
            return tmpLeft
        }
        return tmpRight
    }
    deep := f(root, 0)
    ret = ret[:deep]
    return ret
}
```

### 微信公众号
![qrcode.png](https://pic.leetcode-cn.com/37ddcf7eeed28b56ddd95c871522d8e4a899efa522adf3cd96182c2e2994f928-qrcode.png)

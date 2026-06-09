**解题思路**
运用中序遍历递归，每次递归返回当前子树的节点和和坡度。
递归函数内部计算左右子树坡度并相加然后加上左右节点差的绝对值。

**参考代码**
```
func inOrder(root *TreeNode) (int, int) {
    var sum, tilt int
    if root == nil {
        return 0, 0
    }

    sum += root.Val
    sumLeft, tiltLeft := inOrder(root.Left)
    sumRight, tiltRight := inOrder(root.Right)

    sum += sumLeft + sumRight
    tilt += tiltLeft + tiltRight

    t := sumLeft - sumRight
    if t < 0 {
        t = -t
    }
    tilt += t
    return sum, tilt
}

func findTilt(root *TreeNode) int {
    _, tilt := inOrder(root)
    return tilt
}

```

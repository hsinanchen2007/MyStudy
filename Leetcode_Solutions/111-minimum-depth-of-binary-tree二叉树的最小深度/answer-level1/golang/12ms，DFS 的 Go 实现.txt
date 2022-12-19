
![image.png](https://pic.leetcode-cn.com/f93a58a7879845f5996fdf23e70e9a57ee31fb1423a9bcf064f288d7b1233fe2-image.png)

这题有小坑，空节点不计入最小深度的计算，比如输入为 [1,2]，最小深度不是1，而是2。

代码
```
func Min(a int, b int) int {
    if a==0 {               // 小坑，空节点不计入最小深度的计算
        return b
    } else if b==0 {
        return a
    }
    if a<b {                // 正常的比较
        return a
    }
    return b
}
func minDepth(root *TreeNode) int {
    if root == nil {
        return 0
    }
    return Min(minDepth(root.Left), minDepth(root.Right)) + 1   // 返回当前节点左右子树的最小深度
}
```
![image.png](https://pic.leetcode-cn.com/5d6c2b7ab01372d2bfe32ef303cd05a616fd17bc8f7d1a9f67db18fb783a2070-image.png)

代码
```
func isSameTree(p *TreeNode, q *TreeNode) bool {
    if p != nil && q != nil && p.Val == q.Val { // 当前节点相同，继续往下比
        return isSameTree(p.Left, q.Left) && isSameTree(p.Right, q.Right)
    } else if p==nil && q==nil {
        return true
    } else {
        return false
    }
}
```
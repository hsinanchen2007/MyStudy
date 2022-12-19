欢迎加好友一起交流!
![微信2.png](https://pic.leetcode-cn.com/1b59615a6fd55839b40d6eadb5a608cbfad23d6470afd736d9cd615d5db3d1ec-%E5%BE%AE%E4%BF%A12.png)

```
func longestUnivaluePath(root *TreeNode) int {
    re := 0
    var dfs func(root *TreeNode) int
    dfs = func(root *TreeNode) int {
        if root == nil{
            return 0
        }
        left := dfs(root.Left)
        right := dfs(root.Right)
        l,r := 0,0
        if root.Left != nil && root.Left.Val == root.Val {
            l = left+1
        }
        if root.Right != nil && root.Right.Val == root.Val {
            r = right+1
        }
        re = max(re, l+r)
        return max(l, r)
    }
    dfs(root)
    return re
}
```




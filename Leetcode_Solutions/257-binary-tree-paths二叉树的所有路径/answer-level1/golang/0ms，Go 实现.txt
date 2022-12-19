
![image.png](https://pic.leetcode-cn.com/91fa72cf1b5dd93dc0730599c9dc52bd5895fa7c36542cbdbff4d099cceee4f5-image.png)


```
func TreePaths(cur *TreeNode, s string, ans []string) []string {
    if cur == nil {
        return ans
    }
    s += fmt.Sprintf("%d->", cur.Val)   // 累加当前路径
    if cur.Left == nil && cur.Right == nil {    // 遇到叶子节点返回
        ans = append(ans, s[:len(s)-2])
        return ans
    }
    ans = TreePaths(cur.Left, s, ans)
    ans = TreePaths(cur.Right, s, ans)
    return ans
} 

func binaryTreePaths(root *TreeNode) []string {
    if root == nil {
        return []string{}
    }
    ans := TreePaths(root, "", []string{})
    return ans
}
```
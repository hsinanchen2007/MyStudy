**解题思路**
深度优先遍历获取每个子树的最小和次小值，跟当前树次小值比较。

**代码**
```
func dfs(root *TreeNode) (int, int) {
    one, two := root.Val, root.Val
    if root.Left != nil && root.Left.Val != two {
        two = root.Left.Val
    }
    if root.Right != nil && root.Right.Val != two && root.Right.Val < two {
        two = root.Right.Val
    }

    if two == root.Val {
        m := two
        if root.Left != nil {
            s, t := dfs(root.Left)
            if s != m {
                two = s
            } else if t != m {
                two = t
            }
        }
        if root.Right != nil {
            s, t := dfs(root.Right)
            if (s < two && s != m) || (two == m && s != m) {
                two = s
            } else if (t < two && t != m) || (two == m && t != m) {
                two = t
            }
        }
    }

    return one, two
}

func findSecondMinimumValue(root *TreeNode) int {
    one, two := dfs(root)
    if one == two {
        return -1
    }
    return two
}
```

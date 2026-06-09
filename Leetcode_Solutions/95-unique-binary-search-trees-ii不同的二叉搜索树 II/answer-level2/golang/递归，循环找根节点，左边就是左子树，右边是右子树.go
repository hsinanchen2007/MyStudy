### 解题思路
递归，循环找根节点，左边就是左子树，右边是右子树

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
func generateTrees(n int) []*TreeNode {
    // 遍历n个数，一次作为树根，然后左边做做左子树，又边是右子树
    if n == 0 {
        return nil
    }
    return generateSubTrees(1, n)
}

func generateSubTrees(from, n int) []*TreeNode {
    if from > n {
        return []*TreeNode{nil}
    }
    trees := make([]*TreeNode, 0, n - from + 1)
    for i := from; i <= n; i++ {
        lefts := generateSubTrees(from, i - 1)
        rights := generateSubTrees(i + 1, n)
        for j := 0; j < len(lefts); j++ {
            for k := 0; k < len(rights); k++ {
                var root = &TreeNode{Val : i}
                root.Left = lefts[j]
                root.Right = rights[k]
                trees = append(trees, root)
            }
        }
    }
    return trees
}
```
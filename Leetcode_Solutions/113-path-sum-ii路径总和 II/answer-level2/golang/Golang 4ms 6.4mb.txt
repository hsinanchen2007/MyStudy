### 解题思路
此处撰写解题思路

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
func pathSum(root *TreeNode, sum int) [][]int {
    results := make([][]int, 0)
    if root == nil {
        return results
    }
    path := make([]int, 0)
    search(root, sum, &results, &path)
    return results
}

func search(root *TreeNode, sum int, results *([][]int), path *([]int)) {
    newPath := make([]int, 0)
    newPath = append(newPath, *path...)
    if root.Left == nil && root.Right == nil {
        if Sum(newPath) + root.Val == sum {
            newPath = append(newPath, root.Val)
            *results = append(*results, newPath)
        }
    } else if root.Left == nil && root.Right != nil {
        newPath = append(newPath, root.Val)
        search(root.Right, sum, results, &newPath)
    } else if root.Right == nil && root.Left != nil {
        newPath = append(newPath, root.Val)
        search(root.Left, sum, results, &newPath)
    } else {
        newPath = append(newPath, root.Val)
        search(root.Right, sum, results, &newPath)
        search(root.Left, sum, results, &newPath)
    }
}

func Sum(nums []int) int {
    res := 0
    for _, v := range nums {
        res += v
    }
    return res
}
```
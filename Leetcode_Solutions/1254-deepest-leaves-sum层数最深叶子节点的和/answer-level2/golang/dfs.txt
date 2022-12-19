```
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func deepestLeavesSum(root *TreeNode) int {
    tmp := make(map[int]int, 0) 

    helper(root, 0, tmp) 

    index, result := 0, tmp[0]
    for k,v := range tmp {
        if k > index {
            index = k
            result = v
        }
    }
  
    return result
}

func helper(root *TreeNode, depth int, tmp map[int]int) {
    if root == nil {
        return 
    }    

    tmp[depth] += root.Val 

    helper(root.Left, depth+1, tmp)
    helper(root.Right, depth+1, tmp)
}
```

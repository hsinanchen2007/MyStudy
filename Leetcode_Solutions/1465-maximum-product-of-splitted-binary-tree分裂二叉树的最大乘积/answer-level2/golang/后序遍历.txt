### 解题思路
先求 加起来总值， 这样后序遍历时，sum减去子节点和，就可以得到另一边和了

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
func maxProduct(root *TreeNode) int {
    if root == nil {
        return 0
    }
    s := sum(root) 
    result := 0
    helper(root, &result, s) 

    return result % 1000000007
}

// 后序遍历 
func helper(root *TreeNode, result *int, sum int) int {
    if root == nil {
        return 0
    }   
    if root.Left == nil && root.Right == nil {
        return root.Val
    } 
    val1, val2 := 0,0
    if root.Left != nil {
        val1 = helper(root.Left, result, sum)
    }
    if root.Right != nil {
        val2 = helper(root.Right, result, sum) 
    }

    *result = max(*result, val1*(sum-val1))
    *result = max(*result, val2*(sum-val2))

    return val1 + val2 + root.Val
}

func max(i,j int)int {
    if i > j {
        return i
    }
    return j
}

func sum(root *TreeNode) int{
    if root == nil  {
        return 0
    }
    if root.Left == nil && root.Right == nil {
        return root.Val
    } 
    val := 0
    if root.Left != nil {
        val += sum(root.Left)
    }
    if root.Right != nil {
        val += sum(root.Right)
    }

    return val + root.Val
}
```
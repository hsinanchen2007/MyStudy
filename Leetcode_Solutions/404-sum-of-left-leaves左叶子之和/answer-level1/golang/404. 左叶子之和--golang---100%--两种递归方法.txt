### 解题思路
采用两种递归思路：
思路一：
自定义递归函数，传入指针变量接受值；
思路二：
不需要自定义递归函数，用局部变量接受递归完毕返回的值。

两种均是100%

### 代码
思路一：
```go
func sumOfLeftLeaves(root *TreeNode) int {
    
    if root == nil {
        return 0
    }
    sum := 0
    Run(&sum,root)
    return sum
}

func Run(sum *int,root *TreeNode)  {
    if root == nil {
        return 
    }
    if root.Left!=nil && root.Left.Left == nil  && root.Left.Right == nil {
        fmt.Println(root.Left.Val)
        *sum += root.Left.Val
    }
    
    Run(sum,root.Left)
    Run(sum,root.Right)

}
```
思路二：
```golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func sumOfLeftLeaves(root *TreeNode) int {
     sum := 0
    if root == nil {
        return 0
    }
    if root.Left!=nil && root.Left.Left == nil  && root.Left.Right == nil {
        sum += root.Left.Val
    }
    
    sum += sumOfLeftLeaves(root.Left)
    sum += sumOfLeftLeaves(root.Right)

    return sum
}




```
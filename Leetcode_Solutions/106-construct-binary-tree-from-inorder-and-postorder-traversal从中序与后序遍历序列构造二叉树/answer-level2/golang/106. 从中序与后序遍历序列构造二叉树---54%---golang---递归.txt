### 解题思路
思路在注解中

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
func buildTree(inorder []int, postorder []int) *TreeNode {
    
    root := Run(inorder,postorder)
    
    return root
}

func Run(inorder []int,postorder []int) *TreeNode {

    //大问题细化为子问题
    //即为，可以看作是对某一一个叶子节点的父节点的构建
    //             3(root)
    // 1(root.Left)       2(root.Right)
    //递归原理：只要最基本的子问题搞清楚了，调用时先自顶向下，返回时自下而上构建。

    //返回条件
    if len(inorder) == 0{
        return nil
    }

    leftIndex := 0
    rightIndex := 0

    //分割左右子树
    root := new(TreeNode)
    root.Val = postorder[len(postorder)-1]

    for k,v := range inorder {
        if root.Val == v {
            leftIndex = k
            rightIndex = k+1
            break
        }
    }

    //左子树
    inorderLeft := inorder[:leftIndex]
    postorderLeft := postorder[:leftIndex]
    //右子树
    inorderRight := inorder[rightIndex:]
    postorderRight := postorder[rightIndex-1:len(postorder)-1]
    //构建节点
    root.Left = Run(inorderLeft,postorderLeft)
    root.Right = Run(inorderRight,postorderRight)

    return root
}
```
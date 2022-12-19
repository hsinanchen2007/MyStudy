### 解题思路
递归进行处理 
每次进入一个儿子的时候 递归儿子的左儿子 并且层次加一 然后 如果递归到空节点 就可以返回该路径的最大层次了 这表示这一分支的深度 同理递归儿子的右儿子 获取右儿子的层次 返回其最大者

考察dfs的递归操作
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
func maxDepth(root *TreeNode) int {
   return maxDepthv1(root,0)
}


func maxDepthv1(root *TreeNode,n int)int{
     if root == nil{
        return n
    }

    d1:=maxDepthv1(root.Left,n+1)
    //fmt.Println("d1:",d1)
    d2:=maxDepthv1(root.Right,n+1)
    //fmt.Println("d2:",d2)

    tmax:=0
    if d1>d2{
        tmax = d1
    }else {
        tmax = d2
    }
    return tmax
}

```
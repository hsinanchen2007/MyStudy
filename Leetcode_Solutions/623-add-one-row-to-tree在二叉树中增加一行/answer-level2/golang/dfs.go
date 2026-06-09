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
func addOneRow(root *TreeNode, v int, d int) *TreeNode {
    if d==1{
        temp1:=&TreeNode{Val:v}
        temp1.Left=root
        return temp1
    }
    insert(v,root,1,d)
    return root
}  
func insert(val int,root *TreeNode,dep int,d int){
    if root==nil{
        return
    }
    if d-1==dep{
        s1:=root.Left
        temp1:=&TreeNode{Val:val}
        root.Left=temp1
        root.Left.Left=s1
        s2:=root.Right
        temp2:=&TreeNode{Val:val}
        root.Right=temp2
        root.Right.Right=s2
        
    }else{
        insert(val,root.Left,dep+1,d)
        insert(val,root.Right,dep+1,d)
    }
}


```
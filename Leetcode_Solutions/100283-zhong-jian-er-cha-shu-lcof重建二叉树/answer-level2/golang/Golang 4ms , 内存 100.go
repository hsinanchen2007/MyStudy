### 解题思路
根据中序和前序的规则. 
前序: 根, 左,右
中序: 左, 根, 右

我们可以知道, 前序的第一个元素就是根节点, 那么我们在中序数组中找到该元素(注意元素不重复是题目条件), 根据中序的规则, 在这个元素左边的数列就是左子树, 右边的序列就是右子树的中序遍历.
同样, 我们获得左子树的中序遍历的长度, 可知在前序数组中, 除去第一个元素之后, 前该长度的数列就是左子树的前序遍历, 该长度之后的数列就是右子树的中序遍历. 

以此, 我们就找到了根节点, 左子树的两序遍历和右子树的两序遍历.

递归调用, 找出左右子树的根节点,作为最开始的根节点的左右子节点即可.


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
func buildTree(preorder []int, inorder []int) *TreeNode {

return headF(preorder,inorder, 0 , len(preorder)-1,0,len(inorder)-1)
}
func headF(preorder, inorder []int, startPre,endPre, startIn, endIn int)*TreeNode{   
    if(startPre>endPre||startIn>endIn){//判定是否序列是否便利完。
            return nil;
        }
 head  := &TreeNode{
    Val: 0,
    Left: nil,
    Right: nil,
}
for i:= startIn ; i <= endIn; i++ {
    if inorder[i] == preorder[startPre] {
        head.Val = inorder[i]
        head.Left = headF(preorder,inorder, startPre+1, startPre + i -startIn, startIn, i-1)
        head.Right = headF(preorder,inorder, startPre+i-startIn+1, endPre, i+1, endIn)
        break
    }
}       
return head 
}
```
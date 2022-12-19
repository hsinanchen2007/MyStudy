### 解题思路
此题和上一题(可直接跳转到上一题)的思路很类似，代码也几近相同，下面这两道题一起来说。
规律：
规律1. 前序遍历+中序遍历可以还原二叉树。
规律2. 后序遍历+中序遍历可以还原二叉树
也就是说还原二叉树必须利用中序遍历。
思路：
1. 先找二叉树(或子树)的根节点，规律1，首元素是根节点；规律2，尾元素是根节点
2. 从中序遍历中找到根节点root的位置，对于二者，左边是左子树，右边是右子树
3. 对于根节点root，填充其左右子树，然后对其左右子树调用递归
4. 补充：第2、3点的思路特别像快排的思路，快排是先确定一个数的位置，这个位置左边的比它小，右边的比它大。然后对左右两个区间递归。
5. 补充：为了方便查找在中序遍历的索引，利用map存储值和坐标
6. 规律1和规律2的代码顺序有点不同，
    规律1要先递归左子树，再递归右子树，因为在前序遍历中，根节点后面应该是左子树的值，左子树遍历完才是右子树的值
    规律2要先递归右子树，再递归左子树，因为在后序遍历中，根节点前面应该是右子树的值，右子树遍历完才是左子树的值

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

var inorderMap map[int]int = make(map[int]int)
var Apostorder []int = make([]int,0)
var preIdx=0
func buildTree(inorder []int, postorder []int) *TreeNode {
    Apostorder=postorder

    for i,_:=range inorder{
        inorderMap[inorder[i]]=i
    }
    preIdx=len(postorder)-1
    return helper(0,len(inorder))
}

func helper(left int,right int) *TreeNode{
    if left==right{
        return nil
    }

    nodeVal:=Apostorder[preIdx]
    root:=&TreeNode{
            Val:nodeVal,
            }
    index:=inorderMap[nodeVal]
    preIdx--
    
    root.Right=helper(index+1,right)

    root.Left=helper(left,index)

    return root
}
```
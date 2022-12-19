# 解题思路
- **层序遍历**
 	- 创建一个 queue 队列，先将根节点（ root ）入队
 	- 再将 queue 队列中的元素（根节点）遍历，遍历到节点的值加入进 ret 数组，接下来看根节点，有没有左子树或右子树
 	 	- 如果有，则将左、右子树先后加入 temp 临时队列，最后将 queue=temp 队列，模拟 queue 中元素的出队
 	 - 只要 queue 队列还不为空，则继续遍历
 	 - 这时的 queue 队列中的元素则为刚才入队的左子树和右子树，并遍历按先后顺序将节点的值加入进 ret 数组
 	 - 直到当 temp == nil 时，则说明没有入队元素，queue=temp，当队列为空时，整颗树就层序遍历完成了，结束循环。

---
# 解法一:模拟队列
--执行用时：0 ms -内存消耗：2.7 MB
```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func levelOrder(root *TreeNode) []int {
    if root==nil{
        return nil
    }
    var ret []int
    //树顶入队列
    queue := []*TreeNode{root}
    //队列不为空
    for len(queue)!=0{
        temp := []*TreeNode{}
        for _ , v :=range queue{
            ret = append(ret,v.Val)
            if v.Left != nil{
                temp = append(temp,v.Left)
            }
            if v.Right != nil{
                temp = append(temp,v.Right)
            }
        }
        //下一层
        queue = temp
    }
    return ret
}
```

---
# 解法二:递归

利用 	[面试题32 - II-从上到下打印二叉树 II](https://blog.csdn.net/qq_19841021/article/details/104361658) 	得到带层级的数组切片，再先后遍历各层数组的元素添加到 ret 数组即可

--执行用时：0 ms -内存消耗：3 MB

```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func levelOrder(root *TreeNode) []int {
    if root==nil{
        return nil
    }
    var ret []int
    tree:=leveltree(root)
    for i,_:=range tree{
        ret = append(ret,tree[i]...)
    }
    return ret
}

func leveltree(root *TreeNode) [][]int {
    //初始化数组
    tree:=make([][]int,0)
    creat(&tree,root,0)
    return tree
}

func creat(tree *[][]int,root *TreeNode,level int) {
    if root==nil{
        return 
    }

    if len(*tree)-1<level{
        (*tree)=append((*tree),make([]int,0))
    }
    
    (*tree)[level]=append((*tree)[level],root.Val)

    //level++到下一层，递归记录
    level++
    creat(tree,root.Left,level)
    creat(tree,root.Right,level)
}
```

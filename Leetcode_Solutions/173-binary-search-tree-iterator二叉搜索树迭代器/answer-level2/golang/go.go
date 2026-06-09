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
type BSTIterator struct {
    MidOrderList []int
}


func Constructor(root *TreeNode) BSTIterator {
    res := midOrder(root)
    return BSTIterator{MidOrderList:res}
}

func midOrder(root *TreeNode) []int{
    if root == nil{
        return []int{}
    }
    res := []int{root.Val}
    res = append(midOrder(root.Left),res...)
    res = append(res,midOrder(root.Right)...)
    return res
}

/** @return the next smallest number */
func (this *BSTIterator) Next() int {
    res:= this.MidOrderList[0]
    this.MidOrderList = this.MidOrderList[1:]
    return res
}


/** @return whether we have a next smallest number */
func (this *BSTIterator) HasNext() bool {
    return len(this.MidOrderList) > 0
}


/**
 * Your BSTIterator object will be instantiated and called as such:
 * obj := Constructor(root);
 * param_1 := obj.Next();
 * param_2 := obj.HasNext();
 */
```
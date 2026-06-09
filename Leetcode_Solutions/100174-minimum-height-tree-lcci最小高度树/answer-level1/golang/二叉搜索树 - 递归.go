### 解题思路
二叉搜索树：若它的左子树不空，则左子树上所有结点的值均小于它的根结点的值； 若它的右子树不空，则右子树上所有结点的值均大于它的根结点的值； 它的左、右子树也分别为二叉排序树。
由于题目给的是排序数组，左边小于右边，所以只需要将中间的元素取出作为头节点。
头结点左边的就是数组中间元素左边的元素，右边的就是右边的元素，直接递归遍历就好了。
递归要设定特殊情况，当数组长度为0，则直接返回nil，长度为1则返回数组第一个元素作为节点。

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
func sortedArrayToBST(nums []int) *TreeNode {
    if len(nums) == 0 {
        return nil
    }
    if len(nums) == 1{
        return &TreeNode{Val:nums[0]}
    }
    middle := len(nums) / 2
    head := &TreeNode{Val:nums[middle]}
    head.Left = sortedArrayToBST(nums[:middle])
    head.Right = sortedArrayToBST(nums[middle+1:])
    return head 
}
```

### 运行结果

![image.png](https://pic.leetcode-cn.com/23f5ede176cd561e2dbcb086df1ad56e18940f01621dc5611165075c303e7921-image.png)

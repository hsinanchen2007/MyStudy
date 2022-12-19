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
func findTarget(root *TreeNode, k int) bool {
    var num= []int{}
    findTree(root,&num)
    l,r:=0,len(num)-1
    for l<r{
        sum:=num[l]+num[r]
        if sum==k{
            return true
        }else if sum<k{
            l++
        }else{
            r--
        }
    }
    return false
}

func findTree(root *TreeNode ,num *[]int){
    if root==nil{
        return 
    }
    findTree(root.Left,num)
    *num=append(*num,root.Val)
    findTree(root.Right,num)
}
```
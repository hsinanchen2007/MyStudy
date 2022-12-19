### 解题思路
官方题解 golang 实现

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


 // 这个值是可写共享
var postIndex int
//减少 copy 优化内存
var m map[int]int
//减少 copy 优化内存
var postorder []int

func buildTree(inorder []int, po []int) *TreeNode {
    //覆盖之前case的遗留值
    m = map[int]int{}

    //构造 inorder val->index
    for idx,v :=range inorder{
        m[v]=idx
        //计算长度
        postIndex = idx
    }

    //覆盖之前case的遗留值
    postorder = po

    return helper(0,postIndex)

}

func helper(indexLeft,indexRight int)*TreeNode{
    if indexLeft > indexRight {
        return nil
    }
    rootVal := postorder[postIndex]
    t := &TreeNode{Val:rootVal}
    rootIndex := m[rootVal]
    //postIndex 复杂传入recursive func
    postIndex--
    //right 必须要在left前面 否则出错
    t.Right = helper(rootIndex+1,indexRight)
    t.Left = helper(indexLeft,rootIndex-1)
    return t
}



```
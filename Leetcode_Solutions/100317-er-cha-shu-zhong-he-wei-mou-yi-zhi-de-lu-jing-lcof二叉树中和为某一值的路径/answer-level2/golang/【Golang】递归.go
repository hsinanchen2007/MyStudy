# 解题思路
- **先序遍历，arr 记录节点的路径**
 	- 退出条件：root == nil 当前节点为空 
 	- 每次将当前节点放入当前保存的路径
 		- 判断当前节点是否是叶节点：
 		 	- root.Left == nil && root.Right == nil
 			 	- 是：将符合的路径放入 ret 中
 			 -	dfs(root.Left,sum - root.Val,arr,ret)
 			 	dfs(root.Right,sum - root.Val,arr,ret)
 			 	- 否：继续遍历左子树和右子树直到叶节点
- **遍历到叶节点后**
 	- 得到的路径符合要求时，创建一个新的切片，拷贝当前路径到其中，并添加到 ret 中
 	- 得到的路径不符合要求，往前回溯，删除当前节点，返回父节点

# 代码
--执行用时：4 ms --内存消耗：4.5 MB
```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func pathSum(root *TreeNode, sum int) [][]int {
    if root == nil {
        return nil
    }
    var ret [][]int
    dfs(root,sum,[]int{},&ret)
    return ret
}

func dfs(root *TreeNode,sum int,arr []int,ret *[][]int){
    if root == nil{
        return
    }
    arr = append(arr,root.Val)

    if root.Val == sum && root.Left == nil && root.Right == nil {
        //slice是一个指向底层的数组的指针结构体
        //因为是先序遍历，如果 root.Right != nil ,arr 切片底层的数组会被修改
        //所以这里需要 copy arr 到 tmp，再添加进 ret，防止 arr 底层数据修改带来的错误
        tmp := make([]int,len(arr))
        copy(tmp,arr)
        *ret = append(*ret,tmp)
    }

    dfs(root.Left,sum - root.Val,arr,ret)
    dfs(root.Right,sum - root.Val,arr,ret)

    arr = arr[:len(arr)-1]
}

```

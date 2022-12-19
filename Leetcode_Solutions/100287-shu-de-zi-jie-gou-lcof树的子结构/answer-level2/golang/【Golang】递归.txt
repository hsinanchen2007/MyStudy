# 解题思路
- ## 两个函数

 	- **isSubStructure()** 
 	 	- 用于递归遍历 A 中的所有节点，并判断当前节点 A 是否与 B 的根节点相同，相同则调用  helper( ) 进一步校验
 	- **helper()**
 	 	- 用于校验 B 是否与 A 的一个子树拥有相同的结构和节点值
- ## 函数内容
 	 - **isSubStructure()**
 	  	- 如果当前节点 A == nil && B == nil ，返回true。
 	 	- 如果当前节点 A == nil  | | B == nil ，返回 false。（由题目可知，空树不是任意一个树的子结构）
 	 	- 当在当前结点 A 中找到 B 的根节点时，进入helper () 递归校验
 	 	- ret == false，说明 B 的根节点不在当前 A 中，进入 A 的左子树进行递归查找
 	 	- ret 仍等于 false，则说明 B 的根节点不在当前 A 和左子树中，进入 A 的右子树进行递归查找
 	- **helper()**
 	 	- 如果 B == nil ，说明 B 已遍历完，返回 true
 		- 在 B != nil 的情况下，如果 A == nil ,说明 A 中节点不足以构成子结构 B ，返回 false
 		- 如果 a.Val != b.Val，不满足节点值相等条件，返回 false
 		- a.Val == b.Val 继续递归校验 A B 左子树和右子树的结构和节点是否相同

# 代码

```golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isSubStructure(A *TreeNode, B *TreeNode) bool {
    if A == nil && B == nil {
        return true
    }
    if A == nil || B == nil{
        return false
    }

    var ret bool

    //当在 A 中找到 B 的根节点时，进入helper递归校验
    if A.Val == B.Val{
        ret = helper(A,B)
    }

    //ret == false，说明 B 的根节点不在当前 A 树顶中，进入 A 的左子树进行递归查找
    if !ret {
        ret = isSubStructure(A.Left,B)
    }

    //当 B 的根节点不在当前 A 树顶和左子树中，进入 A 的右子树进行递归查找
    if !ret {
        ret = isSubStructure(A.Right,B)
    }
    return ret

    //利用 || 的短路特性可写成
    //return helper(A,B) || isSubStructure(A.Left,B) || isSubStructure(A.Right,B)
}

//helper 校验 B 是否与 A 的一个子树拥有相同的结构和节点值
func helper(a,b *TreeNode) bool{
    if b == nil{
        return true
    }
    if a == nil{
        return false
    }
    if a.Val != b.Val{
        return false
    }
    //a.Val == b.Val 递归校验 A B 左子树和右子树的结构和节点是否相同
    return helper(a.Left,b.Left) && helper(a.Right,b.Right)
}
```
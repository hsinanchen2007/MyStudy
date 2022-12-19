### 解题思路
要想求是否是子树
那么我们要搭好架构
1.先找A与B相同的A节点n
2.再将节点n 进行与B递归判断

可以有框架，递归务必先考虑特殊情况 因为后面的返回值都会涉及到特殊情况的
可以图表来分析该过程
              8                         8
         8         7                   9 2 
      9    2
         4   7
应该在第二层找到8 然后issame 此时递归isSubStruct递归两次即可
func isSubStruct(A,B) bool{
    ans:=false
    if A==B{
        ans = isSame(A,B)    
    }
    if !ans {
        ans = isSubStruct(A.Left,B)
    } 
    
    if !ans {
        ans = isSubStruct(A.Right,B)
    }
    return ans
}

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
func isSubStructure(A *TreeNode, B *TreeNode) bool {
    if A==nil||B==nil{
        return false
    }

    return find(A,B)
    

}

func find(A *TreeNode,B *TreeNode) bool{
    if A == nil {
        return false
    }

    if A.Val == B.Val{
        if isSame(A,B) {
            return true
        }
    }

    r:=find(A.Left,B)
    if !r{
        r=find(A.Right,B)
    }
    // if l {
    //     if isSame(A.Left,B) {
    //         return true
    //     }
    // }

    return r
}

func isSame(A *TreeNode,B  *TreeNode) bool {
    
    if B == nil {
        return true
    }

    if A == nil {
        return false
    }

    if A.Val != B.Val {
        return false 
    }

    l:=isSame(A.Left,B.Left)
    r:=isSame(A.Right,B.Right)
    
    return  l&&r
}
```
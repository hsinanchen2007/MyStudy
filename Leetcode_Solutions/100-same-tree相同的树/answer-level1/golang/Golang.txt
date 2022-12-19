

```golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
//递归方法
func isSameTree(p *TreeNode, q *TreeNode) bool {
    if p == nil && q == nil {
        return true
    }
    if (p == nil && q != nil) || (p != nil && q == nil) {
        return false
    }
    if p.Val != q.Val {
        return false
    }
    
    return isSameTree(p.Left, q.Left) && isSameTree(p.Right, q.Right)
}


迭代方法其实类似递归，只是通过BFS进行了遍历。
对于两个数，使用一样的队列。但是在计算时，使用一个队列P或Q作为基准。
在每次从队列中取出是，先进行判断取出的是否相等；


//迭代方法
func isSameTree(p *TreeNode, q *TreeNode) bool {
    var stackp, stackq = list.New(), list.New()
    stackp.PushBack(p)
    stackq.PushBack(q)
    for stackp.Len() != 0 {
        p = stackp.Remove(stackp.Front()).(*TreeNode)
        q = stackq.Remove(stackq.Front()).(*TreeNode)
        if !check(p, q) {
            return false
        }
        //以一个stcakp为准！
        //这里其实用p来判断。因为上面已经判断过，保证p和q是一致的，因此不用担心p和q不一致导致的漏判
        if p != nil {
            if !check(p.Left, q.Left) {
                return false
            }
            stackp.PushBack(p.Left)
            stackq.PushBack(q.Left)
            if !check(p.Right, q.Right) {
                return false
            }
            stackp.PushBack(p.Right)
            stackq.PushBack(q.Right)
        }
        
    }
    return true

}

func check(p *TreeNode, q *TreeNode) bool {
    if p == nil && q == nil {
        return true
    }
    if (p == nil && q != nil) || (p != nil && q == nil) {
        return false
    }
    if p.Val != q.Val {
        return false
    }
    return true
} 











```
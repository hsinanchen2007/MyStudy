```
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

var (
    data map[int]int
    result []*TreeNode
)

func delNodes(root *TreeNode, to_delete []int) []*TreeNode {
    // 由于leetcode验证机制，这里全局变量初始化
    result = []*TreeNode{}
    data = map[int]int{}
    
    data = map[int]int{}
    for _, delNum := range to_delete {
        data[delNum] = 0
    }

    trace(&root)
    // root节点可能会被删掉
    if root == nil {
        return result
    }
    
    // 添加根结点
    if _, ok := data[root.Val]; !ok {
        result = append(result, root)
    }

    return result
}


// 后序遍历删除节点
func trace(node **TreeNode) {
    
    if *node == nil {
        return
    }
    
    trace(&(*node).Left)
    trace(&(*node).Right)
    
    if _, ok := data[(*node).Val]; ok {
        if (*node).Left != nil {
            result = append(result, (*node).Left)
        }
        if (*node).Right != nil {
            result = append(result, (*node).Right)
        }
        
        *node = nil
    }
    
}



```

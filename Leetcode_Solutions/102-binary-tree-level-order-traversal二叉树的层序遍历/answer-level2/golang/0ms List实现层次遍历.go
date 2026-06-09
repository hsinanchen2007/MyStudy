链表实现广度优先搜索
```
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func levelOrder(root *TreeNode) [][]int {
    if root == nil{
        return nil
    }
    
    nodeList := list.New()
    nodeList.PushBack(root)
    
    result := make([][]int,0)
    for nodeList.Len() != 0{
        levelVal := []int{}
        nodeListLen := nodeList.Len()
        
        for i:=0; i< nodeListLen; i++{  
            e := nodeList.Front()      
            if e == nil{
                break
            }
            node := e.Value.(*TreeNode)
            if node != nil{
                levelVal = append(levelVal, e.Value.(*TreeNode).Val)
                nodeList.PushBack(e.Value.(*TreeNode).Left)
                nodeList.PushBack(e.Value.(*TreeNode).Right)
            }
            nodeList.Remove(e)
        }
        if len(levelVal) > 0 {
            result = append(result, levelVal)
        }
    }
    return result
}

```

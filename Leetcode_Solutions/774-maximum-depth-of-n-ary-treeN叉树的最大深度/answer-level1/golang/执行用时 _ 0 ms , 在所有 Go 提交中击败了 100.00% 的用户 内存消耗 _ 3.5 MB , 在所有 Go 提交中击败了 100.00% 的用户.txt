### 解题思路

广度搜索

### 代码

```golang
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Children []*Node
 * }
 */

func maxDepth(root *Node) int {
    
    deep :=0
    if root == nil{
        return deep 
    }

    var queue []*Node

    queue = append(queue,root)
    for len(queue) >0{
        qLen := len(queue)
        for i:=0;i<qLen;i++{
            if queue[i].Children !=nil{
                queue = append(queue,queue[i].Children...)
            }
        }
        deep++
        queue = queue[qLen:]

    }
    return deep
}
```
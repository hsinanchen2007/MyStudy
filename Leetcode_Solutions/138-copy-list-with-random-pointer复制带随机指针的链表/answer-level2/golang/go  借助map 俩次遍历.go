### 解题思路
此处撰写解题思路
借助map 俩次遍历
第一次 克隆节点 
第二次 链接节点
### 代码

```golang
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Next *Node
 *     Random *Node
 * }
 */

func copyRandomList(head *Node) *Node {
    m := make(map[*Node]*Node)
    cur := head
    for (cur != nil) {
        temp := &Node{cur.Val, nil, nil}
        m[cur] = temp
        cur = cur.Next
    }
    cur = head
    for (cur != nil) {
        m[cur].Next = m[cur.Next]
        m[cur].Random = m[cur.Random]
        cur = cur.Next
    }
    return m[head]
}
```
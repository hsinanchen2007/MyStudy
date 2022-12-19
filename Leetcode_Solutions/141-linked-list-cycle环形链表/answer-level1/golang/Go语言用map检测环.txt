### 解题思路
此处撰写解题思路

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func hasCycle(head *ListNode) bool {
    var p *ListNode
    var map1 = make(map[*ListNode]int)      //定义一个map用来记录已经遍历过的节点
    var pos = 0
    p = head

    for p!=nil {
        if map1[p] == 0 {   //若节点对应的键值为初始的零值，则记录该节点并将键值设为1
            map1[p] = 1     
            p = p.Next
        } else {    //若节点键值不为1 ，则说明之前已经记录过该节点，此时已形成环
            pos=-1
            break
        }
    }

    if pos == -1 {
        return true
    } else {
        return false
    }
}
```
使用一个切片存储指针，然后直接返回倒数第K个

```
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func getKthFromEnd(head *ListNode, k int) *ListNode {
    tmp := head
    nodes := []*ListNode{head}

    for {
        if(tmp.Next != nil) {
            tmp = tmp.Next
            nodes = append(nodes,tmp)
        } else {
            break
        }
    }

    return nodes[len(nodes) - k]
}
```

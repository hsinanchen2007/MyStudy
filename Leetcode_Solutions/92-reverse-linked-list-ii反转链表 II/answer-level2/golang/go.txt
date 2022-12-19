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
func reverseBetween(head *ListNode, m int, n int) *ListNode {
    if m == 1 {
        return helper(head, n-m)
    }
    start := head
    for i:=2; i < m; i++ { 
        head = head.Next
    }
    head.Next = helper(head.Next, n-m ) 

    return start
} 

func helper(node *ListNode, k int ) *ListNode {
    var last,p1 *ListNode
    start := node
    for i:=0; i <=k; i++ {
        last = node.Next 
        node.Next = p1 

        p1 = node 
        node = last
    }
    start.Next  = node
    return p1
}
```
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
func removeNthFromEnd(head *ListNode, n int) *ListNode {
    node, _ := remove(head, n)
    return node
}

func remove(head *ListNode, n int) (*ListNode, int) {

    if head == nil {
        return nil, 0
    }

    var k int

    head.Next, k = remove(head.Next, n)

    if k == n - 1 {
        return head.Next, k + 1
    }
    return head, k + 1
}
```
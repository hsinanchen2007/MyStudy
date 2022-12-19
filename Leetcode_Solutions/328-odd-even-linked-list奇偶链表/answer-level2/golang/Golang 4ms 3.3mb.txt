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
func oddEvenList(head *ListNode) *ListNode {
    if head == nil {
        return head
    }
    var preOddNode *ListNode
    var preEvenNode *ListNode
    var firstEven *ListNode
    var firstOdd  *ListNode
    index := 0
    for head != nil {
        index += 1
        if index % 2 == 0 {
            if preEvenNode != nil {
                preEvenNode.Next = head
            }
            if index == 2 {
                firstEven = head
            }
            preEvenNode = head
            head = head.Next
            preEvenNode.Next = nil
        } else {
            if preOddNode != nil {
                preOddNode.Next = head
            }
            if index == 1 {
                firstOdd = head
            }
            preOddNode = head
            head = head.Next
            preOddNode.Next = nil
        }
    }
    preOddNode.Next = firstEven
    return firstOdd
}
```
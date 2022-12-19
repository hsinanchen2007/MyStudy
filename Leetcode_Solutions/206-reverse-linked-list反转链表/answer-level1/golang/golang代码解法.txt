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
func reverseList(head *ListNode) *ListNode {
    cur := head
    var pre *ListNode
    for cur != nil{
        aft := cur.Next
        cur.Next = pre
        pre = cur
        cur = aft
    }
    return pre
}
```
循环遍历链表，分别记录当前节点的前一个和后一个，将当前节点指向前一个，然后三个指针往后移。
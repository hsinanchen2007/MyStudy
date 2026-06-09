### 解题思路
保存第一个结点，用一个变量作为dummy节点，然后循环把后续的节点都插在dummy之后。

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
        var p *ListNode
        q := head
        for q != nil {
                t := q.Next
                q.Next = p
                p = q
                q = t
        }
        return p 
}
```
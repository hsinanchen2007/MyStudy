### 解题思路

非递归，用语法糖让cur, cur.Next, prev三者交换即可。

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
/**
func reverseListHelper(prev *ListNode, cur *ListNode) *ListNode {
    if cur == nil {
        return prev
    }
    next := cur.Next
    cur.Next = prev
    return reverseListHelper(cur, next)
}
*/

func reverseList(head *ListNode) *ListNode {
    // iterative
    var prev *ListNode
    cur := head
    for cur != nil {
        prev, cur.Next, cur = cur, prev, cur.Next
    }
    return prev
    // recursive
    // return reverseListHelper(nil, head)
}
```
### 解题思路
1. 抓住循环的指针 cur
2. 选定 临时指针 pos,表明当前的标题
3. 选定 pre 指向新的标题， 每次循环记得回到新表头位置
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
    var pre  *ListNode
    cur := head
    if head == nil || head.Next == nil {
        return head
    }
    for ;cur!=nil;  {
        pos := cur.Next
        cur.Next = pre
        pre = cur
        cur = pos
         
    }
    return pre
}
```
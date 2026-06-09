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

func deleteDuplicates(head *ListNode) *ListNode {
    pre := &ListNode{
        Val: 0,
        Next: head,
    }
    cur := pre
    for nil != cur.Next && nil != cur.Next.Next {
        
        // 与下一个值重复
        if cur.Next.Val == cur.Next.Next.Val {
            // 保存下前驱指针
            temp := cur
            p := cur.Next
            // 循环查找下去是否后面还有重复的
            for nil != p.Next && p.Val == p.Next.Val {
                p = p.Next
            }
            temp.Next = p.Next
            cur = temp
        } else {
            cur = cur.Next
        }
    }
    return pre.Next
}
```
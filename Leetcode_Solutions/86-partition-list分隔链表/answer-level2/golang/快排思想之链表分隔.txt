### 解题思路
无序线性数列，按目标值分隔成两部分，很自然想到快排的思路

链表比较麻烦的是指针以及父指针、子指针。开始按照一条链表去处理的，很乱，头尾覆盖无解。

发现按照两条链表去写，就能缕清了：
一条是存小于目标值的，初始化为空，等待append；
一条是‘预期’大于等于目标值的，初始化为head。遍历过程中发现有不满足的，摘下来，append到上一条list。

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func partition(head *ListNode, x int) *ListNode {
    prevHead1 := &ListNode{
        Next: nil,
    }
    tail1 := prevHead1

    preHead2 := &ListNode{
        Next: head,
    }

    for next := preHead2; next.Next != nil; {
        if next.Next.Val < x {
            tmp := next.Next
            next.Next = tmp.Next
            tmp.Next = tail1.Next
            tail1.Next = tmp
            tail1 = tmp
        } else {
            next = next.Next
        }
    }
    tail1.Next = preHead2.Next
    return prevHead1.Next
}
```
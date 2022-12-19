```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 * 快慢指针不难理解,难以理解的是 为什么快慢指针一定相遇?
 * 官方的解释是 快指针走一次2步速度为2 慢指针一次1步速度为1 所以二者速度相差1
 * 如果链表存在环 那么相当于最坏情况下 每次迭代二者之间的距离就会缩小1个单位,所以必然会在某次迭代时缩小为0
 */
func hasCycle(head *ListNode) bool {
    if head == nil{
        return false
    }
    fast, slow := head, head
    for fast != nil && fast.Next != nil{
        fast = fast.Next.Next
        slow = slow.Next
        if fast == slow{
            return true
        }
    }
    return false
}
```

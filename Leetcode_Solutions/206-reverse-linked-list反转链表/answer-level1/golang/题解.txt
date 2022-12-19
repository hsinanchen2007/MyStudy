### 解题思路
定义 prev 表示前一个节点
因为 head 节点反转后其 前一个节点为空，故初始值为 nil

head 作为 current 节点
1. 将 current(head) 的 Next 节点拎出来放到 next 中，避免后面找不到
2. 将 current(head) 的 Next 指向 prev
3. 将 prev 指向 current(head)
4. 如果 next 为 nil，表示当前是最后一个节点，后面没有节点再需要处理，此处需要返回，避免 head 被赋为 next 时 清空
5. 否则将 head 指向 next

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
    var prev  *ListNode

    for(head != nil) {
        next := head.Next
        head.Next = prev
        prev = head
        if next == nil {
            return head
        }

        head = next

    }
    return head

}
```
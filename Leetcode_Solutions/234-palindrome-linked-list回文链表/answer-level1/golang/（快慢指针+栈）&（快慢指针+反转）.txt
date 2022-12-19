说说该题的两种经典解法：**快慢指针+栈**和**快慢指针+反转**，二者区别在于前者的空间复杂度为O(N)。
  
**快慢指针+栈**：使用快慢指针找到链表的中点或是中点的前一个节点（当链表长度为奇数时慢指针在链表中间节点，长度为偶数时慢指针在链表的中间偏左节点），慢指针步长为1，快指针步长为2。使用栈存储链表的前半部分的节点值：设表长为n，n为奇数时存储前(n-1)/2个节点，n为偶数时存储前n/2个节点。
```go
func isPalindrome(head *ListNode) bool {
    if head == nil || head.Next == nil {
        return true
    }
    stack := make([]*ListNode, 0)
    p1, p2 := head, head
    for p2 != nil && p2.Next != nil {
        stack = append(stack, p1)
        p1, p2 = p1.Next, p2.Next.Next
    }
    if p2 != nil {
        p1 = p1.Next
    }
    for len(stack) != 0 {
        node := stack[len(stack) - 1]
        stack = stack[:len(stack) - 1]
        if node.Val != p1.Val {
            return false
        }
        p1 = p1.Next
    }
    return true
}
```

**快慢指针+反转**：反转后一半节点，然后从头结点和尾节点开始对比，最后还要恢复原状，代码不表，这个思路留着跟面试官扯皮吧。
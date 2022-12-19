### 解题思路
先通过快慢指针找到中间结点，在这过程中将前面的结点值入栈，
然后依次比较后面的结点值和前面的结点值是否相同，
按测试样例，空链表也是回文的。

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func isPalindrome(head *ListNode) bool {
    // 先通过快慢指针找到中间结点，在这过程中将前面的结点值入栈
    // 然后依次比较后面的结点值和前面的结点值是否相同
    // 按测试样例，空链表也是回文的
    if head == nil || head.Next == nil {
        return true
    }
    
    pSlow, pFast := head, head
    var stack []int = make([]int, 0)
    for pFast!=nil && pFast.Next!=nil {
        stack = append(stack, pSlow.Val)
        pSlow = pSlow.Next
        pFast = pFast.Next.Next
    }

    // 链表长度为奇数
    if pFast!=nil {
        pSlow = pSlow.Next
    }
    
    for pSlow != nil {
        lenStack := len(stack)
        if pSlow.Val != stack[lenStack-1] {
            return false
        }
        stack = stack[:lenStack-1]
        pSlow = pSlow.Next
    }
    return true
}
```
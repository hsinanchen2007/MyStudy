
![image.png](https://pic.leetcode-cn.com/71fc698d676e2d4925a32e4b3213e1630c29d7964c9f45189e4538fb0069aafb-image.png)

思路：先使用快慢指针定位链表中点，然后反转中点的后半部分，最后分别从开头和中点处遍历比较是否是回文链表

代码：
```
func isPalindrome(head *ListNode) bool {    // 使用快慢指针寻找链表中点，然后反转后半部分，再分别从开头和中点处遍历比较
    if head == nil {
        return true
    }
    // 1. 快慢指针寻找链表中点
    slow,fast := head,head
    for fast!=nil && fast.Next != nil {
        fast = fast.Next.Next   // 快指针一次走两步
        slow = slow.Next        // 慢指针一次走一步
    }
    // 2. 从中点开始反转链表后半部分
    var pre,cur *ListNode = nil,slow
    for cur!=nil {
        next := cur.Next    // 先记录下下一个节点，不然一会就没了
        cur.Next = pre      // 当前节点指向上一个节点
        pre = cur           // 指针后移
        cur = next
    }
    // 3. 分别从开头和中点处遍历比较
    mid := pre
    for mid!=nil {
        if head.Val != mid.Val {    // 比较每一个元素
            return false
        }
        mid = mid.Next  // 指针后移
        head = head.Next
    }
    return true
    
}
```
```
class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        # 解题思路：翻转前半段链表，比较前半段链表与后半段链表是否相等
        # 利用快慢指针寻找中间节点
        # slow_node = head
        # fast_node = head
        # pre =ListNode(None)

        # while (fast_node and fast_node.next):
        #     # 快针走的长度是慢针的两倍，所以快针停的时候慢针处在中间位置
        #     # 头插法翻转前半段链表
        #     oldCur = slow_node
        #     slow_node = slow_node.next
        #     fast_node = fast_node.next.next
        #     oldCur.next = pre
        #     pre = oldCur
        
        # # fast_node不为空，则说明是链表元素个数为奇数
        # if fast_node:
        #     slow_node = slow_node.next

        # while slow_node:
        #     if (pre.val != slow_node.val):
        #         return False

        #     pre = pre.next
        #     slow_node = slow_node.next

        # return True
```

```
class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        # 堆栈解法
        slow_node = head
        fast_node = head
        L = []
        while (fast_node and fast_node.next):
            L.append(slow_node.val)
            slow_node = slow_node.next
            fast_node = fast_node.next.next

        if fast_node:
            slow_node = slow_node.next

        while L:
            if L.pop() != slow_node.val:
                return False
            else:
                slow_node = slow_node.next

        return True
```

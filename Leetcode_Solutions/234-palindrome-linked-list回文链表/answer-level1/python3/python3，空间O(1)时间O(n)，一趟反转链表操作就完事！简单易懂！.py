为啥大部分人思路都是双指针找中点+反转前半段链表与后半段来比较？一趟反转再整体比较不就完事了吗？
```
class ListNode:
    def __init__(self, x, y):
        self.val = x
        self.next = y

class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        p, q = head, None
        while p:
            q ,p = ListNode(p.val, q), p.next
        while q and q.val==head.val:
            q, head = q.next, head.next
        return q is None
```
这不也是空间O(1)时间O(n)吗（时间O(2n)也是时间O(n)呀）？

下面就按双指针找中点+反转前半段链表与后半段来比较，加深下双指针的印象：
```
class ListNode(object):
    def __init__(self, x, y):
        self.val = x
        self.next = y

class Solution(object):
    def isPalindrome(self, head):
        # 找中点：slow就是中间节点
        fast = slow = head
        while fast and fast.next:
            fast, slow = fast.next.next, slow.next
        # slow节点后半段逆序生成新链表（包含slow节点，新链表命名为fast）
        fast = None
        while slow:
            fast, slow = ListNode(slow.val,fast), slow.next
        # 比较fast链表和原始链表前部分是否相同
        while fast and fast.val==head.val:
            fast, head = fast.next, head.next
        # 如果链表相同，fast一定被遍历完，就一定是None
        return fast is None
```
是不是简单好理解呢！但是思路比起第一种还是复杂了。
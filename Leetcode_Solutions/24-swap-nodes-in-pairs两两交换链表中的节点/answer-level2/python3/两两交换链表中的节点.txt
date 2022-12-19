### 迭代

* 三个指针: `p1` `p2` `p3`

<![幻灯片26.JPG](https://pic.leetcode-cn.com/39852411f9f5262d7cbcc2d81c5c90d4c645c8755a62adde500b9fe7eba6bc09-%E5%B9%BB%E7%81%AF%E7%89%8726.JPG),![幻灯片27.JPG](https://pic.leetcode-cn.com/0805f3f46a756110ab68a42789b3d0a9e953d5e439909870efe327e7819acee4-%E5%B9%BB%E7%81%AF%E7%89%8727.JPG),![幻灯片28.JPG](https://pic.leetcode-cn.com/deb122b21d8975810d95f76fbc861f52585109dbc354e64c9b4f0bead6464ea5-%E5%B9%BB%E7%81%AF%E7%89%8728.JPG),![幻灯片29.JPG](https://pic.leetcode-cn.com/4d2ae0e62b48b8bccf0bcae8b89983eb428f08239d956f0d0ca7fbfd6f3f2a98-%E5%B9%BB%E7%81%AF%E7%89%8729.JPG),![幻灯片30.JPG](https://pic.leetcode-cn.com/35a4739d94b2a0f08f382f79a1f6f427e187eef490bc9e17a23224ed6f056174-%E5%B9%BB%E7%81%AF%E7%89%8730.JPG),![幻灯片31.JPG](https://pic.leetcode-cn.com/cc49fcbe4e6d22e7a4bfc21d17208c7076532b7065c0096546f3855f380e853a-%E5%B9%BB%E7%81%AF%E7%89%8731.JPG),![幻灯片32.JPG](https://pic.leetcode-cn.com/81a38ad7567ebeb618858c2a4537a19898ae449c8cea59b2b689a580b050fe13-%E5%B9%BB%E7%81%AF%E7%89%8732.JPG)>


```python []
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        dummy = ListNode(0)
        dummy.next = head
        p1 = dummy
        while p1.next and p1.next.next:
            p2 = p1.next.next
            p3 = p2.next
            p2.next = p1.next
            p1.next.next = p3
            p1.next = p2
            p1 = p2.next
        return dummy.next
```

### 递归

* 三个指针: `head` 当前节点，`tail`后面已经处理好的链表的头节点，`start`整个链表的头节点

<![幻灯片33.JPG](https://pic.leetcode-cn.com/016cff32c7818769adfedbe2560480b2af0b5fac096b8b9cc592220acfdd1213-%E5%B9%BB%E7%81%AF%E7%89%8733.JPG),![幻灯片34.JPG](https://pic.leetcode-cn.com/b1df4f5beb407959e95a43a326f51f58d706e44dccbdf9f5bf2103aba06852a6-%E5%B9%BB%E7%81%AF%E7%89%8734.JPG),![幻灯片35.JPG](https://pic.leetcode-cn.com/3ba68850491b3ad3c7888e15223d215f684ca6243ea90c423c5438c6f96d285c-%E5%B9%BB%E7%81%AF%E7%89%8735.JPG),![幻灯片36.JPG](https://pic.leetcode-cn.com/66b1bd42eb292f85a02138bd123cd7146009ce44b268e006687284acaa99c56e-%E5%B9%BB%E7%81%AF%E7%89%8736.JPG),![幻灯片37.JPG](https://pic.leetcode-cn.com/4d22e76ce3c008279c1a40dd716a767f4643a491d81a9711a28276d3a81e322f-%E5%B9%BB%E7%81%AF%E7%89%8737.JPG),![幻灯片38.JPG](https://pic.leetcode-cn.com/a711a580159d9e6cfdf07c9423a5f0458417715b4094374f11e1b6c97c2e42a9-%E5%B9%BB%E7%81%AF%E7%89%8738.JPG)>


```python []
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        tail = self.swapPairs(head.next.next)
        start = head.next
        start.next = head
        head.next = tail
        return start
```
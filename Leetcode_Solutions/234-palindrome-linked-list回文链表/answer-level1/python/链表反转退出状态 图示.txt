#### 链表反转

图示第一次遍历结束时的状态。
因为搞了半天也不知道循环退出时，快慢指针究竟走到了哪里。后来明白了，于是做了图，帮助理解。


设置一个快指针，一个慢指针。
慢指针一次走**一步**，快指针一次走**两步**，待到快指针遍历完成，慢指针就走到了中点结点位置。
慢指针同时做了反转操作。
然后同时从中间开始遍历，看是否为回文链表。

示例代码：
```py
    def isPalindrome(self, head: ListNode) -> bool:
        slow, fast, pre = head, head, None
        while fast and fast.next:
            fast = fast.next.next 
            slow.next, pre, slow = pre, slow, slow.next
 
        node1 = pre
        node2 = slow.next if fast else slow  # 奇为slow.next
 
        while node1:
            if node1.val != node2.val:
                return False
            node1, node2 = node1.next, node2.next
        return True
```

**注意**：对于偶数链表和奇数链表，终止时的状态是不同的。

奇数链表：
![奇数链表.png](https://pic.leetcode-cn.com/217513a209f034cf0e84b141e1248cd44a324018e616c3c685f276c292c95d50-%E5%A5%87%E6%95%B0%E9%93%BE%E8%A1%A8.png)

偶数链表：
![偶数链表.png](https://pic.leetcode-cn.com/acfc88b8eb6631efe1d23f0621664d7fac6bda3246dfd6c815a5343f03b8248b-%E5%81%B6%E6%95%B0%E9%93%BE%E8%A1%A8.png)



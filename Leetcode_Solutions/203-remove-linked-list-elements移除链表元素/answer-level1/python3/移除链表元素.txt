

##### 解题思路
在链表中删除某一个元素，往往是跳过这个元素，使指针指向下一个元素。所以，本题的解题思路也是如此。我们还需要考虑给定值`val`可能出现的位置：
1. `val`出现在链表的第一个位置
2. `val`出现在链表其它位置

由于`val`可能出现在第一个位置，所以我们需要设置一个哨兵节点`start_head`，否则无法删除第一个元素。

##### 代码如下
```
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        #设置哨兵节点
        start_head = ListNode(0)
        #使哨兵节点的下一个节点为head，head为链表的第一个节点
        start_head.next = head

        #设立两个指针，pre指向哨兵节点，cur指向head
        pre,cur = start_head,head

        #循环条件为当前节点存在
        while cur:
            #cur指向head，如果其值等于val，那么pre的下一个节点就是cur的下一个节点
            if cur.val == val:
                pre.next = cur.next
            else:
            #如果不相等，就使pre指向cur所在位置，相当于pre向前移动一位
                pre = cur
            #cur指针向前移动一位
            cur = cur.next

        return start_head.next
```

上述代码使用了两个指针解决这道题目，而使用一个指针同样可以完成。两者思路是一样的，代码如下：

```
class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        start_head = ListNode(0)
        start_head.next = head

        #设置指针cur指向start_head
        cur = start_head

        #循环条件为：cur的下一个节点存在
        while cur.next != None:
            if cur.next.val == val:
                cur.next = cur.next.next
            else:
                cur = cur.next

        return start_head.next
```
![公众号二维码.jpg](https://pic.leetcode-cn.com/53df5d51bc15be66598900624e7f34c81d79651108c3271ca209d9a529839e8a-%E5%85%AC%E4%BC%97%E5%8F%B7%E4%BA%8C%E7%BB%B4%E7%A0%81.jpg)
记录自己学习的过程，欢迎关注，大家一起进步！


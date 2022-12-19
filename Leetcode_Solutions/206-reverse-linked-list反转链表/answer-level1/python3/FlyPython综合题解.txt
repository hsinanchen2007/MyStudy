公众号连载leetcode题解，欢迎关注。

![](https://pic.leetcode-cn.com/2a15d78b4b977527a4d95f2bb238db8c82b7d133878dbf168b4b972271818c58.jpg)


题目汇总： [leetcode](http://flypython.com/leetcode/) 


#### 思路

反转链表比较简单，两种方法都说一下。

1. 迭代
迭代就是遍历的时候，直接改变当前节点next的指针指向前一个元素，你需要前存储前一个元素。

时间复杂度：O(n)
空间复杂度：O(1)

2. 递归
递归主要就是为了做反向，代码也比较好写。

时间复杂度：O(n)
空间复杂度：O(n) 这里使用了递归，递归深度可能到n

#### 方案代码

迭代：

```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        cur, prev = head, None
        while cur:
            cur.next, prev, cur = prev,cur, cur.next
        return prev
```


递归：

```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head

        nextNode = self.reverseList(head.next)
        head.next.next = head
        head.next = None
        return nextNode
```


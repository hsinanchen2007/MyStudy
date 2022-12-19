### 解题思路1 一次遍历，快慢指针法
1. 快指针先比慢指针先走n步
2. 两者同时往后移动，直至快指针移动至末节点，此时慢指针指向倒数n+1个节点
3. 将慢指针的next指向下一个节点的next，即删除了倒数第n个节点
代码中为了方便处理边界情况，先往链首增加了一个节点(慢指针需指向倒数n+1,当n等于链表长度时，会溢出，故增加一个节点)

### 代码

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        p = ListNode(-1)
        p.next, head = head, p
        _slow = _fast = head
        for i in range(n):
            _fast = _fast.next
        while _fast and _fast.next:
            _fast = _fast.next
            _slow = _slow.next
        _slow.next = _slow.next.next
        return head.next
```

### 解题思路2 一次遍历 空间换时间
一次遍历，将遍历的顺序存储至堆(python-list)
遍历结束后，直接可以获取到倒数第n个节点
然后更新链表，将倒数第n+1个节点的next指向倒数n-1个节点
然后这里情况分三种：
1. 倒数第n个节点是首节点
2. 倒数第n个节点是末节点
3. 倒数第n个节点处在链表非首尾的位置
以下我的代码较为巧妙的处理了这三种情况

### 代码

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        visted = []
        while head:
            visted.append(head)
            head = head.next
        length = len(visted)
        if n < length:
            visted[-1 * (n + 1)].next = None if n == 1 else visted[-1 * (n - 1)]
        visted.pop(-1 * n)
        return visted[0] if visted else None
        
```
### 迭代+指针
1. 核心是pre cur nxt，cur是需要翻转的部分start~end
2. 记录下pre和nxt，然后翻转start~end得到end~start，再把pre end~start nxt连在一起
3. 并且start = pre.next nxt = end.next，所以只需要确定pre end就可以知道pre start end nxt
4. reverse函数：指针，翻转长度为k的链表，第k个节点的next是None，核心也是pre cur nxt

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    
    def reverse(self, head):
        pre = None
        cur = head
        while cur:
            nxt = cur.next
            cur.next = pre
            pre = cur
            cur = nxt
        return pre
        
    
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        dummy = ListNode(0)
        dummy.next = head
        
        pre = end = dummy
        while pre:
            for _ in range(k):
                if end:
                    end = end.next
            # 如果end是None则说明不满k个不需要翻转了
            if not end:
                break
            # 由pre和end得到start和nxt
            start = pre.next
            nxt = end.next
            # print('start:', start)
            # print('end:', end)
            # 记录下了pre和nxt 就可以放心翻转start~end了
            end.next = None
            new_head = self.reverse(start)
            # 将翻转过的链表和pre nxt连起来
            pre.next = new_head
            start.next = nxt
            # 移动pre和end的位置
            pre = start
            end = pre
        return dummy.next
```

### 递归+指针
执行用时 :48 ms, 在所有 Python3 提交中击败了89.97%的用户
内存消耗 :14.5 MB, 在所有 Python3 提交中击败了5.26%的用户

思路：
思路和迭代方法类似，但因为用了递归就不需要记录pre了
1. reverseKGroup函数：递归，翻转前k个节点，并把翻转后的链表和“后面的”连接在一起，“后面的”也是reverseKGroup函数得到的，因为不需要和“前面的”连在一起了，所以不需要记录pre

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    
    def reverse(self, p):
        pre = None
        cur = nxt = p
        while cur:
            nxt = cur.next
            cur.next = pre
            pre = cur
            cur = nxt
        return pre
    
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        if not head:
            return None
        
        start = end = head
        for _ in range(k-1):
            if end:
                end = end.next
        if not end:
            return head
        nxt = end.next
        end.next = None
        new_head = self.reverse(start)
        start.next = self.reverseKGroup(nxt, k)
        
        return new_head
```


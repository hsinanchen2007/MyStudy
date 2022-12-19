### 啰嗦几句
在我心中这可比很多“简单”的题简单多了。

### 解题思路（一次遍历）
想法就是，如果有两个指针能够一直保持n的间距一起向前走，那么靠后的指针走到最后的时候，我们就能找到该删除的第n个节点了。
需要注意的是，在一般的写法中，需要单独考虑如果所删除的元素是头结点的情况。
为了解决这个问题，我在写的时候，在开头加了一个节点，是什么都无所谓，最后返回的就是新的头结点的下一个节点。

### 代码1：一次遍历

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        # 在开头加一个节点，就可以避免如果删除的是开头的问题。
        new_head = ListNode()
        new_head.next = head
        
        # 设置两个指针，q比p先走n步
        p, q = new_head, new_head
        for i in range(n):
            if q:
                q = q.next
            else:
                return head

        # 此时q已经超前p了n步，然后再两个一起走
        while q.next:
            p = p.next
            q = q.next
        # 走到q.next为空为止，删掉p.next
        p.next = p.next.next  
        
        return new_head.next


```

### 代码2：两次遍历

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        # 首先先遍历一次得到链表的总长度
        count = 0
        cur = head
        while cur is not None:
            count += 1
            cur = cur.next
        
        index = count - n + 1

        pre = None
        cur = head
        count1 = 1
        while cur is not None:
            
            if count1 == index:
                if pre is None:
                    head = cur.next
                else:
                    pre.next = cur.next
                break
            else:
                pre = cur
                cur = cur.next
                count1 += 1
        
        return head


```
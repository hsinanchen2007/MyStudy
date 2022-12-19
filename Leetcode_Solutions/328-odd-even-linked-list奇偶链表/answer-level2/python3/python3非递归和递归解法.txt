## 非递归解法
和86-Partitions List思路几乎一样,这里用了5个指针。但是官方题解中只用了4个指针。
```python
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    cnt = 1

    def oddEvenList(self, head: ListNode) -> ListNode:
        dummy_odd = odd = ListNode(None)
        dummy_even = even = ListNode(None)

        while head:
            if self.cnt % 2:  # odd
                odd.next = head
                odd = odd.next
            else:  # even
                even.next = head
                even = even.next
            self.cnt += 1
            head = head.next

        even.next = None
        odd.next = dummy_even.next

        return dummy_odd.next
```

## 递归解法

### 解法1：在递进中求解
这里的递归函数没有任何回溯过程，主要逻辑和非递归写法一样
```python
class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        dummy_odd = odd = ListNode(None)
        dummy_even = even = ListNode(None)

        def recursive(head, idx):
            nonlocal odd, even
            if head is None:
                return

            if idx % 2:  # odd
                odd.next = head
                odd = odd.next
            else:
                even.next = head
                even = even.next

            recursive(head.next, idx + 1)
            return

        recursive(head, 1)
        even.next = None
        odd.next = dummy_even.next
        return dummy_odd.next
```
### 解法2：在回溯中求解
思路是：
将当前节点和已经完成奇偶分类的子链去拼接。
* 如果当前节点是奇节点，则当前节点直接连上子链最前端。
* 如果当前节点是偶节点，则当前节点需要插到子链的所有奇节点之后。

所以需要递归函数返回子链的头结点和子链中最后一个奇节点（用来插入偶节点）。`idx`用来判断奇偶，`pre`用来清除删除节点时产生的野指针。
```python
class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        dummy_head = ListNode(None)
        dummy_head.next = head

        pre = dummy_head
        cur = head

        def recursive(pre, cur, idx):
            if cur is None or cur.next is None:
                if idx % 2 == 0:  # 最后一个节点是even
                    tail = ListNode(None)  # 创造一个假的奇数节点，以抱枕child_gap一定存在
                    tail.next = cur
                    return tail, tail
                else:  # 最后一个节点是odd
                    return cur, cur

            child_head, child_gap = recursive(pre.next, cur.next, idx + 1)

            if idx % 2:  # odd
                if child_head.val is None:  # 如果遇到假的奇数节点，删除之
                    cur.next = child_head.next
                    child_head.next = None
                    return cur, cur
                cur.next = child_head
                return cur, child_gap
            # even, 由于base case中保证了child_gap存在
            cur.next = child_gap.next
            child_gap.next = cur
            pre.next = child_head  # 原来pre.next指向cur，消除野指针
            return child_head, child_gap

        new_head, _ = recursive(pre, cur, 1)

        return new_head
```

### 解法3：避免奇偶节点的讨论
根据24的解法改编
```python
class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        
        odd_tail = None
        def recursive(head):
            nonlocal odd_tail
            if not head:
                return None, None
            if not head.next:
                return head, None

            nxt = head.next
            odd, even = recursive(nxt.next)
            
            if not odd:
                odd_tail = head
            elif not even:
                odd_tail = odd
                
            head.next = odd
            nxt.next = even
            return head, nxt
        
        a, b = recursive(head)
        if odd_tail:
            odd_tail.next = b
        return a
```
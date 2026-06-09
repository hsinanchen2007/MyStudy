### 解题思路
三种方法时间复杂度都是O(N)
- 遍历链表，利用列表history存下所有结点；history[len(history)//2]即为结果；
- 第一次遍历链表，记录长度N;第二次遍历链表计数至N//2输出结点；
- 快慢指针，fast到达链尾时，slow一定在链表中间。
- 假设链表长度2n+1,经过n次移动，fast到达位置1+2n，slow到达1+n
- 假设链表长度2n,经过n次移动，fast到达位置1+2n(fast到达链尾空节点),slow到达位置1+n

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        history = []
        while head:
            history.append(head)
            head = head.next
        L = len(history)
        return history[L//2]
```
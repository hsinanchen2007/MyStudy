### 解题思路
思路见代码，想理解就看注释里的代码，想精简就看没注释的；

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        """
        思路：设置pre，cur，next 三个指针
        """
        pre, cur = None, head
        while cur:
            cur.next, pre, cur = pre, cur , cur.next
        # while cur:
        #     next = cur.next # 指向当前节点的下一个节点
        #     cur.next = pre # 对当前节点进行逆向，把当前节点的下一个节点设置为前一个节点
        #     pre = cur # pre指针向后移动，指向cur
        #     cur = next # cur指针向后移动，指向下一个节点
        return pre
            
```
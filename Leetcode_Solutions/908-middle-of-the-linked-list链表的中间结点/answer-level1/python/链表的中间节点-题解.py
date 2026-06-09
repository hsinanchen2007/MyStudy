### 解题思路
思路比较简单
- 一次遍历，同时将遍历到的节点存入临时数组
- 并且，根据遍历记录的节点数，计算其中间节点索引；
- 最后根据索引在临时数组中进行取值即可

方法比较简单暴力，向大陆们多学习

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        if head is None:
            return head
        
        cnt = 0
        idx = 0
        rst = []
        while head:
            cnt += 1
            rst.append(head)

            if 2*(idx+1) == cnt:
                idx += 1

            head = head.next
        
        return rst[idx]
```
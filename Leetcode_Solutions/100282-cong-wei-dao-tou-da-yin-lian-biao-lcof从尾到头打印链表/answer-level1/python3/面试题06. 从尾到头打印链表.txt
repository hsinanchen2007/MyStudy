### 解题思路
此处撰写解题思路

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # def reversePrint(self, head: ListNode) -> List[int]:
    #     nums = []
    #     while head:
    #         nums.append(head.val)
    #         head = head.next
    #     nums = nums[::-1]
    #     return nums


    def reversePrint(self,head):
        if not head:
            return []
        return self.reversePrint(head.next) + [head.val]
```
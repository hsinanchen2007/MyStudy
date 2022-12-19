### 解题思路
1.创建一个空数组
2.遍历链表，将值加入数组中
3.返回倒叙数组

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reversePrint(self, head: ListNode) -> List[int]:
        stack=[]
        while head:
            stack.append(head.val)
            head=head.next
        return stack[::-1]
```
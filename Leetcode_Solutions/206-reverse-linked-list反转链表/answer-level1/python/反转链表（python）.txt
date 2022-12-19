### 解题思路
此处撰写解题思路
参考：https://www.cnblogs.com/tianqizhi/p/9673894.html
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if head is None:
            return head
        last = None #last指针用于指向上一个
        while head:
            tmp = head.next #先把下一个节点的地址保存，省得丢失
            head.next = last #下一个转换成上一个
            last = head#当前的就变成了上一个
            head = tmp#下一个就变成了了当前的
        return last
```
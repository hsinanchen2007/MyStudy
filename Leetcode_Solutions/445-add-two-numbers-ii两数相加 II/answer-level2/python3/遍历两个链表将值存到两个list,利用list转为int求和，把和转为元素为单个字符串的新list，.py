### 解题思路
遍历两个链表将值存到两个list,利用list转为int求和，把和转为元素为单个字符串的新list，
遍历新list创建节点，head指针标记头结点用于返回，first用于创建最后一个节点与新增节点之间的指向

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        res1=[]
        res2=[]
        while l1:
            res1.append(str(l1.val))
            l1=l1.next
        while l2:
            res2.append(str(l2.val))
            l2=l2.next
        sum1=int(''.join(res1))+int(''.join(res2))
        lis=[]
        lis.extend(str(sum1))
        head=first=ListNode(int(lis[0]))
        for i in range(1,len(lis)):
            first.next=ListNode(int(lis[i]))
            first=first.next
        return head
```
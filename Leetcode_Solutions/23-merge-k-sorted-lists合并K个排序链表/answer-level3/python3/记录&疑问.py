```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        amount = len(lists)
        interval = 1
        while interval < amount:
            for i in range(0, amount - interval, interval*2):
                lists[i] = self.merge2Lists(lists[i], lists[i + interval])
            interval *= 2
        if amount > 0:
            return lists[0]        

    def merge2Lists(self, l1, l2):
        head = point = ListNode(0)
        while l1 and l2:
            if l1.val <= l2.val:
                point.next = l1
                l1 = l1.next
            else:
                point.next = l2
                l2 = l2.next
            point = point.next
        if not l1:
            point.next = l2
        if not l2:
            point.next = l1
        return head.next
```
疑问：Python3执行
```
if amount > 0:
    return lists[0] 
加上下列代码执行不过：typeerror：[]不是预期的返回类型ListNode 官方测试输入[]
else:
    return lists
```



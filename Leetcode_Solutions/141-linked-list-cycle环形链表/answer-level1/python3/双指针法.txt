这个题双指针法需要注意两个点：
1、两个指针的速度要不一致，否则会出现死循环
2、通过这组数据[1,2] pos = 1，发现终止循环的条件要加上head.next.next != None
(3、测试用例记得修改pos的值，否则会出现奇奇怪怪的错误)

```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: ListNode) -> bool:

        if head == None or head.next == None:
            return 0
            
        a = head
        b = head.next

        while b != None and b.next != None:
            if a == b:
                return 1
            a = a.next
            b = b.next.next     # a b 速度不能一样，要一个快一个慢，否则死循环
        
        return 0
```


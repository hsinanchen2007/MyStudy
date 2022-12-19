### 解题思路
注意区分m, n的取值
m=1 and n=length return 翻转后的头
m=1 and n!=length
m!=1 and n=length 
见程序注释

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        
        length = 0
        ptr = head
        while ptr != None:
            length += 1
            if m == 1:
                temp_tail = head
            else:
                if length == m-1:
                    new_head = ptr
                    temp_tail = ptr.next
            if length == n:
                temp_head = ptr
                new_tail = ptr.next
            ptr = ptr.next
# 中间部分翻转
        loop = n-m+1
        p = temp_tail
        q = None
        while loop != 0:
            r = q
            q = p
            p = p.next
            q.next = r
            loop -= 1
# 遍历找到翻转部分的尾部tail
        top = q
        while top.next != None:
            top = top.next
# 翻转的部分与其他部分连接
        if m==1 and n==length:
            return q
        if m == 1:
            top.next = new_tail
            return q
        if n == length:
            new_head.next = q
            return head
        new_head.next = q
        top.next = new_tail
        return head



        

```
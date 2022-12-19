### 解题思路
1.令链表为非环部分长度为**a**, 环部分长度为**b**
2.**p1**为快指针，**p2**为慢指针,即**p1**走1步，**p2**走两步
3.若不存在环，则**p1**,**p2**不会相遇
4.存在环时,**p1**走到环入口时，**p1**走了**a**步，则**p1=a**, **p2=2a**
5.此时p2处于环的某个位置，**p2**距离环口长度为**b - (a%b)**，**p2**要追赶上**p1**,则还需走**b - (a%b)**步。
6.**p1 = a + b - (a%b)**。
7.**p1%b=(a+b-a%b)%b=(a%b+0-a%b)%b=0**,故p1的步数为a的整数倍
8.**p1**再走**a**步时，**p1 = a + nb**,则**p1**到达入口处。
9.令**p3=head,p1,p3**同步走，**p1**与**p3**相遇时则**p1**走了**a**步到达入口处


### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        if not head: return None
        p1 = head
        p2 = head
        while True:
            if p2 == None or p2.next == None: return
            p1 = p1.next
            p2 = p2.next.next
            if p1 == p2: break
        p3 = head
        while p1 != p3:
            p1 = p1.next
            p3 = p3.next
        return p3
        
```
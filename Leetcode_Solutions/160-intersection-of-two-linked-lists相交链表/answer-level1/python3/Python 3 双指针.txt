### 解题思路

计算两个路劲的长度，然后计算差值，谁长谁先走delta步，然后再一起走，如果相等则为交叉点，都走完了，还没有交叉，那么直接返回None吧，下面的写法，最后走完且不相交时，headA和headB都是None.

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        # 双指针法
        m, n = 0, 0
        dummyHead = headA
        while dummyHead != None:
            dummyHead = dummyHead.next
            m += 1
        
        dummyHead = headB
        
        while dummyHead != None:
            dummyHead = dummyHead.next
            n += 1
            
        delta = abs( m - n )
        
        if m > n:
            while delta != 0:
                headA = headA.next
                delta -= 1
        else:
            while delta != 0:
                headB = headB.next
                delta -= 1
            
        # 开始一起走
        while headA and headB and headA != headB:
            headA = headA.next
            headB = headB.next
        
        return headA
    
        # 这个解法有点太耗空间了呀
        
        
        
        
```

END.
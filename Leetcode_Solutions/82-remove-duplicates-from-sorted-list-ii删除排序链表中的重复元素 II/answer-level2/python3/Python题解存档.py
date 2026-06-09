### 解题思路
这道题目要求我们在有序链表中，寻找长度超过1的同元素子链表，并将其删除。
所以思路是用两个指针标记子链表的开头和结尾。对于长度小于2的链表，直接返回原状。
当子链表不存在时，头尾指针正常向后遍历。
当子链表存在时，尾指针向后遍历，确定下一个元素是否仍在子链，
如果不属于，则可以删除掉该子链，因为重复的元素已经确定了。
最后考虑到同元素子链在结尾的情况。再做一次判断。

至于删除的方法，用头指针之前的一个节点，将其后项指定为尾指针所在处，就直接跳过了所有的同元素子链表。

时间复杂度为O(n),空间复杂度为常数。
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        
        if head == None:
            return None
        if head.next == None:
            return head 
        fk = ListNode(0)
        fk.next = head
        A = fk
        B = A.next
        P = B.next
        hasDuplicated = False
        while P!=None:
            if P.val == B.val:
                P = P.next
                hasDuplicated = True
            elif hasDuplicated == True:
                A.next = P
                B = A.next
                P = P.next
                hasDuplicated = False
            else:
                A =B
                B = B.next
                P = P.next
        if hasDuplicated:
            A.next = P
        return fk.next
```
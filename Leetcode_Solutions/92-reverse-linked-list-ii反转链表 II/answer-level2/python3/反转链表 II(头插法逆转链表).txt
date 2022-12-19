
![image.png](https://pic.leetcode-cn.com/52e0edd882cf2fa6e47736385821f0590ed38bdda728c7767a268dac32eaac19-image.png)



```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution: # 计数从1开始
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        if head is None or head.next is None or m == n:
            return head

        temp_head = ListNode(0)
        temp_head.next = None

        p = head
        for _ in range(1,m-1):
            p = p.next  # p为第m-1个结点
        
        if m == 1:
            p = temp_head  
            q = head  # q为第m个结点            
        else:
            q = p.next # q为第m个结点
        r = q # r为第m个结点，同时作为逆转链表的最后一个结点

        for _ in range(n-m+1): # 头插法进行m-n的链表逆置
            temp = q
            q = q.next
            temp.next = temp_head.next
            temp_head.next = temp

        if m == 1:
            r.next = q
            return temp_head.next

        else:
            p.next = temp_head.next # p为第m-1个结点
            r.next = q   # r为逆转链表的最后一个结点
            return head
        

        




```

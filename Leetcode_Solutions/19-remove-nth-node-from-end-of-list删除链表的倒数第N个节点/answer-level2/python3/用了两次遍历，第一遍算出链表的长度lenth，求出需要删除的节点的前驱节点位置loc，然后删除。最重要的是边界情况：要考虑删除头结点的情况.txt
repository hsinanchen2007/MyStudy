### 解题思路
此处撰写解题思路

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        '''得到链表的长度'''
        count_1 = 0
        pre = head
        while pre != None:
            pre = pre.next
            count_1 += 1
        lenth = count_1

        loc = lenth - n #loc为需要删除的节点的前驱节点的正序位置、从0开始计数
        cur = head
        count_2 = 1
        if loc == 0:  #若loc==0，意味着删除的是头节点
            head = head.next
            return(head)
        while count_2 != loc:
            cur = cur.next
            count_2 += 1
        
        '''循环结束、cur指向需删除节点的前驱'''
        x = cur.next.next
        cur.next = x
        return(head)
```
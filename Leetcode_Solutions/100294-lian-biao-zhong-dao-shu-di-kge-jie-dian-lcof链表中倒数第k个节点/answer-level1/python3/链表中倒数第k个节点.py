### 解题思路

1. ##和操作思路相反##
2. 双指针：a先走k步，然后a，b同步走直到a到达终点

### 操作思路 
1. 同二叉树，需要仔细看链表定义的结构
2. 利用中间变量temp，计算出链表的长度--注意temp最后的值是最后一次循环的head.text,not head本身！
3. 利用链表的长度找到倒数第K个节点

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getKthFromEnd(self, head: ListNode, k: int) -> ListNode:
        # 解题思路1
        # if not head or k<=0 :return None
        # temp = head
        # len_head = 1
        # while temp.next != None:
        #     temp = temp.next
        #     len_head += 1
        # # print(temp)
        # for i in range(len_head-k):
        #     head = head.next
        # return head

        # 解题思路2：双指针
        if head == None or k <= 0:return None
        a = head
        b = head
        for i in range(1,k):
            if a.next == None:return 
            a = a.next
        while a.next != None:
            a = a.next
            b = b.next
        return b
```
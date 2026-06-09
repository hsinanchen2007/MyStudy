### 解题思路
![image.png](https://pic.leetcode-cn.com/26e84b16ca52508be8a779ec7cdcb542fd90a08a8790adc9766f9a9aa413a2fa-image.png)
思路总体来说遍历两次，先将比给定值x小的值按顺序遍历存放在结果列表中，再将大于等于x的值遍历存放在结果列表中，最后返回一个遍历结果列表的链表就可以了
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        res_list = []
        node1 = head
        node2 = head
        while node1:
            if node1.val < x:
                res_list.append(node1.val)
                node1 = node1.next
            else:
                node1 = node1.next
        while node2:
            if node2.val >= x:
                res_list.append(node2.val)
                node2 = node2.next
            else:
                node2 = node2.next
        res = head
        for item in res_list:
            res.val = item
            res = res.next
        return head


```
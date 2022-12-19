### 解题思路
首先实现2个有序链表的合并，而后按照归并排序的思路，持续对K个链表进行两两排序，如果是奇数个，则最后一个链表本轮不排序直接进入下一轮，直至最终只剩下一个链表结束。

### 结果

![image.png](https://pic.leetcode-cn.com/305f345222a00a40226a05a41f84a6a4312ac1b3a7014c8bcca8f9580e0f56b7-image.png)

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        def merge2lists(ListNode1, ListNode2):#两个链表的排序
            cur = dummy = ListNode(-1)
            while ListNode1 and ListNode2:
                if ListNode1.val <= ListNode2.val:
                    cur.next, ListNode1 = ListNode1, ListNode1.next
                else:
                    cur.next, ListNode2 = ListNode2, ListNode2.next
                cur = cur.next
            cur.next = ListNode1 if ListNode1 else ListNode2
            return dummy.next

        if not lists:
            return []
        while len(lists)>1:#类似归并实现K链表的两两排序
            tmp = []
            for i in range(len(lists)//2):
                tmp.append(merge2lists(lists[2*i], lists[2*i+1])) 
            if len(lists)%2:
                tmp.append(lists[-1])
            lists = tmp
        return lists[0]
```
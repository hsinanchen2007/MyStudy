### 解题思路
![image.png](https://pic.leetcode-cn.com/466f817adababcdb8fa9dc97228d316df777798f2890eb53e9c24c660dbd069a-image.png)
- 相信大家对这个题应该很熟悉了,数据结构书中也有类似题目的出现
- 思路是: 比较两个链表当前节点的值,选择小的取下来连接到我们的最终结果链表上,如果相等就都取下来
- 重点在于将指针的顺序理清楚即可,别的无论是循环还是递归的写法都无可厚非
- 时间复杂度`O(n+m)`,空间复杂度`O(1)`

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        head = ListNode(0)
        result = head
        while l1 and l2:
            if l1.val == l2.val:
                temp_1 = l1.next
                temp_2 = l2.next
                l1.next = l2
                head.next = l1
                head = l2
                l1 = temp_1
                l2 = temp_2
            elif l1.val < l2.val:
                temp_1 = l1.next
                head.next = l1
                l1 = temp_1
                head = head.next
            else:
                temp_2 = l2.next
                head.next = l2
                l2 = l2.next
                head = head.next
        if l2:
            while l2:
                head.next = l2
                l2 = l2.next
                head = head.next
        else:
            while l1:
                head.next = l1
                l1 = l1.next
                head = head.next
        return result.next





```
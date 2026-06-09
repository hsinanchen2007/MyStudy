### 解题思路
将链表中的值转成字符串，然后转成int类型，然后直接相加
将得到的结果转成字符串，然后用字符串里面的值创建链表

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        res1 = []
        res2 = []
        while l1:
            res1.append(l1.val)
            l1 = l1.next
        res1.reverse()

        while l2:
            res2.append(l2.val)
            l2 = l2.next
        res2.reverse()

        str1 = ''.join(map(str, res1))
        str2 = ''.join(map(str, res2))
        a = int(str1)
        b = int(str2)

        c = a + b
        c = str(c)

        dummy = ListNode(0)
        pre = dummy
        for i in c[::-1]:
            node = ListNode(int(i))
            pre.next = node
            pre = pre.next
        return dummy.next
```
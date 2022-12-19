### 解题思路
中文版没有筛选语言的功能吗？？？

最后递归结束条件卡了好久，各种判断None不None的人都傻了。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:

        def add(ret, l1, l2, flag=0):
            if not l1:
                l1_val = 0
                l1_next = None
            else:
                l1_val = l1.val
                l1_next = l1.next
            if not l2:
                l2_val = 0
                l2_next = None
            else:
                l2_val = l2.val
                l2_next = l2.next
            tmp = l1_val + l2_val + flag

            flag = 0
            if tmp >= 10:
                tmp = tmp % 10
                flag = 1
            ret.next = ListNode(tmp)
            ret = ret.next
            
            # 这个判断好复杂啊
            # l1空了，l1.next会报错。
            if l1_next or l2_next or flag:
                add(ret, l1_next, l2_next, flag)
            return
                

        ret = ListNode(0)
        add(ret, l1, l2)

        return ret.next
```
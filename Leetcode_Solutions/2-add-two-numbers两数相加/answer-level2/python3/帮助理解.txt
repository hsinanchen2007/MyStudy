### 解题思路
两链表左对齐后，长度不够的以0补位，进行从左到右的竖式加法运算

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        新建链表头 = 新建链表 = ListNode(None)
        进一位 = 0  
        while l1 or l2:  # 当任意一个没走到底就继续
              # 三种情况：如果两个表都没到底表1加表2 or 表1到底取表2值 or 表2到底取表1值
            表头对齐相加的和 = (l1.val + l2.val + 进一位) if l1 and l2 else ((l1 or l2).val + 进一位)  # 刚开始相加前面不会进一位，后面根据和是否大于10判断
            新建链表头.next = ListNode(表头对齐相加的和 % 10)  # 更新现在的新链表头，取和的个位
            进一位 = 表头对齐相加的和 // 10  # 等于0或者1，根据和是否小于10
            # 同时向后移动两个链表的头直到节点是None
            l1 = l1.next if l1 else l1
            l2 = l2.next if l2 else l2
            新建链表头 = 新建链表头.next  # 移动到下一个节点继续添加值
        新建链表头.next = ListNode(进一位) if 进一位 else None  # 最后如果还有个10没进一位，还需要在加上
        return 新建链表.next
```
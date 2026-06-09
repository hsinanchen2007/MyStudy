### 解题思路
pre_cur作为前驱节点，head作为当前结点，先保存当前结点后继(temp)，然后更改当前结点后继为其自身的前驱，然后更新pre_cur(head)和head(temp)，注意pre_cur初始值设为None，可省去反转完成后的尾结点处理。

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        pre_cur = None     # 前驱开始为None，即可省去单独处理表头
        while head:
            temp = head.next        # 保存后继，作为下一个head
            head.next = pre_cur     # 前驱变后继
            # 处理一个转换一个
            pre_cur = head     # 当前对象变前驱
            head = temp     # 后继变当前处理对象
        return pre_cur
```
### 双指针
- 思路:
- 设置指针`temp`先在链表中走`k`步,在使用另一个指针`result`从头开始,这是两个指针之间的间距为`k`,同时前进,直到`temp`到达最后最后一个节点,这时`result`就指向了倒数敌`k`个节点,返回即可
- 同时我们还需要考虑是否存在倒数第`k`节点的情况
- 时间复杂度`O(n)`,空间复杂度`O(1)`

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getKthFromEnd(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        result = head
        temp = head
        num = 1
        while num != k and temp:
            temp = temp.next
            num += 1
        if num != k:# 判断是否存在倒数第K个节点
            return None
        while temp.next:
            result = result.next
            temp = temp.next
        return result

```
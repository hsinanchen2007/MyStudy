### 解题思路
学习结果里面的内存最佳方法。

**本题关键思路**：思路与之前写的暴力解决也是完全一样，也是构建一个新的链表。实现上有区别，没有构建一个ListNode(x)来打头，而且麻烦一点以先判断l1和L2哪个小，以小的数值构建开头的ListNode。https://leetcode-cn.com/problems/merge-two-sorted-lists/solution/bu-zhi-dao-neng-bu-neng-jian-chi-de-xiao-bai-bao-2/

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        prev = None
        new_head = None
        while l1 and l2:
            if l1.val <= l2.val:
                l3 = ListNode(l1.val)
                l1 = l1.next
            else:
                l3 = ListNode(l2.val)
                l2 = l2.next
            # 初始化链表，让链表直接以l1.val和l2.val小的构建新链表头，并留一个指针new_head指向这个头作为返回值用，prev指针作为遍历用
            if prev:
                prev.next = l3
                prev = l3
            else:
                prev = l3
                new_head = prev
        if prev is None:
            if l1 is None:
                return l2
            else:
                return l1
        if l1:
            prev.next = l1
        else:
            prev.next = l2
        return new_head
```
### 解题思路
学习结果里面的时间最佳方法。

**本题关键思路**：思路与之前写的暴力解决完全一样，就是构建一个新的链表。实现上也基本一样，就是有一行重复代码原先复制粘贴的时候直接卸载if else里面，应该放出到while层。https://leetcode-cn.com/problems/merge-two-sorted-lists/solution/bu-zhi-dao-neng-bu-neng-jian-chi-de-xiao-bai-bao-2/

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        head = ListNode(0)
        cur = head
        cur1 = l1
        cur2 = l2
        while cur1 and cur2:
            if cur1.val <= cur2.val:
                cur.next = cur1
                cur1 = cur1.next
            else:
                cur.next = cur2
                cur2 = cur2.next
            # 这句重复的写外面就行了，当时就直接复制粘贴没注意
            cur = cur.next
        if cur1:
            cur.next = cur1
        if cur2:
            cur.next = cur2
        return head.next
```
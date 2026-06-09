### 解题思路
1.
暴力解法，创建一个set，遍历节点，若不存在则放入，存在则删除

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeDuplicateNodes(self, head: ListNode) -> ListNode:
        if head == None:
            return
        A = set()
        A.add(head.val)
        prev, p = head, head.next
        while p:
            if p.val in A:
                prev.next = p.next
                del p
                p = prev.next
            else:
                A.add(p.val)
                prev = p
                p = p.next

        return head

'''
作者：gelthin
链接：https://leetcode-cn.com/problems/remove-duplicate-node-lcci/solution/gelthin-shi-yong-yi-ge-set-by-gelthin/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
'''
```
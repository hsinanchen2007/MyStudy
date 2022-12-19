### 解题思路
1.
暴力解法
2.
快慢指针

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def kthToLast(self, head: ListNode, k: int) -> int:
        i, j = head, head  # 似乎没有必要 设 prehead 虚拟头结点
        for _ in range(k):
            j = j.next
        while j!= None:
            i = i.next
            j = j.next
        return i.val

'''
作者：gelthin
链接：https://leetcode-cn.com/problems/kth-node-from-end-of-list-lcci/solution/gelthin-kuai-man-zhi-zhen-by-gelthin/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
'''
```
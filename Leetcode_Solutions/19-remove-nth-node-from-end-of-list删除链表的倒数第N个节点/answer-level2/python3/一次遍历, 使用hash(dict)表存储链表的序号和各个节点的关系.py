### 解题思路
执行用时 : 28 ms , 在所有 python3 提交中击败了 99.22% 的用户 
内存消耗 : 12.6 MB , 在所有 python3 提交中击败了 99.59% 的用户

创建一个随机访问节点O(1)时间复杂度的结构(dict)存储序号和节点的对应关系

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        store = {}
        num = 0
        while head:
            store[num] = head
            head = head.next
            num += 1

        index = num - n
        if 0 == index:
            # del head node
            head = store[index].next

        else:
            # other node
            head = store[0]
            store[index - 1].next = store[index].next
        return head

```
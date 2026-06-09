### 解题思路
(1)借鉴思维
用两个指针fast 和slow一起遍历链表
slow每次走一步，fast一次走两步
那么fast到达链表的末尾时，slow必然位于中间
（2）弯路集合
head类型是listnode，而不是List,不可以用len等数学方法来处理
（3）返回结果
返回结果是中间节点开头的后序列

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        fast,slow = head,head
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
        return slow


```
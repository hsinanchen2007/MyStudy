### 解题思路
设置两个指针同时向后遍历
当pre与cur相等时，只移动cur指针
不相等时，让pre.next指向cur，并移动pre至cur的位置
当cur移动到链尾None时，说明cur的前驱节点为pre或者都与pre相等，所以直接让pre指向cur就行
没看题解做了好多遍、可能是我太小白了吧

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if head == None:
            return(head)
        pre = head
        cur = pre
        while cur != None:
            if cur.val != pre.val:
                pre.next = cur
                pre = pre.next
            cur = cur.next
        pre.next = cur
        return(head)
            
```
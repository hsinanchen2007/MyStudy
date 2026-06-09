### 解题思路
普通循环法，用一个数组保存数字，然后逆序遍历

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
        #迭代方法
        nums=[]
        p = head
        while(p!=None):
            nums.append(p.val)
            p=p.next
        p = head
        for num in nums[::-1]:
            p.val = num
            p = p.next
        return head
        
        
```
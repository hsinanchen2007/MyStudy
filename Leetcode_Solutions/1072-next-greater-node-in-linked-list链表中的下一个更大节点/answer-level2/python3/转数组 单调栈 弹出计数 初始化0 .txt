### 解题思路
此处撰写解题思路

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def nextLargerNodes(self, head: ListNode) -> List[int]:
        nums = []
        stack = []
        total=0
        while head != None:
            nums.append(head.val)
            head= head.next
            total+=1
        ans = [0]* total
        for i in range(total):
            while stack and nums[stack[-1]]<nums[i]:
                ans[stack.pop()] = nums[i]
            stack.append(i)
        return ans
```
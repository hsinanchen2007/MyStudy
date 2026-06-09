正向扫描：
```
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def nextLargerNodes(self, head: ListNode) -> List[int]:
        if head == None:
            return None
        nums = []
        while head:
            nums.append(head.val)
            head=head.next
        stack = []
        res = [0]*len(nums)
        for i in range(len(nums)):
            while stack and nums[stack[-1]]<nums[i]:
                tmp = stack.pop()
                res[tmp] = nums[i]
            stack.append(i)
        return res
```
反向扫描：
```
class Solution:
    def nextLargerNodes(self, head: ListNode) -> List[int]:
        if head == None:
            return None
        nums = []
        while head:
            nums.append(head.val)
            head=head.next
        stack = []
        res = [0]*len(nums)
        for i in range((len(nums)-1),-1,-1):
            while stack and nums[stack[-1]]<=nums[i]:
                stack.pop()
            if stack:
                res[i] = nums[stack[-1]]
            stack.append(i)
        return res
```

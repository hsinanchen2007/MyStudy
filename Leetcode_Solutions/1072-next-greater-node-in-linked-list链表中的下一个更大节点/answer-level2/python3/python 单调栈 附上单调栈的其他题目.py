## 单调栈题目

- 42
- 84
- 907
- 1019
- 768
- 402

## 代码

记录位置的数据结构是必须的

可以

- 多加个栈
- 多加个记录位置的数组
- 用栈中放的是pair(其实等效于2个栈)

链表转数组
```python
class Solution:
    def nextLargerNodes(self, head: ListNode) -> List[int]:        
        nums = []
        node = head
        while node != None :
            nums.append(node.val)
            node = node.next

        stack = []
        stack_loc = []
        res = [0] * len(nums)

        for i in range(len(nums)):
            while stack and stack[-1] < nums[i]:
                res[stack_loc[-1]] = nums[i]
                stack.pop()
                stack_loc.pop()
            stack.append(nums[i])
            stack_loc.append(i)

        return res  
```

直接操作链表
```python
class Solution:
    def nextLargerNodes(self, head: ListNode) -> List[int]:        
        stack = []
        stack_loc = []
        loc = -1
        res = []
        while head:
            loc += 1
            res.append(0)
            while stack and stack[-1] < head.val:
                res[stack_loc[-1]] = head.val
                stack.pop()
                stack_loc.pop()
            stack.append(head.val)
            stack_loc.append(loc)
            
            head = head.next

        return res  
```


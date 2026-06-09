### 解题思路
用辅助栈：（初始化辅助栈为全为-1，长度为nums的长度，方便处理最大值）
1.当stack为空时，将当前遍历元素和index添加到stack中（处理初始元素），不对res做操作
2.当遍历元素小于栈顶元素时，当前元素对应的index 在res中改变为栈顶元素的值
3.当遍历元素**大于或等于**栈顶元素时，pop掉栈顶元素再判断，一直到栈顶元素大于
遍历元素，这时再将栈顶元素的值，赋值到遍历元素对应的res中的位置。（如果栈为空的时候，表示当前元素为遍历过后的最大元素，将遍历元素储存到stack中，并不对res做操作）

这个遍历过程需要从后往前循环列表两次，对于nums中最大值的位置，对应到res中为-1，因为在弹出stack直到空后并没有对res进行操作。（有多个最大值也可以处理）

### 代码

```python3
class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        n = len(nums)
        # 初始化res最大值自动为-1，不需要操作, 因为当stack弹到空时，不会改变res的值，
        # 只是加入当前最大元素到栈中
        res = [-1]*n
        stack = []
        for i in range(2*n-1, -1, -1):
            # 从末尾到头遍历遍历两遍 5,4,3,2,1,0,5,4,3,2,1,0
            i = i % n
            if not stack:
                # stack为空的时候,用来处理遍历的第一个元素
                stack.append([nums[i], i])
            elif nums[i] < stack[-1][0]:
                res[i] = stack[-1][0]
                stack.append([nums[i], i])
            else: 
                while stack and nums[i] >= stack[-1][0]:
                    stack.pop()
                
                if not stack:
                    stack.append([nums[i], i])
                else:
                    res[i] = stack[-1][0]
                    stack.append([nums[i], i])
        return res
            
```
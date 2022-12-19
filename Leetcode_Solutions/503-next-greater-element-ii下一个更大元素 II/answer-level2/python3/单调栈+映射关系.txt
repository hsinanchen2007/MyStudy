### 单调栈+映射关系
从下一个更大元素Ⅰ过来的应该懂，想要再次使用映射关系解题只要明白该题中保持唯一的是下标就可以了，任何数组只要循环一次就能得出答案，因此使用nums + nums,偷懒了~~

### 代码

```python3
class Solution:
    def nextGreaterElements(self, nums):
        stack = []
        tmp = {}
        cur = nums + nums
        for i in range(len(cur)):
            while stack and cur[i] > cur[stack[-1]]:
                tmp[stack.pop()] = cur[i]
            stack.append(i)
        return [tmp.get(i, -1) for i in range(len(nums))]

        
```
### 解题思路
思路是单调栈，从尾到头维护一个递增栈，栈顶保存的是最大的元素，_MIN保存的是第二大的元素
如果新的数组小于第二大的元素，那么就返回True，此时一定满足条件 ai<ak<aj
### 代码

```python3
class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        stack=[]
        _Min=float("-inf")
        for i in range(len(nums)-1,-1,-1):
            if nums[i]<_Min:
                return True
            while stack and nums[i]>stack[-1]:
                _Min=stack.pop()
            stack.append(nums[i])
        return False



```
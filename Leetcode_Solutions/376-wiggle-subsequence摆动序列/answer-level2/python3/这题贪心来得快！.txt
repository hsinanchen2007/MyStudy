贪心算法，线性时间：要判断当前是上坡还是下坡，维护一个状态变量d即可。
d = 2 初始化
d = 1 表示上升
d = 0 表示下降
注意：利用一个栈，使得栈顶存储上坡或下坡的末端。

```python []
class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:       
        n = len(nums)
        if n < 2: return n
        res, d = [nums[0]], 2
        
        for i in range(1, n):
            if nums[i] > nums[i-1]:                             
                if d == 1: res.pop()
                res.append(nums[i])
                d = 1                    
            elif nums[i] < nums[i-1]:
                if d == 0: res.pop()
                res.append(nums[i])
                d = 0  
        return len(res)
```

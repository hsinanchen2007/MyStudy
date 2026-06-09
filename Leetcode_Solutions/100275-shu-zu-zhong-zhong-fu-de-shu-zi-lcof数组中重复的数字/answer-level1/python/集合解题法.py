### 解题思路
设置一个空集合，遍历挨个往集合里放，放之前先检测如果集合里面这个数已经存在了，返回这个值

### 代码

```python3
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        sets = set()     #设置空集合
        for i in nums:   #循环取值
            if i in sets:#判断值是否存在于集合中    
                return i #存在返回这个值
            else:
                sets.add(i) #不存在添加到集合
```
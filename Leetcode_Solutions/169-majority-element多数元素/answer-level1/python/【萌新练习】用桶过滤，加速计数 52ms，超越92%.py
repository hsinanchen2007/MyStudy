### 解题思路
# 萌新，欢迎大家指点

# 主要思想：count方法记录每个元素出现次数
# 加速思想：用桶过滤已经计数的元素

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        res=[] # 创建桶
        for i in nums:
            if i not in res: # 过滤元素
                result=nums.count(i) # 计数
                res.append(i)
                if result>len(nums)/2:
                    return i
            elif i in res:
                continue
```
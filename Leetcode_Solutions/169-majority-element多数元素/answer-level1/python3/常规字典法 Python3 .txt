### 解题思路
此处撰写解题思路
常规的字典法，基本思路是遍历一遍，记录数字出现的次数
最后选出多数元素
### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        l = len(nums)
        a = {}
        for i in nums:
            if i not in a.keys():#如果没有这个数字的键 则创建 并设键值为1
                a[i] = 1
            else:
                a[i] += 1 
        for j in a:
            if a[j] > math.floor(l/2):
                return j
```
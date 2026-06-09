### 解题思路
创建一个字典，记录每个数字出现的次数，每次记录后判断，次数大于1则返回该数字。

### 代码

```python3
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        dic = {}
        for num in nums:
            dic[num] = dic.get(num,0) + 1
            if dic[num] > 1:
                return num
```
### 解题思路
将每个数字转化而为字符串，然后统计长度为偶数的字符串。
### 代码

```python3
class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        count = 0
        i = 0
        while i <len(nums):
            if len(str(nums[i])) % 2==0:
                count +=1
            i +=1
        return count
```
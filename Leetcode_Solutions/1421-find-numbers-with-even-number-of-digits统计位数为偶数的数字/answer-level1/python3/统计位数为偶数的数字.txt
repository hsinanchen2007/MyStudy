### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findNumbers(self, nums: List[int]) -> int:

        # 方法1：耗时68ms，耗内存13.7MB
        return sum(1 for num in nums if len(str(num)) % 2 == 0)

        # 方法2：耗时104ms，耗内存13.6MB
        # count = 0
        # for num in nums:
        #     if len(str(num)) % 2 == 0:
        #         count += 1
        
        # return count
```
### 解题思路
一次遍历。初始化一个最大计数变量maxCount，一个计数变量count。
当num==1的时候：
    count+1
    更新maxCount
否则：
    count = 0
最后返回maxCount即可

### 代码

```python3
class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        maxCount, count = 0, 0
        for num in nums:
            if num == 1:
                count += 1
                maxCount = max(count, maxCount)
            else:
                count = 0
        return maxCount
```
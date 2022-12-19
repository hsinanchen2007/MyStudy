### 解题思路
有点慢，有没有什么优化思路
执行用时 :
72 ms
内存消耗 :
13.3 MB
### 代码

```python3
class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        results = []
        for n in range(len(nums) // 2):
            results += [nums[2*n + 1]]*nums[2*n]
        
        return results
```
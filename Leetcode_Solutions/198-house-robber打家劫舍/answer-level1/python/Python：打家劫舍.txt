### 解题思路
第一次见就是上色问题的解题思路，现在是名字变了，思路一样。
动态规划：
1、不包含上一个元素，包含当前元素
2、不包含当前元素，即上一次规划的最优解
Python写法，优势在于ab交换时比较简单

### 代码

```python3
class Solution:
    def rob(self, nums: List[int]) -> int:
        last,now=0,0
        for num in nums:
            last,now=now,max(last+num,now)
        return now
```
### 解题思路
用hashmap两次遍历,但最好的是一次遍历:

从第一个数开始count=1，遇到相同的就加1，遇到不同的就减1，减到0就重新换个数开始计数，总能找到最多的那个

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        l = len(nums)//2
        from collections import Counter
        c = Counter(nums)
        for k,v in c.items():
            if v>l:
                return k
```
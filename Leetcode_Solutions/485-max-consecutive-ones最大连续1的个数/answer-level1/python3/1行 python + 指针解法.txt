```python
class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        return len(max(''.join(map(str, nums)).split('0')))
```
- 参考评论区一楼思路，转字符串后分割取最大子串长度
```python
class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        r = c = 0
        for n in nums:
            if n:
                c += 1
            else:
                r = max(r, c)
                c = 0
        return max(r, c)
```
- 用指针更快一些
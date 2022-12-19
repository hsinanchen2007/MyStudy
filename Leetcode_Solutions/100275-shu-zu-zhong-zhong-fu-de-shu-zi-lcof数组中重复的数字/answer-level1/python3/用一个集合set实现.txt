### 解题思路
1、如果数字已经出现在集合中了，直接返回数字
2、如果没有出现在集合中，就添加进去

### 代码

```python3
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        s = set()
        for num in nums:
            if num in s:
                return num
            s.add(num)
        return None
```
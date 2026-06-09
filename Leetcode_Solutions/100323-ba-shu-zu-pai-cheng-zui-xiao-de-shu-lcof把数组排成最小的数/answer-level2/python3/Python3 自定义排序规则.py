### 解题思路
使用自定义排序规则，具体思路可查看《剑指offer》书中所介绍的方法。


### 代码

```python3
class Solution:
    def minNumber(self, nums: List[int]) -> str:
        import functools
        return "".join(sorted([str(num) for num in nums], key=functools.cmp_to_key(lambda x, y: int(x+y)-int(y+x))))
```
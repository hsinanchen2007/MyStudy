先统计各个数字出现的次数装进字典d，然后d[i]/(i+1)向上取整再乘以(i+1)，这样就可以得出这个数字对应的兔子数量，遍历字典里面的所有条目并按此方法加总就是森林兔子的数量。

```python []
class Solution:
    def numRabbits(self, answers: List[int]) -> int:
        return sum(math.ceil(ct / (i + 1)) * (i + 1) for i, ct in collections.Counter(answers).items())
```

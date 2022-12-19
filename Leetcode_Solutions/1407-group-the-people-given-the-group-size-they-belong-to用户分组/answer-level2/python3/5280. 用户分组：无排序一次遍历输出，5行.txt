![image.png](https://pic.leetcode-cn.com/4441cd6af47bbf9323d1b734c1372f7c75ccdf97dd48d9ade3f5b93f5157e952-image.png)

就是直接把编号放进对应的组数字典列表里，当列表长度等于组数时，就用迭代器输出这段列表。

76ms，仅供参考。

```python []
class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        d = collections.defaultdict(list)
        for i, c in enumerate(groupSizes):
            d[c].append(i)
            if len(d[c]) == c:
                yield d.pop(c)
```
```python []
class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        ans, d = [], collections.defaultdict(list)
        for i, c in enumerate(groupSizes):
            d[c].append(i)
            if len(d[c]) == c:
                ans.append(d.pop(c))
        return ans
```

![image.png](https://pic.leetcode-cn.com/21db3c43b60e5f7bdd664851b3e4c0a2ed75c6d9c4181861c721ef8c8e22e75a-image.png)


奇偶分别排序，然后合并，然后元组化，然后装进集合，然后返回大小。

```python []
class Solution:
    def numSpecialEquivGroups(self, A: List[str]) -> int:
        return len({tuple(sorted(a[:: 2]) + sorted(a[1:: 2])) for a in A})
```

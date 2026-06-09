![image.png](https://pic.leetcode-cn.com/f5a7afbb1b64e242d5a266c0a5c48757a195061b9834c9aa9bdda6c9162907a2-image.png)

把二维数组重塑成一维数组，然后二分插入，然后再次打包成二维数组并设置条件输出，468ms仅供参考。

```python []
class Solution:
    def removeInterval(self, intervals: List[List[int]], toBeRemoved: List[int]) -> List[List[int]]:
        (l, r), a = toBeRemoved, [*itertools.chain(*intervals)]
        bisect.insort(a, l)
        bisect.insort(a, r)
        return [[i, j] for i, j in zip(a[:: 2], a[1:: 2]) if i != j and (j <= l or i >= r)]
```

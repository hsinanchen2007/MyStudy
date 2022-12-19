1、长度为n的数组有n*(n+1)//2个子数组；
2、如果一个数组里不包含大于R的数，那它的任何一个子数组最大值都不会超过R；
3、如果一个数组里不包含大于等于L的数，那它的任何一个子数组最大值都不会大于等于L。

这相当于，大于R的数把整个数组分成了若干段，每一段的任何一个子数组都可以满足条件————————但是要排除掉只包含小于L的数的数组。

最终算法，从左到右扫一遍，统计有多少个连续<=R（记为nr），有多少个连续<L（记为nl），最终数量+nr*(nr+1)//2，-nl*(nl+1)//2。

```python3
class Solution:
    def numSubarrayBoundedMax(self, A: List[int], L: int, R: int) -> int:
        nl, nr = 0, 0
        total = 0
        for val in A:
            if val < L:
                nl += 1
            else:
                total -= nl * (nl + 1) // 2
                nl = 0
            if val <= R:
                nr += 1
            else:
                total += nr * (nr + 1) // 2
                nr = 0
        total += nr * (nr + 1) // 2
        total -= nl * (nl + 1) // 2
        return total
```

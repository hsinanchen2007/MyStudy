### 解题思路
自右往左用bisect的方法给数组排序，每次bisect_left返回的索引就代表需要往后走的步数，反过来其实就是我们想知道的右边比它小的个数。

### 代码

```python3
class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        import bisect
        res = []
        order = []
        for num in nums[::-1]:
            index = bisect.bisect_left(order, num)
            order.insert(index, num)
            res.append(index)
        return res[::-1]
```
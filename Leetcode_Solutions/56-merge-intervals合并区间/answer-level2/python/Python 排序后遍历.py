思路是先对`intervals`排序
然后从里面取出第一个区间作为基准`tmp`
继续从里面提取区间, 记`[left, right]`
存在2种情况:

不能合并的情况: 如果 `left > tmp[1] or right < tmp[0]` 说明当前提取的区间的最小值超过了基准的最大值, 或者最大值小于基准的最小值, 此时我们把基准区间记录下来,让当前的这个区间作为基准

能合并的情况: 如果能合并的话, 就更新基准为合并后的区间即可

```python
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if not intervals:
            return []
        intervals.sort()
        res = []
        for idx, (left, right) in enumerate(intervals):
            if idx == 0:
                # 初始化一个基准的区间
                tmp = [left, right]
                continue
            if left > tmp[1] or right < tmp[0]:
                # 不能合并, 基准空间加入res, 更新新的基准
                res.append(tmp[:])
                tmp = [left, right]
            else:
                # 能合并的话进行合并
                tmp[0] = min(left, tmp[0])
                tmp[1] = max(right, tmp[1])
        res.append(tmp)
        return res
```
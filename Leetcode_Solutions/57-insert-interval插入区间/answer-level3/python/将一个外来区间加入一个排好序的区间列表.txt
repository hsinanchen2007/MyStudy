### 解题思路
给出俩个思路
#### 第一个思路
1. 将外来的区间列表用插入到区间列表中，再用56的方法进行合并
#### 第二个思路
1. 将比外来区间小的与它不重叠的区间归到左边
2. 将比外来区间答的与它不重叠的区间归到右边
3. 找出重叠部分的最小值和最大值组成新的区间加入到列表的中间

### 代码

```python
class Solution(object):
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[List[int]]
        :type newInterval: List[int]
        :rtype: List[List[int]]
        """
        l, r = [], []
        start = newInterval[0]
        end = newInterval[1]
        for it in intervals:
            if (it[1] < start): l.append(it)
            elif (it[0] > end): r.append(it)
            else:
                start = min(start, it[0])
                end = max(end, it[1])
        return l + [[start, end]] + r

```
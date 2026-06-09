**思路：**

暴力的方法可以直接统计或者使用摩尔投票法。但是对于查询次数最多为 `10000` 的情况会超时。

优化的方法有很多，比如分桶或者使用线段树。这里介绍一个可以通过测试，并且编程复杂度比较小的方法。把每个值的索引加入一个列表，然后用二分搜索查询 `left` 和 `right` 插入的位置，通过比较 `right - left `是否大于等于 `threshold`。由于要查询绝对众数，我们可以将数组中数字按照频率排序，然后进行遍历，这样就可以保证绝对众数被最先搜索到。


**代码：**
```python
class MajorityChecker:

    def __init__(self, arr: List[int]):
        self.d = collections.defaultdict(list)
        for index, value in enumerate(arr):
            self.d[value].append(index)
        self.freq = sorted([(len(locations), value) for value, locations in self.d.items()], reverse = True)

    def query(self, left: int, right: int, threshold: int) -> int:
        for f, v in self.freq:
            if f < threshold: break
            locations = self.d[v]
            low = bisect.bisect_left(locations, left)
            high = bisect.bisect_right(locations, right)
            if high - low >= threshold:
                return v
        return -1


# Your MajorityChecker object will be instantiated and called as such:
# obj = MajorityChecker(arr)
# param_1 = obj.query(left,right,threshold)
```
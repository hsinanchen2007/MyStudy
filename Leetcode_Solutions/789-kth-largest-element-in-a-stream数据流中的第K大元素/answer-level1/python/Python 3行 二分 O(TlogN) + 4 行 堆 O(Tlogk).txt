```python
class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.k, self.n = k, sorted(nums)

    def add(self, val: int) -> int:
        self.n.insert(bisect.bisect_left(self.n, val, 0, len(self.n)), val)
        return self.n[-self.k]


# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)
```
- 首先对数组排序
- 每次插入新值时使用二分查找搜索插入位置，保持插入后数组的升序性质，那么就可以直接取第 k 大的值
- 时间复杂度 O(TNlogN), 其中 T 代表插入次数
- 其实可以在每次插入之后丢弃小于第 k 大数据之后的所有数字，这样时间复杂度可以降为 O(TNlogk)
- 进阶可使用堆：
```python
class KthLargest:
    def __init__(self, k: int, nums):
        self.k, self.nums = k, heapq.nlargest(k, nums + [float('-inf')])
        heapq.heapify(self.nums)

    def add(self, val: int) -> int:
        heapq.heappushpop(self.nums,val)
        return self.nums[0]


# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)
```
- 题目中提到 len(nums) >= k-1，因此我们加入一个无穷小使得 len(nums) >= k，以便构造一个 k 尺寸的小根堆
- 堆中的数据意味着从第 k 大的数字到最大的数字
- 维护堆的时间复杂度为 O(Tlogk)
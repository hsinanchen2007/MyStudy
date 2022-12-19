```python
import collections
def findShortestSubArray(nums):
    # 获取次数最多的数
    counter = collections.Counter(nums)
    max_v = max(counter.values())
    ns = [k for k, v in counter.items() if v == max_v]
    # 返回间距最小的索引差值
    return min([len(nums) - nums[::-1].index(n) - nums.index(n) for n in ns])

print(findShortestSubArray([1,2,2,3,1]))
print(findShortestSubArray([1,2,2,3,1,4,2]))
```
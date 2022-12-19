## 分析：
- 很多人写法都是每次都排序一遍，其实没必要
- 这道题的数据规模不大，如果数据量变大的一遍遍排序肯定超时
- 因为每一次排序都需要`O(nlogn)`的时间复杂度
- 可是如果使用堆来存放数组，我们只有在建堆时需要`O(1/2nlogn)`,剩下的插入和取最大值都只要`O(logn)`的复杂度
- 时间一下子就下了很多
- python有一个自带的`heapq`能创建小顶堆，我把数据变成负数就间接实现了大顶堆。
- 如果是java不知道有没有这样的库，那么就要自己实现了
- 主要是建堆，加值，取值。

## 代码：

```python
from heapq import heapify, heappush, heappop

class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        for i in range(len(stones)):
            stones[i] = -stones[i];
        heapify(stones)
        while len(stones) > 0:
            y = -heappop(stones)
            if len(stones) == 0:
                return y
            x = -heappop(stones)
            if x != y:
                heappush(stones, x - y)
        return 0
```
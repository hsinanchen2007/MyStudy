思路：

1. 按efficiency进行降序排列，
2. 遍历排序后的speed和efficiency，在遍历过程中进行以下操作：
    (1)将speed放入最小堆中，
    (2)保持堆的大小为k，
    (3)记录堆中speed之和，
    (4)寻找最大团队表现值。

献上代码：

```python3
import heapq
class Solution:
    def maxPerformance(self, n: int, speed: List[int], efficiency: List[int], k: int) -> int:
        lst = sorted([(s, e) for s, e in zip(speed, efficiency)], key=lambda x: x[1], reverse=True)

        speed_total = 0
        ans = 0
        speed_heap = []
        for s, e in lst:
            heapq.heappush(speed_heap, s)
            if len(speed_heap) > k:
                speed_total -= heapq.heappop(speed_heap)
            speed_total += s
            ans = max(ans, e * speed_total)
        return ans % (10 ** 9 + 7)
```

变量说明：

speed_total：记录k个最大speed之和，
ans：记录最大团队表现值，
speed_heap：存放堆元素。
由于堆中只保留k个元素，每多一个元素需要放入堆，就会弹出一个最小的元素，所以遍历完之后堆中剩下的k个元素就是最大的k个speed。
由于遍历是按照efficiency从大到小进行的，所以堆中的speed始终满足其对应的efficiency大于当前的efficiency。

复杂度：

排序：nlogn，对lst遍历：n，每次遍历进行堆的push和pop：2logn
时间复杂度：O(nlogn) + O(2nlogn) = O(nlogn)
空间复杂度：O(n)。

AC图：

![截屏2020-03-1619.26.04.png](https://pic.leetcode-cn.com/1776e5298ac75dc048b74144cd87a637b6472a3191a73ecdeb4279d9492bc609-%E6%88%AA%E5%B1%8F2020-03-1619.26.04.png)

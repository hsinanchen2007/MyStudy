本题可以直接sort()，反而是最快的。当然，维护一个优先队列也是常见思路，这里不加赘述。
我扫了一眼题解区暂时没看到用计数排序的。
这道题因为给了数据范围，小于10000，所以我认为使用计数排序的思路是一个比较优质的选择。
时间复杂度O(n+max(arr)),空间复杂度O(max(arr))
```
from queue import PriorityQueue
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        count = [0 for i in range(10001)]
        MAX = 0
        for i in arr:
            count[i] += 1
            if i>MAX:
                MAX = i
        num = 0
        ans = []
        print(count[0:MAX+1])
        for i in range(MAX+1):
            if not count[i]:
                continue
            num += count[i]
            if num<=k:
                for j in range(count[i]):
                    ans.append(i)
            if num>k:
                for j in range(k-num+count[i]):
                    ans.append(i)
                break
        return ans
```
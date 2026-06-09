行为：
1. 将 speed 与 efficiency 成组并按 efficiency 降序排序（时间复杂度 O(nlogn)）
2. 初始化一个保存了速度的最小堆
3. 遍历一次成组后的元素 （时间复杂度 O(n））
    1. 计算出至当前元素为止的速度总和并将这个速度加入至速度堆中（时间复杂度 O(logn)）
    2. 如果速度堆中元素已溢出（>k），则取出堆中最小的元素并在速度和中将这个元素减去（时间复杂度 O(logn)）
    3. 计算总团队表现值并更新最大值

总时间复杂度 O(nlogn)

思路：维护着一个「从第一个元素到现在的成员中速度最快的前 k 人」集合，在遍历的过程中由于最初已经按照效率降序排序了，因此越往后成员的效率值越小，也即团队的效率值便是遍历到的元素的效率值。

这其中有一个小问题，如果第 3.2 步删减的元素恰巧是 3.1 加入的元素那么「就会出问题」。一个可行的做法是在 3.1 前进行判断如果当前堆已满且当前元素的速度小于等于堆中速度最小的元素的速度则跳过。不过，由于总团队效率的计算公式，当总速度相同时，如果团队中的人有着更低的效率那么团队的效率不可能更高，因此这个问题可以被忽略掉。

另外代码中将 3.1 和 3.2 步堆的操作变为为了「如果堆未满则加入元素」「如果堆已满则加入元素并弹出最小元素」，这是因为 heapq 中使用 heappushpop 的效率高于先 heappush 再 heappop

还有一个小问题是，「由于答案可能很大，请你返回结果对 10^9 + 7 取余后的结果」可能有误导性，不能在计算 result 时直接进行取余（这会导致 10^9 + 8 < 2 的错误情况），而只能在最终进行判断。根据给出的范围，result 值最多为 10^8 * 10^5 * 10^5 = 10^18，因此对于其他语言应当使用 64 位数字类型计算。

```Python
import heapq

class Solution:        
    def maxPerformance(self, n: int, speed: List[int], efficiency: List[int], k: int) -> int:
        member = sorted(zip(efficiency, speed), reverse=True)
        speed_heap = []
        speed_sum = 0
        result = 0
        for start in range(n):
            speed_sum += member[start][1]
            if len(speed_heap) < k: 
                heapq.heappush(speed_heap, member[start][1])
            else:
                speed_sum -= heapq.heappushpop(speed_heap, member[start][1])
            
            
            result = max(result, member[start][0] * speed_sum)
            

        return result % (10 ** 9 + 7)
```

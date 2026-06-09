题解升级版[here](https://leetcode-cn.com/problems/kth-largest-element-in-a-stream/solution/python3-cong-bu-zao-lun-zi-da-fa-by-nickyingo/)
if判断只有当小顶堆堆顶元素**小于**当前元素时才有必要替换（说明当前元素插入后根一定不在是第K大，可以大胆替换）。
@Alan的代码不判断，每次都先push一个再pop一个，当前到来元素不是前k大自然被淘汰掉。

```python
import heapq

class KthLargest:
    def __init__(self, k: int, nums):
        self.pool = heapq.nlargest(k, nums)[::-1] #hi，我是一丢丢。。。。
        self.k = k

    def add(self, val: int) -> int:
        if len(self.pool) < self.k:
            heapq.heappush(self.pool, val)
        elif val > self.pool[0]:
            heapq.heapreplace(self.pool, val)
        return self.pool[0] 
#Alan的代码
class KthLargest:
    def __init__(self, k: int, nums):
        self.pool = heapq.nlargest(k, nums)
        heapq.heapify(self.pool)
        self.k = k

    def add(self, val: int) -> int:
        if len(self.pool) < self.k:
            heapq.heappush(self.pool,val)
        else:
            heapq.heappushpop(self.pool,val)
        return self.pool[0]

```

# 一
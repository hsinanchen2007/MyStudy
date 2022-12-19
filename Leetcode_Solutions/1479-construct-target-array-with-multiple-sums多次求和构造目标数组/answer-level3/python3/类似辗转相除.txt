### 解题思路
类似于辗转相除，从target反过来进行看看能不能推到[1, 1, ...].

### 代码

```python3
class Solution:
    def isPossible(self, target: List[int]) -> bool:
        if len(target) == 1:
            if target[0] == 1:
                return True
            else:
                return False
        
        import heapq
        import math
        target = [-1*i for i in target]
        heapq.heapify(target)
        # print(target)
        while True:
            summ = -1*sum(target)
            # print(summ)
            max1 = -1*heapq.heappop(target)
            # print(max1)
            # break
            if max1 == 1:
                break
            # summ = -1*sum(target)
            max2 = -1*heapq.heappop(target)
            tmp_k = math.ceil((max1 - max2)/(summ - max1))
            if tmp_k == 0:
                return False
            # print(tmp_k)
            max1 = max1 - tmp_k*(summ - max1)
            if max1<1:
                # print(max1)
                return False
            heapq.heappush(target, -1*max1)
            heapq.heappush(target, -1*max2)
        return True



```
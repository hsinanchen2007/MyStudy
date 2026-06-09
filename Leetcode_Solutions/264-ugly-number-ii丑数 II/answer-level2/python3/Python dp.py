```
import heapq

class Solution:
    def nthUglyNumber(self, n: int) -> int:
        ugly_nums = [1]
        ptrs = [0, 0 ,0]
        factors = [2, 3, 5]

        while len(ugly_nums) < n:
            frontier = [ugly_nums[p] * f for p, f in zip(ptrs, factors)]
            cur_ugly = min(frontier)
            if ugly_nums[-1] != cur_ugly:
                ugly_nums.append(cur_ugly)
            
            for i, f in enumerate(frontier):
                if f == cur_ugly:
                    ptrs[i] += 1
        
        return ugly_nums[-1]

```

```
import heapq

class Solution(object):
    def getKth(self, lo, hi, k):
        """
        :type lo: int
        :type hi: int
        :type k: int
        :rtype: int
        """

        cache = {}
        def get_weight(val):
            if val in cache:
                return cache[val]
            i = 0
            if val != 1:
                if val % 2 == 0:
                    new_val = val / 2
                else:
                    new_val = 3 * val + 1
                i += get_weight(new_val) + 1
            cache[val] = i
            return i

        def wrapper_get_weight(val):
            return get_weight(val), val
        # return sorted(range(lo, hi+1), key=wrapper_get_weight)[k-1]
        return heapq.nsmallest(k, range(lo, hi+1), key=wrapper_get_weight)[-1]
```
利用tuple（其实list和string也是）默认按0 1 2的元素排序。cache记录避免重复计算

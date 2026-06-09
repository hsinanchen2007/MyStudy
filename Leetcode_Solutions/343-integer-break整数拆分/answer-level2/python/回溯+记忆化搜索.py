```python []
class Solution(object):
    def integerBreak(self, n):
        """
        :type n: int
        :rtype: int
        """
        d = dict()
        def search(n):
            if n <= 2:
                return 1
            if n in d:
                return d[n]
            cur_max = 1
            for i in range(2, n):
                r = max(i, search(i)) * max(search(n-i), n-i)
                if r > cur_max:
                    cur_max = r
            d[n] = cur_max
            return cur_max
            
        return search(n)
        
```

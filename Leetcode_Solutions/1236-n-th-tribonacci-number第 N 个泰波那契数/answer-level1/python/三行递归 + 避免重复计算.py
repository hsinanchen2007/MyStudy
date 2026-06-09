```
has_calced_dict = {0: 0, 1: 1, 2: 1}

class Solution(object):
    def tribonacci(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n not in has_calced_dict:
            has_calced_dict[n] = self.tribonacci(n - 3) + self.tribonacci(n - 2) + self.tribonacci(n - 1)
        return has_calced_dict[n]
```

12ms, 11.8MB
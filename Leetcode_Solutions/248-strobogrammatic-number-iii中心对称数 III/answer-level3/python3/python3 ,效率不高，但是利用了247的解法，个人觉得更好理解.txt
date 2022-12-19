```
class Solution:
    def strobogrammaticInRange(self, low: str, high: str) -> int:
        dict1 = {'0': '0', '1': '1', '6': '9', '8': '8', '9': '6'}
        n = len(high)
        low, high = int(low), int(high)
        res = set()
        if int(low) < 10:
            for k in [0, 1, 8]:
                if low <= k <= high:
                    res.add(k)

        def helper(n):
            nonlocal res
            if n == 0:
                return ['']
            if n == 1:
                return ['0', '1', '8']
            ans = []
            for i in helper(n - 2):
                for k, v in dict1.items():
                    tmp = v + i + k
                    ans.append(tmp)
                    if len(str(int(tmp))) == n and low <= int(tmp) <= high:
                        res.add(tmp)
            return ans

        helper(n)
        helper(n - 1)
        return len(res)
```

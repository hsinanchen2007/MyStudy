

```
from queue import Queue
class Solution:
    def strobogrammaticInRange(self, low: str, high: str) -> int:
        que = Queue()

        que.put('')
        que.put('0')
        que.put('1')
        que.put('8')

        n = max(len(high), len(low))
        if len(low) < n:
            low = '0'*(n-len(low)) + low
        if len(high) < n:
            high = '0'*(n-len(high)) + high

        if high < low:
            return 0

        ans = 0
        while not que.empty():
            cur = que.get()
            if len(cur) > n:
                continue

            ex_cur = '0'*(n-len(cur)) + cur

            if cur != '' and not (cur[0] == '0' and len(cur) > 1) and ex_cur >= low and ex_cur <= high:
                #print(cur, ex_cur)
                ans += 1

            elif ex_cur > high:
                continue

            que.put('0' + cur + '0')
            que.put('1' + cur + '1')
            que.put('6' + cur + '9')
            que.put('8' + cur + '8')
            que.put('9' + cur + '6')

        return ans
```

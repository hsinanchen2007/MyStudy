

### 代码

```python
class Solution(object):
    def distributeCandies(self, candies, num_people):
        n = int((2*candies)**0.5)
        if n * (n+1) > 2 * candies:n -= 1
        mod = int(candies - n * (n+1)/2)
        numcandies = [0]*num_people
        p = 0
        while True:
            for i in range(1,n+1):
                numcandies[p] += i
                p += 1
                if p == num_people:
                    p = 0
            if i == n:break
        numcandies[p] += mod
        return numcandies
```
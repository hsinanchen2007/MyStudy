### 解题思路

a1 = target/n - (n-1)/2 即  a1 = (target-n*(n-1)/2)/n
a1为正整数，则(target-n*(n-1)/2)%n=0
a1>=1 则(target-n*(n-1)/2)/n>=1
        得 n*(n+1)/2 <= target

### 代码

```python3
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        ans = []
        n = 2
        while n*(n+1)/2 <= target:
            temp = target - n * (n-1) /2
            if not temp % n:
                a1 = int(temp//n)
                ans.append([i for i in range(a1, a1+n)])
            n += 1
        ans.reverse()
        return ans
```
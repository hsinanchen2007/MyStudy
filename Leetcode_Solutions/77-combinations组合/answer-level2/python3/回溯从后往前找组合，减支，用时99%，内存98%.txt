```
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        r = []
        def backtrack(combination, n, k):
            if k == 0:
                r.append(combination[:])
                return
            for i in range(k, n+1):
                combination.append(i)
                backtrack(combination, i-1, k-1)
                combination.pop()
        backtrack([], n, k)
        return r       
```
n = 4, k = 2。产生组合43, 42, 41, 32, 31, 21。可以看出不需要1（k)开头的组合，所以在for循环里，从k遍历到n+1
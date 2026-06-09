都在说找中位数，又没给证明，这也叫题解；
这题不用想什么中位数：设 a <= x <= b，将 a 和 b 都变化成 x 为最终目的，则需要步数为 x-a+b-x = b-a，即两个数最后相等的话步数一定是他们的差，x 在 a 和 b 间任意取；
所以最后剩的其实就是中位数；
那么直接排序后首尾指针计算就好：

```
def minMoves2(self, a: List[int]) -> int:
        a.sort()
        i, j = 0, len(a)-1
        ans = 0
        while i<j:
            ans += a[j]-a[i]
            i += 1
            j -= 1     
        return ans
```

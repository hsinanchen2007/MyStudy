### 思路
1. 假设序列从t开始，长度为n，则对其求和得`n*t+n*(n-1)/2`，令其等于target，则求得t为`(2*target-n*(n-1))/(2*n)`，只要这个结果是整数，那么序列[t, t+n)就是答案之一。
2. 由于n越大，t越小，所以从大到小遍历n找出符合条件的t和n，把序列push进结果列表即可满足题目要求，接下来求n的范围。
3. 当t为1时，n最大，求和得`n*(n+1)/2`，令其小于等于target，得到n小于等于`(2*t-0.25)**0.5-0.5`；又由题意，n最小为2，所以得到了n的范围。
### 代码
```python
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        ans = []
        for n in range(int((2 * target + 0.25)**0.5 - 0.5), 1, -1):
            a = 2 * target - n * (n - 1)
            b = 2 * n
            if a % b == 0:
                t = a // b
                ans.append(list(range(t, t + n)))
        return ans
```
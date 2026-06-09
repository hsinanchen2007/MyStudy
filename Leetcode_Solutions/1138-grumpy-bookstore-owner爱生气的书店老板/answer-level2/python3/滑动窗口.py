这道题用一个大小为X的滑动窗口从数组customers的开始处往后移动，将窗口内的所有顾客以及窗口外所有的 grumpy[i]==0 的位置的顾客数相加，最后取所有结果中的最大值即可。  
```Python
class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], X: int) -> int:
        n = len(customers)
        cur = 0
        for i in range(n):
            if i < X or grumpy[i] == 0:
                cur += customers[i]
        i = X
        ans = cur
        while i < n:
            if grumpy[i] == 1:
                cur += customers[i]
            if grumpy[i - X] == 1:
                cur -= customers[i-X]
            ans = max(ans,cur)
            i += 1
        return ans
```
### 解题思路
滑窗法，话说这样生气不会累吗

### 代码

```python3
class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], X: int) -> int:
        if len(grumpy) <= X:
            return sum(customers)
        windows = customers[:X]
        res = 0
        start = 0
        for i in range(X):
            if grumpy[i] == 1:
                res += customers[i]
        num = res
        for i in range(X,len(customers)):
            if grumpy[i-X] == 1:
                num -= windows[0]
            windows.pop(0)
            windows.append(customers[i])
            if grumpy[i] == 1:
                num += windows[-1]
            if num > res:
                start = i - X + 1
                res = num
        for i in range(start,start+X):
            grumpy[i] = 0
        ans = 0
        for i in range(len(customers)):
            if grumpy[i] == 0:
                ans += customers[i]
        return ans
```
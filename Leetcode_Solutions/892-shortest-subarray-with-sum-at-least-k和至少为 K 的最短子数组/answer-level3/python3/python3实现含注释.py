```python3 []
class Solution:
    def shortestSubarray(self, A: List[int], K: int) -> int:
        n = len(A)
        s = [0] * (n+1)
        for i in range(n):  # 循环计算前j=i+1（j:1——n）项和，并以s[j]记录
            s[i+1] = s[i] + A[i]
        
        ans = n + 1
        de = collections.deque()  # 创建双端队列，用于保存可能的索引值y
        for y, sy in enumerate(s):
            while de and s[de[-1]] >= sy:  
                de.pop()  # 此时以s[y]作为被减数，即左端，所得结果一定优于弹出的元素
            while de and sy - s[de[0]] >= K:
                ans = min(ans, y - de.popleft())  # 如此循环，则可得到所有满足条件的解，然后在其中寻找最小的
            de.append(y)
        return -1 if ans == n+1 else ans  # n+1不可能
```


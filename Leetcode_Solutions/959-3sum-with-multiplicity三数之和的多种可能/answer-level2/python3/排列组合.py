### 解题思路
排列组合解法，参考过评论区中java的排列组合。
![image.png](https://pic.leetcode-cn.com/d3a26a98da33acc8062a40aed69bf8c6dbe97aa0a0623e5b34be35dbe1e06cef-image.png)


### 代码

```python3
class Solution:
    def threeSumMulti(self, A: List[int], target: int) -> int:
        s = 0
        d = {}
        for i in range(len(A)):
            if A[i] not in d:
                d[A[i]] = 1
            else:
                d[A[i]] += 1

        for i in range(0, target+1):
            if i not in d:
                continue
            for j in range(i, target+1):
                if j not in d:
                    continue
                k = target - i - j                
                if k >= j and k in d:
                    if i == j and j == k:
                        s += d[i] * (d[i] - 1) * (d[i] - 2) / 6
                    elif i == j and j != k:
                        s += d[i] * (d[i] - 1) / 2 * d[k]
                    elif i != j and j == k:
                        s += d[i] * d[j] * (d[j] - 1) / 2
                    else:
                        s += d[i] * d[j] * d[k]
        return int(s%(10**9 + 7))
```
### 解题思路
值得注意的是：
count = [a.count(c) for a in A]比原来的for+if慢了约500ms！！！

### 代码

```python3
class Solution:
    def commonChars(self, A: List[str]) -> List[str]:
        res = []
        for c in set(A[0]):

            # count = [0] * len(A)
            for i in range(len(A)):
                # for a in A[i]:
                #     if a == c: count[i] += 1
                count = [a.count(c) for a in A]
            for j in range(min(count)):
                res.append(c)

        return res
```
![image.png](https://pic.leetcode-cn.com/f8c7cf5802cc3324978ed0ec0ef5baf91fc277155bcf14c3911f7c09170ea3e1-image.png)

```python3
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        res = []
        for i in range(2, int((target * 2) ** 0.5) + 1):
            if i % 2 != 0 and target % i == 0:
                res.append([j for j in range(target // i - i // 2, target // i + i // 2 + 1)])
            if i % 2 == 0 and target % (i // 2) == 0 and target % i != 0:
                res.append([j for j in range(target // i - i // 2 + 1, target // i + i // 2 + 1)])
        return res[::-1]
```
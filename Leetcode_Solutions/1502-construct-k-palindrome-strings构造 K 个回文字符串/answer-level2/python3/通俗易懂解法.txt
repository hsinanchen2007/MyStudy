### 解题思路
回文串，因为回文串字符顺序可以打乱，只要统计单数的字符数量即可，

### 代码

```python3
class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        """
        思路：回文串，因为回文串字符顺序可以打乱，只要统计单数的字符数量即可，
        :param s:
        :param k:
        :return:
        """
        if not s:
            return False
        if len(s) == k:
            return True
        elif len(s) < k:
            return False
        counter = collections.Counter(s)
        res = 0
        for key, v in counter.items():
            if v % 2 == 1:
                res += 1
        return res <= k
```
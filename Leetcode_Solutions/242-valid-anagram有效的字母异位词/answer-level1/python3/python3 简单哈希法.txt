### 解题思路
遍历第一个词，记录字母频次。遍历第二个词，递减频次，恰好中和返回True，否则False

### 代码

```python3
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        count_rd = dict()
        for i in s:
            if count_rd.get(i):
                count_rd[i] = count_rd[i] + 1
            else:
                count_rd[i] = 1
        for i in t:
            if count_rd.get(i):
                count_rd[i] = count_rd[i] - 1
                if count_rd[i] < 0:
                    return False
            else:
                return False
        if sum(count_rd.values()) > 0:
            return False
        return True
```
### 解法一：遍历字符串

遍历字符串，寻找 S 中存在于 J 中的字母个数。

```python
class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        res = 0
        for j in J:
            for s in S:
                if j == s:
                    res += 1
        return res
```

pythonic 一点：

```python
class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        return len([x for x in S if x in J])
```

### 解法二：哈希表

记录 `S` 中每个字母出现的次数，再把 `J` 中存在的字母次数都相加。

```python
class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        s_count = dict()
        for s in S:
            s_count[s] = s_count.get(s, 0) + 1
        res = 0
        for j in J:
            res += s_count.get(j, 0)
        return res
```
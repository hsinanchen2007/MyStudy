### 解题思路
编写哈希映射函数解决同构问题

### 代码

```python3
class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:

        def hash_(s, r):
            temp, map_ = 0, {}
            for i in range(len(s)):
                if s[i] in map_:
                    r += str(map_[s[i]])
                else:
                    map_[s[i]] = temp
                    temp += 1
            return r

        r1, r2 = '', ''
        r1, r2 = hash_(s, r1), hash_(t, r2)
        if r1 == r2:
            return True
        else:
            return False

```
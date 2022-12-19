### 解题思路
若想省事，此方法用了Counter

1. 直接使用Counter统计每个元素出现次数；
2. 循环判断是否存在次数为1的value,存在则find到s的这个值的下标，否则返回-1

### 代码

```python3
class Solution:
    def firstUniqChar(self, s: str) -> int:

        import collections
        c =  collections.Counter(s)
        for i in c:
            if c[i] == 1:
                return s.find(i)
        return -1

```


### 解题思路
count遍历的i 遇到1就返回index. 如果没遇到返回-1
这个比用collections Counter慢多了. 用了 6984 毫秒

### 代码

```python3
class Solution:
    def firstUniqChar(self, s: str) -> int:
        for i in s:
            if s.count(i) == 1:
                return s.index(i)
        else:
            return -1
```
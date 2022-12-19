### 解题思路
遍历字符串s，通过 count 函数计数，记录位置信息 pos，
若 count == 1，返回 pos ，否则 pos+1。
若不存在，返回 -1

### 代码

```python3
class Solution:
    def firstUniqChar(self, s: str) -> int:
        pos = 0
        for i in s:
            count = s.count(i)
            if count == 1:
                return pos
            else:
                pos += 1
        return -1 
```
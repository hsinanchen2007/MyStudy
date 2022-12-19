### 解题思路
遍历 字符串s，利用 find函数 查找 字符i 是否在 t 中，
若存在，删除 t字符串 已查找字符i所在位置之前的全部字符。
若不存在，返回 False
若成功遍历完成，返回 True

### 代码

```python3
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        for i in s:
            p = t.find(i)
            if p == -1:
                return False
            else:
                t = t[p+1:]
        return True
```
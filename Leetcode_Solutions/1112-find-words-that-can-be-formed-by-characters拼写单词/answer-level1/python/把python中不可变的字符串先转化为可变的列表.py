### 解题思路
把python中不可变的字符串先转化为可变的列表，然后每次遍历到一个字母就从列表中移除，最后统计结果

### 代码

```python3
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        res=0
        for i in words:
            n=len(i)
            t=list(chars)
            for c in range(n):
                if i[c] not in t:
                    break
                else:
                    t.remove(i[c])
                if c==n-1:
                    res+=n
        return res
```
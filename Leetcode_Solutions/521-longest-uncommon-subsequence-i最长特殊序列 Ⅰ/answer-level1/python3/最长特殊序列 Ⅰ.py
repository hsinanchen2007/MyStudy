### 解题思路
想得特别复杂来着。。。。结果看题解只需要考虑字符串长度的关系。

### 代码

```python3
class Solution:
    def findLUSlength(self, a: str, b: str) -> int:
        if a == b:  # 如果a和b同，则没有最长特殊序列
            return -1
        return len(a) if len(a)>len(b) else len(b)   # a和b不同时，则更长的那个字符串肯定是不会被更短的那个字符串给覆盖的
        
        
        
```
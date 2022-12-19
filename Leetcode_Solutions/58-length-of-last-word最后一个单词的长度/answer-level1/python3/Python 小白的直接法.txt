### 解题思路
1用split方法拆分字符串
2用 try 试运行
3空列表的情况用except的方法
### 代码

```python3
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        b = s.split()
        try:
            return len(b[-1])
        except:
            return 0
```
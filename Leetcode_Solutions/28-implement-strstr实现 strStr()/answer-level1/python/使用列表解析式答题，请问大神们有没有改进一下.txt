### 解题思路
这里使用列表解析式得到一个值的列表，然后再用切片得到这个值，但是有没有办法可以直接用解析式得到一个值呢？

### 代码

```python3
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        ln = len(needle)
        out = [i  for i in range(len(haystack)-ln+1) if needle == haystack[i:i+ln]]
        if out != []:
            return out[0]
        else:
            return -1

```
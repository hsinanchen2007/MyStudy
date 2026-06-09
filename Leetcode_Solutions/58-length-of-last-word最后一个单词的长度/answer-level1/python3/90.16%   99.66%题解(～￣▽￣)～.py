### 解题思路
用字符串处理函数split除去所有空格，同时将被空格分隔的字符串转成列表，取列表最后一个元素的长度即为答案；
要注意的是需特判字符串只有空格的情况。

### 代码

```python3
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        if s.count(" ")==len(s):
            return 0
        else:
            return len(list(s.split())[-1])
```
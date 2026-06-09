### 解题思路
如果一个单词在其中一个句子中只出现一次，在另一个句子中却没有出现，那么这个单词就是不常见的。
等同于：
拼接字符串A+B，求拼接后的字符串中只出现过一次的单词。

### 代码

```python3
class Solution:
    def uncommonFromSentences(self, A: str, B: str) -> List[str]:
        c = A.split(' ') + B.split(' ')
        return [i for i in c if c.count(i) == 1]
```
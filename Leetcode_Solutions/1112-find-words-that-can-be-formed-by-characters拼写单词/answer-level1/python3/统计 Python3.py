#### 解题思路：

直接统计字母表 `chars` 中每个字母出现的次数，然后检查词汇表 `words` 中的每个单词，如果该单词中每个字母出现的次数都小于等于词汇表中对应字母出现的次数，就将该单词长度加入答案中。

#### 图解：

![图解](https://pic.leetcode-cn.com/545be33139677e5ef8de527255c93d11b21ffc77a020f22cabec2779f95e0415.gif)

#### 代码：

```python [-python]
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        ans = 0
        cnt = collections.Counter(chars)
        for w in words:
            c = collections.Counter(w)
            if all([c[i] <= cnt[i] for i in c]):
                ans += len(w)
        return ans
```

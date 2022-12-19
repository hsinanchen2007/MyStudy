### 思路

**字符串**

##### 解法一

```
用 collections，代码风格比较 pythonic。
```

##### Python3代码

```python
from typing import List

class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        # solution one
        import collections
        res = 0
        cnt = collections.Counter(chars)
        for word in words:
            c = collections.Counter(word)
            if all([c[i] <= cnt[i] for i in c]):
                res += len(word)
        return res
```

##### 解法二

```
判断 word 中各个字符个数是否 <= chars 中这些字符个数。
```

##### Python3代码

```python
from typing import List

class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        # solution two
        res = 0
        for word in words:
            n = len(word)
            cnt = 0
            for i in word:
                # word 中字符 i 个数 <= chars 中字符 i 个数
                if word.count(i) <= chars.count(i):
                    cnt += 1
                else:
                    break
            # word 可以由 chars 拼出
            if cnt == n:
                res += cnt
        return res
```

### 代码地址

[GitHub链接](https://github.com/Wonz5130/LeetCode-Solutions/blob/master/solutions/1160-Find-Words-That-Can-Be-Formed-by-Characters/1160.py)
### 解题思路
> 分别统计字符出现次数，判断单词所有字符都出现在字典中且出现次数小于等于字典中的则是合理的；
- 分别用Counter和defaultdict做了尝试， 后者效率略高一点；

### 代码

```python3
from collections import Counter, defaultdict


class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        '''
        执行用时 :128 ms, 在所有 Python3 提交中击败了80.71%的用户
        内存消耗 :13.9 MB, 在所有 Python3 提交中击败了5.04%的用户
        '''
        char_dict = defaultdict(int)
        for c in chars:
            char_dict[c] += 1

        def is_known(word):
            known = defaultdict(int)
            for c in word:
                if c not in char_dict:
                    return False
                known[c] += 1
                if known[c] > char_dict[c]:
                    return False
            return True

        ans = 0
        for word in words:
            if is_known(word):
                ans += len(word)
        return ans

    def countCharacters1(self, words: List[str], chars: str) -> int:
        """
        执行用时 :192 ms, 在所有 Python3 提交中击败了59.26%的用户
        内存消耗 :13.9 MB, 在所有 Python3 提交中击败了5.04%的用户
        """
        char_dict = Counter(chars)

        def is_known(word):
            known = Counter(word)
            for c in known:
                if c not in char_dict:
                    return False
                if known[c] > char_dict[c]:
                    return False
            return True

        ans = 0
        for word in words:
            if is_known(word):
                ans += len(word)
        return ans
```
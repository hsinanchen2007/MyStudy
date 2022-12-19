### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        self.dic = {}
        if not words or not chars:return 0
        for i in range(len(chars)):
                if chars[i] not in self.dic:self.dic[chars[i]] = 1
                else:self.dic[chars[i]] += 1
        def cal(s):
            ans = 0
            dc = {}
            for i in range(len(s)):
                if s[i] not in dc:dc[s[i]] = 1
                else:dc[s[i]] += 1
            for i in dc:
                if i not in self.dic or dc[i]>self.dic[i] :return 0
                ans += dc[i]
            return ans
        ans = 0
        for i in range(len(words)):
            ans += cal(words[i])
        return ans

```
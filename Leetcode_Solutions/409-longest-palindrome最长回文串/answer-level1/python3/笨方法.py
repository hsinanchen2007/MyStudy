### 解题思路
永远不要将题想的多复杂，笨方法完全可以解决。

回文串，一定是对称，那么我们可以，只要成对出现的字母，都可以加入。
将能组成一对的字母全部找到。lens = lens + value//2,这个是成对的数量，回文长度lens = 2 * lens

最后一种场景
abxab,如果我们的长度不到总长度，说明还有可用字符，随便一个就可以当作x。
总长度：lens = lens+1

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> int:
        letter_dict = dict()
        lens = 0
        for item in s:
            if item not in letter_dict.keys():
                letter_dict[item] = 1
            else:
                letter_dict[item] = letter_dict[item] + 1
        if len(letter_dict) == 1:
            return len(s)
        else:
            for value in letter_dict.values():
                    lens = lens + value//2
            lens = 2 * lens
            if lens < len(s):
                lens = lens + 1
        return lens
```
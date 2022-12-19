### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        chars_dic = {}
        for x in chars:
            if x not in chars_dic:
                chars_dic[x] = 1
            else:
                chars_dic[x] += 1
        res = 0 
        for word in words:
            have = {}
            for x in word:
                if x not in chars_dic:
                    break
                elif x not in have:
                    have[x] = 1
                else:
                    have[x] += 1
                    if have[x] > chars_dic[x]:
                        break
            else:
                res += len(word)
        return res
```
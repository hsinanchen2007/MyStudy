### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        ans=0
        for word in words:
            for i in word:
                if word.count(i)<=chars.count(i):
                    flag=1
                    continue
                else:
                    flag=0
                    break
            if flag==1:
                ans+=len(word)
        return ans

```
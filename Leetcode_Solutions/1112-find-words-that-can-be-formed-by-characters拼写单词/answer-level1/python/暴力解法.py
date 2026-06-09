### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:

        if not words or not chars:
            return ""
        nums=[]
        for word in words:
            used=[False]*len(chars)
            count = 0
            for i in range(len(word)):
                for j in range(len(chars)):
                    if word[i]==chars[j] and not used[j]:
                        count+=1
                        used[j]=True
                        if count==len(word):
                           nums.append(word)
                        break
        res=0
        for num in nums:
            res+=len(num)
        return res
```
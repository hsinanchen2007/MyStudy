### 解题思路
时间复杂度：o(m*n)
空间复杂度：o(n)
### 代码

```python
class Solution(object):
    def countCharacters(self, words, chars):
        """
        :type words: List[str]
        :type chars: str
        :rtype: int
        """
        count=0
        for word in words:
            flag=True
            char_list = list(chars)
            for char in word:
                if char in char_list:
                    char_list.remove(char)
                else:
                    flag=False
                    break
            if flag:
                count+=len(word)
        return count
                

                
```
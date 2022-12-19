### 解题思路
此处撰写解题思路
暴力匹配求解
### 代码

```python
class Solution(object):
    def countCharacters(self, words, chars):
        """
        :type words: List[str]
        :type chars: str
        :rtype: int
        """
        sum=0
        for c in words:
            char=list(chars)
            flag=0
            for d in c:
                for i in range(len(char)):
                    if d==char[i]:
                        flag=flag+1
                        char[i]='A'
                        break
            if len(c)==flag:
                sum=sum+flag
        return sum
```
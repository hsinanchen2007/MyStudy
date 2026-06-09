首先把s处理，然后判断是否相同
```python3
class Solution:
    def isPalindrome(self, s: str) -> bool:
        news=[s[i].lower() for i in range(0,len(s)) if s[i].isalnum()]
        return news==[news[len(news)-i-1] for i in range(0,len(news))]
```
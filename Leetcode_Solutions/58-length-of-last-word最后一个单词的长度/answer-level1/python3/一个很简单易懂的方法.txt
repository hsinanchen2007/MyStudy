
```python3
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        temp=s.split(" ")
        for i in range(len(temp)-1,-1,-1):
            if len(temp[i])!=0:
                return len(temp[i])
        
        return 0

```
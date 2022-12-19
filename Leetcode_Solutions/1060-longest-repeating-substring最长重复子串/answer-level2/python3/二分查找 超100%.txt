```python
class Solution:
    def longestRepeatingSubstring(self, S: str) -> int:
        
        def check(S,res):
            record = set([S[i:i+res] for i in range(len(S)-res+1)])
            return (len(record) != len(S)-res+1)
        
        left = 1
        right = len(S)-1
        while left <= right:
            #print(left,right)
            mid = (left+right+1)//2
            if check(S,right):
                return right
            else:
                if check(S,mid):
                    left = mid
                else:
                    right = mid-1
        return 0
```
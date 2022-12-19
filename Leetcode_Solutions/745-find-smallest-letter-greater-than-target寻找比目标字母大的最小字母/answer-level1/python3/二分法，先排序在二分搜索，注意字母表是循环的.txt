### 代码

```
class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        letter = sorted(letters)
        n = len(letter)
        left = 0
        right = n
        while left<right:
            mid = left + (right-left)//2
            if letter[mid]<=target:
                left=mid+1
            else:
                right = mid
        if left ==n:
            return letter[0]
        else:   
            return letter[left]            
```
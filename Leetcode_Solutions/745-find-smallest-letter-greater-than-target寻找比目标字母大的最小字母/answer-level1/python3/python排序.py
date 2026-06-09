```
class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        letters.append(target)
        letters.sort()
        if target == 'z' or target == max(letters):
            return letters[0]
        for x in letters:
            if x > target:
                return x
```

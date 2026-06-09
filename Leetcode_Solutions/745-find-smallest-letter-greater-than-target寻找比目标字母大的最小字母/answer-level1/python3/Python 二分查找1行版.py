直接全部负数坐标，或者取模也行。

```
class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        return letters[bisect.bisect(letters, target) - len(letters)]
```
```
class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        return letters[bisect.bisect(letters, target) % len(letters)]
```
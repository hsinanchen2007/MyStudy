```
class Solution(object):
    def game(self, guess, answer):
        """
        :type guess: List[int]
        :type answer: List[int]
        :rtype: int
        """
        return ([answer[i] - guess[i] for i in range(3)]).count(0)
```

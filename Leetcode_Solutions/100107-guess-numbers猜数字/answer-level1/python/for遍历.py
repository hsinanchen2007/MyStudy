### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def game(self, guess, answer):
        """
        :type guess: List[int]
        :type answer: List[int]
        :rtype: int
        """
        rightnum=0
        numguess=0
        for i in guess:
            if numguess < len(guess):
                if i == answer[numguess]:
                    rightnum+=1
                numguess+=1
        return rightnum
guess=[1,2,3]
answer=[1,2,3]
solution=Solution()
print(solution.game(guess,answer))

```
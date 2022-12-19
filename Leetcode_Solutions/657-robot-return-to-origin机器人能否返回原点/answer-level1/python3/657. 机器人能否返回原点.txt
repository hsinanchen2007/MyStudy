**Str/List.count('匹配值')**


python2
```
class Solution(object):
    def judgeCircle(self, moves):
        """
        :type moves: str
        :rtype: bool
        """
        RL, UD = 0, 0
        for i in moves:
            if i == 'R':
                RL += 1
            elif i == 'L':
                RL -= 1
            elif i == 'U':
                UD += 1
            elif i == 'D':
                UD -= 1

        return True if RL == 0 and UD == 0 else False
```

python2
```
class Solution(object):
    def judgeCircle(self, moves):
        """
        :type moves: str
        :rtype: bool
        """
        if moves.count('R') == moves.count('L'):
            if moves.count('U') == moves.count('D'):
                return True

        return False
        # return moves.count('R') == moves.count('L') and moves.count('U') == moves.count('D')
print Solution().judgeCircle('UD')
```

python3 这个最快
```
class Solution:
    def judgeCircle(self, moves: str) -> bool:
        return moves.count('R') == moves.count('L') and moves.count('U') == moves.count('D')
        
```

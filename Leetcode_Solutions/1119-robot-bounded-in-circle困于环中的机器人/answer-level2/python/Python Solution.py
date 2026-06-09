### 解题思路
Using complex numbers for directions
### 代码

```python
class Solution(object):
    def isRobotBounded(self, instructions):
        """
        :type instructions: str
        :rtype: bool
        """
        position,direction = 0,1
        for i in instructions:
            if i == 'G':
                position += direction
            elif i == 'L':
                direction *= 1j
            elif i == 'R':
                direction *= -1j
        return position == 0 or direction != 1
```
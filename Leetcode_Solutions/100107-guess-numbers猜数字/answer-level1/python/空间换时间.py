### 解题思路
只需要找到有几个元素相同，可以作差，只要找到差里面有几个零就可以了。

### 代码

```python
class Solution(object):
    def game(self, guess, answer):
        """
        :type guess: List[int]
        :type answer: List[int]
        :rtype: int
        """
        x=guess[0]-answer[0]
        y=guess[1]-answer[1]
        z=guess[2]-answer[2]
        if (x*y*z!=0):
            return 0
        elif (x*x+y*y+z*z==0):
            return 3
        elif (x!=0):
            if ((y!=0)or(z!=0)):
                return 1
            else:
                return 2
        elif((y==0)or(z==0)):
            return 2
        else:
            return 1
```
### 解题思路
Dictionary 
### 代码

```python
class Solution(object):
    def judgeCircle(self, moves):
        """
        :type moves: str
        :rtype: bool
        """
        dict={'R':(1,0),'L':(-1,0),'U':(0,1),'D':(0,-1)}
        x=y=0
        for i in moves:
            if i == 'R' or i =='L':
                x+=dict[i][0]
            else:
                y+=dict[i][1]
        return x==y==0
```
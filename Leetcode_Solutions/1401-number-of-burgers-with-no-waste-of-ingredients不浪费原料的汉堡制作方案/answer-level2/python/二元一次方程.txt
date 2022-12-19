### 解题思路
        #jumbo 4 tomato 1 chess
        #small 2 tomato 1 chess
        #有多少个chess,就要制作多少个
        #假设制作x jumbo, y small
        x+y=cheeese
        4x+2y=tomato
        2x=totato-2cheese

### 代码

```python
class Solution(object):
    def numOfBurgers(self, tomatoSlices, cheeseSlices):
        """
        :type tomatoSlices: int
        :type cheeseSlices: int
        :rtype: List[int]
        """
        #jumbo 4 tomato 1 chess
        #small 2 tomato 1 chess
        #有多少个chess,就要制作多少个
        #假设制作x jumbo, y small
        """
        x+y=cheeese
        4x+2y=tomato
        2x=totato-2cheese
        """
        if  ( tomatoSlices-2*cheeseSlices)%2:
            return []
        else:
            x=(tomatoSlices-2*cheeseSlices)/2
            y=cheeseSlices-x
            return [x,y] if x>=0 and y>=0 else []


```
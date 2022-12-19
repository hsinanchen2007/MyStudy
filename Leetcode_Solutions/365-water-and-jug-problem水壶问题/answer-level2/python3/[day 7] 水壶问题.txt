### 解题思路



官方解法

### 代码

数学法

```python
class Solution(object):
    # 求最大公约数
    def getMaxcommpisor(self,a,b):
        if a < b:
            a,b = b,a     
        while a%b != 0:
            a,b = b,a%b
        return b
    def canMeasureWater(self, x, y, z) :
        if x + y < z:
            return False
        if x == 0 or y == 0:
            return z == 0 or x + y == z
        return z % self.getMaxcommpisor(x, y) == 0


```


dfs


class Solution(object):
    def canMeasureWater(self, x, y, z) :
        # if  z == 0: # 不必要的代码
        #     return True
        # if x>z and y>z  : # 错误的想法
        #     return False

        stack = [(0,0)]
        self.results = set()
        while stack:
            cur_x,cur_y = stack.pop()
            # print(cur_x,cur_y)
            if cur_x == z or cur_y == z or ((cur_x + cur_y) ==z):
                return True

            if (cur_x,cur_y) in self.results:
                continue
            self.results.add((cur_x, cur_y))

            stack.append((x,cur_y))
            stack.append((cur_x,y))
            stack.append((0,cur_y))
            stack.append((cur_x,0))
            stack.append((cur_x - min(cur_x,y-cur_y),cur_y + min(cur_x,y-cur_y)))
            stack.append((cur_x + min(cur_y,x-cur_x),cur_y - min(cur_y,x-cur_x)))

        return False


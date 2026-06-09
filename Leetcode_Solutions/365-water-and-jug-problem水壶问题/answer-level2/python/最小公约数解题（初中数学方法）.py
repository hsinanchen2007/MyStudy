### 解题思路
水壶问题就是两个壶的最小公约数与想得到的水的升数是否成倍数问题（除去几个特殊情况，特殊情况在代码中有写到）
当z是最小公约数的整数倍时，可以利用两个壶经行迭代，得到最小公约数的倍数关系的容量

### 代码

```python3
class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        #这里我们排除需要得到0升水的情况和恰好有一个壶的容量跟目标一致的情况
        if z == 0 or z == x or z == y  :  
            return True 
        #判断是否超出最大量取容量，超过了就取不到了，应为只有两个壶
        if z > x + y :
            return False
        #这里用到了math库中的最小公约数方法gcd,如果z是最小公约的整数倍关系的时候，就可以取到
        return z % math.gcd(x,y) == 0
```
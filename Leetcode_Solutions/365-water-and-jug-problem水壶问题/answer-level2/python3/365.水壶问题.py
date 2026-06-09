### 解题思路
- 水壶容量分别为x,y;则倒水加水的过程可以看作 a*x + b*y = z;
- 其中a,b为整数，负值表示全部倒出，正值表示倒满；如x,y=3,5,z=4;则3*3-1*5=6
- x加满，全部到给y;
- x第二次加满，倒给y(x此时还剩1);
- y全部倒出;
- x将剩下的1到给y;
- x第三次加满，全部到给y,y==z==4;
- 问题变成a*x+b*y=z判断是否存在一组整数解（最大公约数整除z说明存在，最大公约数用辗转相除法求）

### 代码

```python3
class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        if z==0:return True
        if x==0:return y==z
        if y==0:return x==z
        if x+y<z:return False
        if x<y:
            x,y = y,x
        
        while x%y!=0:
            x,y = y,x%y
        
        return True if z%y==0 else False
```
### 解题思路

Kick the card. 
Math is fun. 
Again, I will give you the code. 

### 代码

```python3
class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        if z == 0:
            return True
        if z > x+y:
            return False
        return z%self.gcd(x,y)==0
        
    def gcd(self,a:int,b:int)->int:
        c=a%b
        if c==0:
            return b
        return self.gcd(b,c)
```
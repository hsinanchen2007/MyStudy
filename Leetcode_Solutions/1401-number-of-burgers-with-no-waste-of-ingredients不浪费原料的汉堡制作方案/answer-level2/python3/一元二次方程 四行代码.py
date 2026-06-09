### 解题思路
一元二次方程求解方法，主要代码四行
但是用时和内存消耗不是很好

### 代码

```python3
class Solution:
    def numOfBurgers(self, tomatoSlices: int, cheeseSlices: int) -> List[int]:
        a = (tomatoSlices - 2*cheeseSlices)/2
        b = (4*cheeseSlices - tomatoSlices)/2
        if a == int(a) and b == int(b) and a >= 0 and b >= 0:return [int(a),int(b)] 
        else:return []
```
### 解题思路
这里细致地分析了很久，似乎只需要考虑不断从 y 里面往 x 里倒水就能解决，而不用考虑 x 往 y 里倒水。
这里对 x+y > z > y, 我构造了 z1 = z-y, z2 = z-x。只需要找到一个就可以。

#### 官方题解上数学的想法很妙
ax+by = z 是否有解 等价于  z % gcd(x,y) = 0. 这个似乎在大一的高代课上讲过。不过是在多项式环上面讲的，涉及了首1最大公因式的特性。

另外，邵老师也讲过， ax+by = z 有解， 那么 (a-y)*x + (b+x)*y = z, 因此，若有解，必然存在解






### 代码

```python3
class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        if z == 0:
            return True
        if x > y:
            x, y = y, x
        if z ==x or z==y or z == x+y:
            return True
        if z > x + y:
            return False
        elif z > y:   ## 构造出 0< z-y <x, 0<z-x<y, 只要能达成一个就可以  
            z1 = z-y
            z2 = z-x
            hashset  = {x, y}
            t = y-x
            while True:
                while t>x:  #设  y = 7, x=2
                    if t in hashset:
                        return False
                    if t == z1 or t==z2:  ## z1 可以转换到 z2， 但z2 似乎也可以转换到 z1
                        return True
                    hashset.add(t)
                    t = t-x
                if t in hashset:
                    return False
                if t == z1 or t == z2:
                    return True
                hashset.add(t)
                t = y-(x-t)  ##这里是转折，但似乎有时候也存在 x 往 y 里面倒水，使得 y 满， x剩下一点
        else:
            if z > x:
                z = z-x  # 若 z<x, 不处理
            hashset = {x, y}
            t = y-x
            while True:
                while t>x:  #设  y = 7, x=2
                    if t in hashset:
                        return False
                    if t == z:
                        return True
                    hashset.add(t)
                    t = t-x
                if t in hashset:
                    return False
                if t == z:
                    return True
                hashset.add(t)
                t = y-(x-t)  ##这里是转折
```
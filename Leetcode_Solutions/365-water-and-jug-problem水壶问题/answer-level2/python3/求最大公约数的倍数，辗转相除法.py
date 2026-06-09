### 解题思路
容量大的是L，小的是l，那么肯定可以得到L、l和L-l三种
能得到L-l就可以得到L-(l - (L - l)) = 2(L-l)
继而可以得到3(L-l).。。。n(L-l)只要其不大于L
然后另一桶水可空可满。
综合考虑来讲，最后的体积和肯定是L和l的线性组合，aL+bl = z
a和b有0或正整数解的时候成立。
```
在数论中，裴蜀定理是一个关于最大公约数（或最大公约式）的定理。
说明了对任何整数a、b和它们的最大公约数d，关于未知数x和y的线性丢番图方程：
ax + by = m有解当且仅当m是d的倍数。裴蜀等式有解时必然有无穷多个整数解，每组解x、y都称为裴蜀数，可用辗转相除法求得。
```
所以就可以求L和l的最大公因数，然后看z能不能整除这个最大公因数。
其实我已经忘了初中学的辗转相除法了，还是搬出来百度
```
用较大数除以较小数，再用出现的余数（第一余数）去除除数，再用出现的余数（第二余数）去除第一余数，如此反复，直到最后余数是0为止。如果是求两个数的最大公约数，那么最后的除数就是这两个数的最大公约数。
```
### 代码

```python3
class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        if x + y < z:
            return False
        if x == 0 or y == 0:
            return z == 0 or x + y == z
        if x>y:
            return z % self.MaxGcd(x,y) == 0
        else:
            return z % self.MaxGcd(y,x) == 0
    

    def MaxGcd(self,big,small):
        if big%small == 0:
            return small
        remain = big % small
        if remain > small:
            return self.MaxGcd(remain,small)
        else:
            return self.MaxGcd(small,remain)
```
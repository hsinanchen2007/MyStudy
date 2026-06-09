### 解题思路
由于n是32位有符号整数，python使用暴力法会超时，可以考虑使用分治法：
1. 首先，先判断n的符号，若为舒服，则先让x = 1 / x，且n变为其相反数；
2. 根据 x ^ n = x ^ (n/2) * x^(n - n / 2)可以得到分治策略，这里直接使用递归，递归出口时n=0，但是为了避免重复计算，可以先计算temp = x^(n/2)，然后判断此时n的次数：
    - 若为偶数，则返回temp*temp；
    - 若为奇数，返回temp*temp*x；
3. 返回最终结果。
### 代码

```python3
class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n < 0:
            x = 1 / x
            n *= -1
        return self.devide(x,n)
    
    def devide(self,x:float,n:int) -> float:
        if n == 0:
            return 1
        temp = self.devide(x,n//2)
        if n % 2 == 0:
            return temp*temp
        else:
            return temp*temp*x;
    

```
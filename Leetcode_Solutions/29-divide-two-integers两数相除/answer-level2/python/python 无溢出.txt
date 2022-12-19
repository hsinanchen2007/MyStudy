### 解题思路
python3的整数存储是动态的，1是01，所以1<<31之后是个33位数，而0x80000000是最高位是0的33位数，这些都不能用来判断是否溢出。所以还是-2147483648直接些。
解法用的位移来求商，除数左移相当于乘2的幂，但是注意不要左移到大于被除数才停止，因为被除数如果是32位，除数左移可能溢出，可以用while tmp <= a >> 1 来判断，tmp就不会有溢出的风险。

### 代码

```python3
class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        flag = (dividend ^ divisor) >= 0
        if divisor == -2147483648:
            if dividend == -2147483648:
                return 1
            return 0
        b = abs(divisor)
        add = 0
        if dividend == -2147483648:
            if divisor == -1:
                return 2147483647
            dividend += b
            add = 1
        a = abs(dividend)
        j = self.div(a , b)
        if add == 1:
            j += 1
        if flag:
            return j
        return -j
    def div(self, a,b):
        j = 0
        while a >= b:
            i = 1
            tmp = b
            while tmp <= a >> 1 :
                tmp = tmp << 1
                i = i << 1
            j += i 
            a -= tmp
        return j
        


```
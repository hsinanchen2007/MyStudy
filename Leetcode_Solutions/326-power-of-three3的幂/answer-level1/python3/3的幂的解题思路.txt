### 解题思路
此处撰写解题思路
需要有数论的一点东西
3^n=3*3*3*3*3……
任何数除以3的余数只可能为0，1，2,而3的幂除以3最后只能为1，所以只需要一直除下去，最终余数为1就一定是3的幂
### 代码

```python3
class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        if n<1:
            return False
        while n%3==0:
            n=n/3
        return n==1                
```
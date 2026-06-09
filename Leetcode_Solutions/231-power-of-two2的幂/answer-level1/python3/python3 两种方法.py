### 解题思路
首先当然可以用n&(n-1)==0判断是不是只有一位是1
如果你不熟悉上面这个式子，直接转换为二进制当作字符串处理，把为1的位统计出来也可以

### 代码

```python3
class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        return n>0 and n&(n-1)==0
当作字符串处理
        if n<=0:
            return False
        return str(bin(n)).count("1")==1
            


       
        
```
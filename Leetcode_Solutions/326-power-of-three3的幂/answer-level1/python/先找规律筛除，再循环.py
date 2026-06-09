### 解题思路
方法比暴力循环稍微好一点，因为3的n次幂的尾数是1,3,9,7循环。所以尾数不是1,3,9,7的数可以直接返回False。下一步再通过循环判断整除情况。

### 代码

```python3
class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        m = ['1', '3', '9', '7']
        tmp = str(n)
        if tmp[-1] not in m:
            return False
        while n%3==0: 
            n=n/3
        if n==1:
            return True
        else:
            return False
```
### 解题思路
**《剑指offer》中的递归数字排列法**
按位数分解：
假如有4位，就分为：0000+1000+2000...+9000; 0000又分解为：000+100+200...+900,以此类推吧。
所以在进入递归的第一个数字就是0000，ind可以看作标志位，找到各位数后转换为int()就添加到列表中就行了。

### 代码

```python3
class Solution:
    def __init__(self):
        self.a = []
    def printNumbers(self, n: int) -> List[int]:
        if n == 0:
            return []
        nums = ["0"]*n
        for i in range(10):
            nums[0] = chr(ord("0")+i)
            self.re_number(nums, n, 0)
        return self.a[1:]
    
    def re_number(self, nums, n, ind):
        if n-1 == ind:
            self.a.append(int("".join(nums)))
            return 
        for i in range(10):
            nums[ind+1] = chr(ord("0")+i)
            self.re_number(nums, n, ind+1)
        
            
```
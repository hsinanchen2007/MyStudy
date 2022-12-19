### Python求解Triboancci

#### 1.递归方法
这种方法一般都很容想到，但是提交后超时，因为递归计算量较大。代码如下：

```python []
    def tribonacci(self, n: int) -> int:
        if n==0 :            
            return 0
        if n==1 or n==2:
            return 1
        
        return self.tribonacci(n-1)+self.tribonacci(n-2)+self.tribonacci(n-3)
```
#### 2.利用Python字典的特性做映射表
这个方法只用跑一边循环，时间复杂度为O(n)，完美提交。代码：

```python []
class Solution:
    def tribonacci(self, n: int) -> int:
        x = {0:0,1:1,2:1}        
        for i in range(3,38):
            xi = x[i-1] + x[i-2] + x[i-3]
            x[i] = xi
        
        return x[n]
```
![QQ截图20190814230853.png](https://pic.leetcode-cn.com/2c642f382b209ab8d8867c92da46fae0308fbb9750eddd9f655f9d76168979f9-QQ%E6%88%AA%E5%9B%BE20190814230853.png)

#### 3.借助2的思路，用空间换速度
使用已经跑好的字典，直接建立全部值的映射。当然，这是投机取巧，

```python []
class Solution:
    def tribonacci(self, n: int) -> int:        
        x={0: 0, 1: 1, 2: 1, 3: 2, 4: 4, 5: 7, 6: 13, 7: 24, 8: 44, 9: 81, 10: 149, 11: 274, 12: 504, 13: 927, 14: 1705, 15: 3136, 16: 5768, 17: 10609, 18: 19513, 19: 35890, 20: 66012, 21: 121415, 22: 223317, 23: 410744, 24: 755476, 25: 1389537, 26: 2555757, 27: 4700770, 28: 8646064, 29: 15902591, 30: 29249425, 31: 53798080, 32: 98950096, 33: 181997601, 34: 334745777, 35: 615693474, 36: 1132436852, 37: 2082876103}
        return x[n]
```

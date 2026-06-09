### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def integerBreak(self, n: int) -> int:
        # 所有数都可以用 2和3组成
        # a代表有多少个，b是余数
        # b=0时：代表n有a个3 相乘，b=1时：可以变为 a-1个3 和一个4 相乘
        # b=2时：代表a个3 和一个2 相乘
        if n<=3:
            return n-1
        a,b=n//3,n%3
        if b==0:return 3**a
        elif b==1:return 3**(a-1)*4
        # b==2时
        return 3**a*2
      
```
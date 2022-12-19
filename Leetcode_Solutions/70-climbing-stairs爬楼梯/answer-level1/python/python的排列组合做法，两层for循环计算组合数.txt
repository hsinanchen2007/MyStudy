### 解题思路
此问题可以看做排列组合问题。
假设普通人只坐一个座位，而胖子需要做两个座位，当存在n个座位时，最多有几种坐法。

### 代码

```python3
class Solution:
    def climbStairs(self, n: int) -> int:
        c = n // 2 #n个座位最多可以容纳n//2个胖子
        s = 0
        for i in range(c+1):#从没有胖子进入的情况开始看，直到进入c个胖子
            a,b = 1,1       #进入i个胖子，就只能坐n-i个人（算胖子）
            for j in range(i):#当进入i个胖子时，存在C(i/n-i),这个循环就是在计算C(i/n-i)
                a *= (n-i-j)
                b *= (j+1)
            s = s + a/b
        return int(s)
```
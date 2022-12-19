### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n == 0 :
            return 1
        if n == 1:
            return x
        if n < 0:
            n = -n
            x = 1/x
        if x == 1:
            return 1
        if x == -1:
            return 1 - 2*(n%2)
        num = x

        def cal_times(n):
            if n == 1:
                return num
            elif n==0 :
                return 1   
            
            x = num
            time = 1
            times = 0
            while time <= n:
                time *= 2
                times += 1
            time = time // 2
            times -= 1
            for i in range(times):
                x *= x
                if abs(x) < 0.00001:
                    return 0.00000
            shenyu = n % time
            return x * cal_times(shenyu)

        return cal_times(n)
```
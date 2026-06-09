### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/9040a2bfe5f7693beb8fab481bb831a7a712d7e5251d7a228f828ea70cc7d76b-image.png)


### 代码

```python3
class Solution:
    def fib(self, N: int) -> int:
        if(N==1 or N==0):return (N)
        a=0
        b=1
        for i in range(N):
            a,b=b,a+b
        return a
```
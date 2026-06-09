### 解题思路
递归调用

### 代码

```python3
class Solution:
    def fib(self, N: int) -> int:
        if N==0:
            return 0
        if N<3:
            return 1
        return self.fib(N-1)+self.fib(N-2)
```

![image.png](https://pic.leetcode-cn.com/0a2ca5b97ff23f59191cf586d6836596cef75bcf2d427574fd21ee46bc470556-image.png)

### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def fib(self, n: int) -> int:
        a,b=0,1
        if n==0:
            return 0
        elif n==1:
            return 1
        else:
            for i in range(2,n+1):
                a,b=b,int((a+b)%(1e9+7))
            return b
```
本题很简单，就是要取模要注意。

因为斐波那契数列求解用递归是O(2^n),所以这里每次算出下一个结果后就赋值给原来的两个变量将复杂度降到O(n)。
跟递归相比就是既保存了下一次要调用的两个数，又减少了空间的使用。
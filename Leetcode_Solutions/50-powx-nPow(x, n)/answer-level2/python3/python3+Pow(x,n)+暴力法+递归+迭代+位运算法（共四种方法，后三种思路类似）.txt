**可以参考，里面加了开n次方的求法：[求解n次幂，n次方（python3实现）](https://www.cnblogs.com/anzhengyu/p/11185603.html)**

__解法1：暴力法__

不是常规意义上的暴力，过程中通过动态调整底数的大小来加快求解。代码如下：

```python
class Solution:
    def myPow(self, x: float, n: int) -> float:
        judge = True
        if n<0:
            n = -n
            judge = False
        if n==0:
            return 1
        final = 1     # 记录当前的乘积值
        tmp = x       # 记录当前的因子
        count = 1     # 记录当前的因子是底数的多少倍
        while n>0:
            if n>=count:
                final *= tmp  
                tmp = tmp*x
                n -= count
                count +=1  
            else:
                tmp /= x
                count -= 1
        return final if judge else 1/final
```

__解法2：根据奇偶幂分类（递归法，迭代法，位运算法）__

1. 如果n为偶数，则pow(x,n) = pow(x^2, n/2)；

2. 如果n为奇数，则pow(x,n) = x*pow(x, n-1)。

递归代码实现如下：

```python
class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n<0:
            n = -n
            return 1/self.help_(x,n)
        return self.help_(x,n)

    def help_(self,x,n):
        if n==0:
            return 1
        if n%2 == 0:  #如果是偶数
            return self.help_(x*x, n//2)
        # 如果是奇数
        return self.help_(x*x,(n-1)//2)*x
```

迭代代码如下：

```python
class Solution:
    def myPow(self, x: float, n: int) -> float:      
        judge = True
        if n < 0:
            n = -n
            judge = False     
        final = 1
        while n>0:
            if n%2 == 0:
                x *=x
                n //= 2
            final *= x
            n -= 1
        return final if judge else 1/final
```

[python位运算符简介](https://www.runoob.com/python/python-operators.html#ysf5)

其实跟上面的方法类似，只是通过位运算符判断奇偶性并且进行除以2的操作（移位操作）。代码如下：

```python
class Solution:
    def myPow(self, x: float, n: int) -> float:      
        judge = True
        if n < 0:
            n = -n
            judge = False      
        final = 1
        while n>0:
            if n & 1:   #代表是奇数
                final *= x
            x *= x
            n >>= 1     # 右移一位
        return final if judge else 1/final 
```
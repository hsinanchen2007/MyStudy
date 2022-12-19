### 解题思路
#### 递归
使用递归方法可以轻松解决该问题:当N==0时,返回0,当N==1时,返回1;其他情况下按照斐波那契数列的计算公式即可
但是使用该方法完成计算提交后,发现执行时间很长,可能是python对递归的支持不是很好的原因
注释内的代码为递归代码

#### 循环
该问题也可使用循环求解,使用一个列表来储存斐波那契数列,并在其中预置0和1两个初始值,倘若N<2,则直接返回,倘若N>=2,那么我们依次计算每一个斐波那契数,并将其存入列表中,以便下一次计算.在计算完成后返回斐波那契数即可

### 代码

```python3
class Solution:
    def fib(self, N: int) -> int:
        '''
        if N==0:
            return 0
        elif N==1:
            return 1
        else:
            return self.fib(N-1)+self.fib(N-2)
        '''
        fib_list=[0,1]
        if N <2:
            return fib_list[N]
        for i in range(2,N+1):
            tmp=fib_list[i-1]+fib_list[i-2]
            fib_list.append(tmp)
        return fib_list[N]

```
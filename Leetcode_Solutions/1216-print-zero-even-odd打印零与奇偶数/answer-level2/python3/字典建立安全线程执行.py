初始化时候建立一个字典，三个线程分别把调用方法引用存入字典，新建一个函数函数中遍历调用传值；
个人觉得也可以使用队列，我再思考下；字典方法如下：

```python []
class ZeroEvenOdd:
    def __init__(self, n):
        self.n = n
        self.dict = {}
        
        
	# printNumber(x) outputs "x", where x is an integer.
    def zero(self, printNumber: 'Callable[[int], None]') -> None:
        self.dict[0] = printNumber
        self.res()
        
        
        
    def even(self, printNumber: 'Callable[[int], None]') -> None:
        self.dict[1] = printNumber
        self.res()
        
        
        
    def odd(self, printNumber: 'Callable[[int], None]') -> None:
        self.dict[2] = printNumber
        self.res()
        
    def res(self):
        if len(self.dict) == 3:
            for i in range(1,self.n+1):
                if (i%2)==0:
                    self.dict[0](0)
                    self.dict[1](i)
                else:
                    self.dict[0](0)
                    self.dict[2](i)
```
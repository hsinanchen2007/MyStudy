我看很多 Python 题解的方案都是使用循环打印，但是本题的出题目的是在某些编程语言上无法用整型的数来表示一个大的整数（虽然Python可以），但是，我们还是使用Python 列表来表示一个大的整数（不用字符串的原因是，在Python中，字符串一旦定义就无法修改了）



```
class Solution:
    def __init__(self):
        self.result = [] # 用来保存结果
        
    def printNumbers(self, n: int) -> List[int]:
        if n <= 0:
            return []
        number = ["0"]*n
        number[-1] = "1"
        for i in range(0, 10):
            number[0] = chr(ord("0")+i) # ord 是将一个字符转换成 ASCII 码，chr 是将一个 ASCII 码转换成一个数字
            self.Print1ToMaxOfDigitsRecursively(number, n, 0)
        return (self.result[1:])
    
    def Print1ToMaxOfDigitsRecursively(self, number, length, index):
        if index == length - 1:
            self.PrintNumberNormal(number)
            self.result.append(int("".join(number)))
            return 

        for i in range(10):
            number[index+1] = chr(ord("0")+i)
            self.Print1ToMaxOfDigitsRecursively(number, length, index+1)
    
    def PrintNumberNormal(self, number):
        number = int("".join(number))
        if number != 0:
            print(number)     

```


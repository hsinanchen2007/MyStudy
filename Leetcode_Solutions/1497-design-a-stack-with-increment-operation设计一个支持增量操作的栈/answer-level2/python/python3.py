### 解题思路
总体来说就是类的编写，没什么难度
思路：用列表来模拟栈
列表的pop方法默认删除最后一个元素并返回该元素

### 代码

```python3
class CustomStack:

    def __init__(self, maxSize: int):
        self.__l = []
        self.maxSize = maxSize


    def push(self, x: int) -> None:
        if len(self.__l) < self.maxSize:
            self.__l.append(x)


    def pop(self) -> int:
        return self.__l.pop() if self.__l else -1


    def increment(self, k: int, val: int) -> None:
        for i in range(len(self.__l)):
            if i < k:
                self.__l[i] += val
            else:
                break

            



# Your CustomStack object will be instantiated and called as such:
# obj = CustomStack(maxSize)
# obj.push(x)
# param_2 = obj.pop()
# obj.increment(k,val)
```
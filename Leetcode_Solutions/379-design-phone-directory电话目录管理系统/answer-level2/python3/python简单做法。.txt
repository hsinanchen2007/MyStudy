### 解题思路
此处撰写解题思路

### 代码

```python3
class PhoneDirectory:

    def __init__(self, maxNumbers: int):
        """
        Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory.
        """
        self.able_to_use = set()
        for i in range(maxNumbers):
            self.able_to_use.add(i)
        self.not_able_to_use = set()
        self.use = maxNumbers
        

    def get(self) -> int:
        """
        Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available.
        """
        if self.use == 0:
            return -1

        number = self.able_to_use.pop()
        self.not_able_to_use.add(number)
        self.use -= 1
        return number
        

    def check(self, number: int) -> bool:
        """
        Check if a number is available or not.
        """
        return number in self.able_to_use
        

    def release(self, number: int) -> None:
        """
        Recycle or release a number.
        """
        if number in self.not_able_to_use:
            self.not_able_to_use.remove(number)
            self.use += 1
            self.able_to_use.add(number)
        


# Your PhoneDirectory object will be instantiated and called as such:
# obj = PhoneDirectory(maxNumbers)
# param_1 = obj.get()
# param_2 = obj.check(number)
# obj.release(number)
```
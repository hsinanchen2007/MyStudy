```
class TwoSum:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.Queue = collections.deque()

    def add(self, number: int) -> None:
        """
        Add the number to an internal data structure..
        """
        self.Queue.append(number)


    def find(self, value: int) -> bool:
        """
        Find if there exists any pair of numbers which sum is equal to the value.
        """
        dic = {}
        for item in self.Queue:
            if item in dic:
                return True
            dic[value - item] = item
        return False
```

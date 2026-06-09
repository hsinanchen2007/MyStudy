常数时间摆明了就是哈希嘛，
python的set直接实现
```python
from random import choice
class RandomizedSet:
    def __init__(self):
        self.set = set()

    def insert(self, val: int) -> bool:
        if val in self.set:
            return False
        self.set.add(val)
        return True
        
    def remove(self, val: int) -> bool:
        if val not in self.set:
            return False
        self.set.remove(val)
        return True

    def getRandom(self) -> int:
        if not self.set:
            return None
        return random.choice(list(self.set))
```
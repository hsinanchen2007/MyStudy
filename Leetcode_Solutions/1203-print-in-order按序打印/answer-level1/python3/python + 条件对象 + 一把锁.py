执行用时 :
68 ms
, 在所有 Python3 提交中击败了
95.79%
的用户

内存消耗 :
15.6 MB
, 在所有 Python3 提交中击败了
100.00%
的用户

```
from threading import Lock, Condition
class Foo:
    def __init__(self):
        self.cv = Condition()
        self.num = 0

    def first(self, printFirst: 'Callable[[], None]') -> None:
        with self.cv:
            while self.num != 0:
                self.cv.wait()
            printFirst()
            self.num += 1
            self.cv.notify_all()

    def second(self, printSecond: 'Callable[[], None]') -> None:
        with self.cv:
            while self.num != 1:
                self.cv.wait()
            printSecond()
            self.num += 1
            self.cv.notify_all()

    def third(self, printThird: 'Callable[[], None]') -> None:
        with self.cv:
            while self.num != 2:
                self.cv.wait()
            printThird()
```

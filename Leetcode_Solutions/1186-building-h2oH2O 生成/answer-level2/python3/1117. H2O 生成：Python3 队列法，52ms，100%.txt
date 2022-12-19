试了py3的`threading`模块下的好几个阻塞方法都不行，甚至完全一样的逻辑结构函数方法名，java，c++都可以过，python也太惨了，数据稍微大一点就超时，最大长度大约也就能承受`15-18`这样，AC以后看柱状图，过的人确实有点少，估计大家都想着怎么用阻塞去做了。

最后索性直接用的队列，52ms，100%（出新时的记录）。

虚假的队列：
![image.png](https://pic.leetcode-cn.com/3f014cfd015f130c0bdf8603393c55f927b64e71913babbba38643935577a708-image.png)

```python []
class H2O:
    def __init__(self):
        self.h, self.o = [], []

    def hydrogen(self, releaseHydrogen: 'Callable[[], None]') -> None:
        self.h.append(releaseHydrogen)
        self.res()

    def oxygen(self, releaseOxygen: 'Callable[[], None]') -> None:
        self.o.append(releaseOxygen)
        self.res()
        
    def res(self):
        if len(self.h) > 1 and len(self.o) > 0:
            self.h.pop(0)()
            self.h.pop(0)()
            self.o.pop(0)()
```

真实的队列，28ms，100%
![image.png](https://pic.leetcode-cn.com/88a0be81e1eb647bf2936aa33331ab4a34093c8179cf02c01740402f05d5675d-image.png)

```python []
class H2O:
    def __init__(self):
        self.h = collections.deque()
        self.o = self.h.copy()

    def hydrogen(self, releaseHydrogen: 'Callable[[], None]') -> None:
        self.h.append(releaseHydrogen)
        self.res()

    def oxygen(self, releaseOxygen: 'Callable[[], None]') -> None:
        self.o.append(releaseOxygen)
        self.res()
        
    def res(self):
        if len(self.h) > 1 and len(self.o) > 0:
            self.h.popleft()()
            self.h.popleft()()
            self.o.popleft()()
```

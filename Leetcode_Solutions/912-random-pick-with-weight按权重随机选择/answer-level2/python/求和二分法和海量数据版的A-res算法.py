```python
    # 常规求和再二分查找的方法，应对pick调用次数较多但数据量不大的情况
    def __init__(self, w: list):
        self.w, self.sum = [0], 0
        for i in w:
            self.sum += i
            self.w.append(self.sum)
        self.sum -= 1

    def pickIndex(self) -> int:
        w = random.randint(0, self.sum)
        return bisect.bisect(self.w, w)-1
```

```python
    # 处理海量数据的A-res算法，应对pick调用次数较少但数据量特别大以及数据流的情况
    def __init__(self, w: list):
        self.w = w

    def pickIndex(self) -> int:
        _i, _v = 0,  float('-inf')
        for i, w in enumerate(self.w):
            v = random.random()**(1/w)
            if v > _v:
                _i, _v = i, v
        return _i
```


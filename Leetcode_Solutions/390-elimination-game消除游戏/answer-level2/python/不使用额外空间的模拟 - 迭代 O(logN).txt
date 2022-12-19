模拟整个过程, 注意只需要知道开始/结束/增量即可, 最终循环结束条件是s==e
不需要逐个删除, 只需要找到新的开始/结束
```python
class Solution:
    def lastRemaining(self, n: int) -> int:
        # 模拟整个过程, 注意只需要知道开始/结束/增量即可, 最终循环结束条件是s==e
        if n < 2:
            return n
        s, e, interval = 1, n, 2
        while s != e:
            end = s + (e - s) // interval * interval
            # 交换起始终点, interval翻倍且变符号
            # 注意新的终点一定是s+interval//2, 因为s已经被使用了
            # 新的起点可能是原来的e也可能是e-interval//2 (如果真正的end正好等于e)
            newE = s + interval // 2
            if end == e:
                newS = e - interval // 2
            else:
                newS = e
            interval = -interval * 2
            s, e = newS, newE
        return s
```


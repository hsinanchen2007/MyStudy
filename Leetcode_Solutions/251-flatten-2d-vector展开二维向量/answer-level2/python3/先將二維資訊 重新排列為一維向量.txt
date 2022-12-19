### 解题思路
先將二維資訊 重新排列為一維向量 過程中記錄元素總數
再一一取出的動作中 隨時記錄已經取出多少元素 

### 代码

```python3
class Vector2D:

    def __init__(self, v: List[List[int]]):
        self.vec = []
        self.total_c = 0
        self.it = -1
        for i in v:
            for j in i:
                self.vec.append(j)
                self.total_c += 1
    def next(self) -> int:
        self.it += 1        
        return self.vec[self.it]
    def hasNext(self) -> bool:
        if self.it + 1 < self.total_c:
            return True
        else:
            return False


# Your Vector2D object will be instantiated and called as such:
# obj = Vector2D(v)
# param_1 = obj.next()
# param_2 = obj.hasNext()
```
只有两个数组的拼接的情况下，按照下面的代码即可解决，注意在while循环之后的判定时，是用`i != size_1`以及`j != size_2`，不用再加1判断。


```python3

class ZigzagIterator:
    # 这道题的中文翻译是有问题的，这个“中间的元素”有歧义
    def __init__(self, v1: List[int], v2: List[int]):
        
        # 组成二维矩阵后，按照列的顺序进行访问
        
        self.combination = []
        self.index = 0
        size_1, size_2 = len(v1), len(v2)
        i, j = 0, 0
        while(i < size_1 and j < size_2):
            self.combination.append(v1[i])
            i += 1
            self.combination.append(v2[j])
            j += 1
        
        # 若第一个数组还有元素
        if i != size_1:
            self.combination += v1[i :]
        if j != size_2:
            self.combination += v2[j :]
        
        print(self.combination)

    def next(self) -> int: 
        res = self.combination[self.index]
        self.index += 1
        return res


    def hasNext(self) -> bool:
        return self.index < len(self.combination)
        
        

# Your ZigzagIterator object will be instantiated and called as such:
# i, v = ZigzagIterator(v1, v2), []
# while i.hasNext(): v.append(i.next())

```

END.
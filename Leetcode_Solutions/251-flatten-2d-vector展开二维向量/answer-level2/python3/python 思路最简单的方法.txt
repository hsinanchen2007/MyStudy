# 解题思路
将二维数组先转化成列表，再依次弹出，注意一开始的指针是指向第一个元素的左边
# 代码

```python []
class Vector2D(object):
    def __init__(self, v):
        self.list = []
        for nums in v:
            for num in nums:
                self.list.append(num)
        #print(self.list)
        self.index = 0
    
    def next(self):
        self.index += 1
        #print (self.index)
        return self.list[self.index-1]
    
    def hasNext(self):
        return self.index != (len(self.list) )
```


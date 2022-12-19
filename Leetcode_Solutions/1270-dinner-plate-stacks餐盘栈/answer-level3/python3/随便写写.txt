### 解题思路

这道题主要的功夫下在优化速度上：
1、使用2个列表，一个存储栈值，另一个**按位置值**存储空栈值位置；
2、push函数会先查看空栈值位置表是否为空，否则将**位置值最小**处替换为入参；
3、pop函数会检查出栈值是否为空，若为空，则同时将空栈值位置表中对应位置值（即最大值）删除，直至非空为止；
4、popAtStack则分为三种情况：
    （1）栈编号超过现有最大编号，直接返回-1；
    （2）选择了最后一个栈，直接调用pop；
    （3）选择了非最后一个栈，这时向前遍历该栈，返回首个非空值并赋空，存储该值位置并排序空栈值位置列表。

![image.png](https://pic.leetcode-cn.com/07020c41009eb7fa2192819a05ab7f6df5401c664f1e2a12223ae4566708bf6c-image.png)


### 代码

```python3
class DinnerPlates:

    def __init__(self, capacity: int):
        self.cpc = capacity
        self.stc = []
        self.hole = []

    def push(self, val: int) -> None:
        if self.hole:
            self.stc[self.hole.pop()] = val
        else:
            self.stc.append(val)

    def pop(self) -> int:
        try:
            while (pp := self.stc.pop()) is None:
                self.hole.pop(0)
            return pp
        except IndexError:
            return -1

    def popAtStack(self, index: int) -> int:
        l = len(self.stc)
        if index*self.cpc+1 > l:
            return -1
        elif (index+1)*self.cpc+1 > l:
            return self.pop()
        else:
            for n in range((index+1)*self.cpc-1,index*self.cpc-1,-1):
                if (self.stc[n]) != None:
                    pp = self.stc[n]
                    self.stc[n] = None
                    self.hole.append(n)
                    return pp
            self.hole.sort()
            return -1

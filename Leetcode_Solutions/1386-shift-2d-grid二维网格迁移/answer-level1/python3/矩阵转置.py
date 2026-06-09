```
class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        tmp = [list(i) for i in zip(*grid)]   #将数组行变成列
        for i in range(k):
            tmp.insert(0, tmp.pop())　　#删除最后一个元素，并插入到第一个位置
            tmp[0].insert(0, tmp[0].pop())  
        return [list(i) for i in zip(*tmp)]   #还原
```

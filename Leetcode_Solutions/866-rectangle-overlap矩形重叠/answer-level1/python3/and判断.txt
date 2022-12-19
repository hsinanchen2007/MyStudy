### 解题思路
画了半天，发现开始想多了。
其实很简单，分3步：
1. 给定矩形1
2. 新来矩形2
3. 如果 矩形2的右上角 在矩形1的左上角 的右上方，并且矩形2的左下角 在矩形2右上角 的左下方，则两个矩形相交！
### 代码

```python3
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        return (rec2[0] < rec1[2] 
                and rec2[1] < rec1[3]
                and rec2[2] > rec1[0]
                and rec2[3] > rec1[1])
```
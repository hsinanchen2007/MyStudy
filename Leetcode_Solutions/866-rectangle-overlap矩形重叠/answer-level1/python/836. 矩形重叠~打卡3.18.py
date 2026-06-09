### 解题思路
如果从重叠角度考虑的话，会有很多情况考虑不到，而且代码写起来逻辑性要强很多，
如果从不重叠角度考虑的话，只有下面的图中的四种情况，代码也会相对简洁很多
![image.png](https://pic.leetcode-cn.com/45dd2fbfaa35f1fc1555e804a1eb813c70e91bc7b124fa911db7c5ea64742bab-image.png)


### 代码

```python3
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        x1, y1, x2, y2 = rec1
        x1_, y1_, x2_, y2_ = rec2
        
        if x2 <= x1_:return False
        if x1 >= x2_:return False
        if y2 <= y1_:return False
        if y1 >= y2_: return False

        return True
        
```
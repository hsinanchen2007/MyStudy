### 解题思路
默认Rec1位于Rec2左边，对下列三种情况进行判断，符合其中之一即为无重叠。

![图片 1.png](https://pic.leetcode-cn.com/9c0a3822231b999b30034336740c0015675268a0f1a7cc7973f619145c42494a-%E5%9B%BE%E7%89%87%201.png)


### 代码

```python3
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        if rec1[0] > rec2[0]:rec1,rec2 = rec2,rec1
        if rec1[1] >= rec2[3] or rec1[2] <= rec2[0] or rec1[3] <= rec2[1]:return False
        return True
```
### 解题思路
这个题因为已经给出的就是排序好的数组，如果使用比较高级的数据结构，比如堆（C++和很多语言会有用堆维护的队列等数据结构），可以实现快速插入。但是一般情况下，尤其是直接使用没有堆维护的线性表的情况下，反复的插入和移动过操作反而会增加算法的复杂度，所以直接无视顺序合并数组之后排序即可，因为两个序列都是有序的，所以排序的复杂度也不会恶化到极端情况。

### 代码

```python3
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        for i in range(n):
            A[m+i]=B[i]
        A.sort()
```
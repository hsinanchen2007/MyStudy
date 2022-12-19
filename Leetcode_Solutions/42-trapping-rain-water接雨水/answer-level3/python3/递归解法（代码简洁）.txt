执行用时：44 ms
先找出最高的两列的索引：排序对象是height数组的索引，key是对应的height
`heapq.nlargest(2, range(len(height)), height.__getitem__)`
计算之间的雨水，左侧和右侧可以递归计算。
`return trap(height[:left+1]) + result + trap(height[right:])`
递归终止条件为`if len(height) <= 2: return 0`




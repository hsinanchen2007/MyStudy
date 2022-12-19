### 解题思路
动态规划，用堆获取上一行最小的两个dp值及对应坐标，选出列坐标不等于当前坐标的最小dp数值加上自身。
可以直接在原数组修改，节省额外dp状态存储空间。
时间复杂度$O({N}^{2})$，额外空间复杂度如果不用迭代器的话勉强算$O(N)$吧，毕竟特有的语言特性不计入复杂度计算咯。

### 代码
```python []
class Solution:
    def minFallingPathSum(self, arr: List[List[int]]) -> int:
        for i in range(1, len(arr)):
            (min0, idx), (min1, _) = heapq.nsmallest(2, ((num, j) for j, num in enumerate(arr[i - 1])))
            arr[i] = (num + (min0, min1)[j == idx] for j, num in enumerate(arr[i]))
        return min(arr[-1])
```

![image.png](https://pic.leetcode-cn.com/950b26dc61daf145fe6306d51f8b0d8951d439e1a962ac55ac9545c46f86c64b-image.png)

### 解题思路
方法2中利用“非递增”条件：从右边开始，看每一列有几行是负数的
图解作者：wan-dou-huang
![image.png](https://pic.leetcode-cn.com/3f3e04a0ec040b037cf5f63cc7dff161579be305d93d852dee4c26fd4442a842-image.png)


### 代码

```python3
class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        # 方法2:利用“非递增”  # 作者：wan-dou-huang
        count = 0
        i, j = 0, len(grid[0])-1   # 每一行从倒数开始

        while i < len(grid) and j >= 0:
            if grid[i][j] >= 0:
                i += 1
            else:
                count += len(grid) - i   # 统计每一列里有几行是负的
                j -= 1
        return count

        # 方法1:暴力法，不考虑题目中“非递增”条件
        # count = 0
        # for i in range(len(grid)):
        #     for j in range(len(grid[0])):
        #         if grid[i][j] < 0:
        #             count += 1
        
        # return count
```
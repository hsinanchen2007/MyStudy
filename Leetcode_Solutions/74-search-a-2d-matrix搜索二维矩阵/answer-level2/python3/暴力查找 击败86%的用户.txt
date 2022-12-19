### 解题思路
#### 暴力查找(有点类似二维链表的概念？):

由于是有序矩阵，直接将target和每行第一个数比较，确定目标所在行。
当target小与第i行第一个数时，目标位置就在第i-1行出现。

 **但需要考虑几种特殊情况：**
- matrix为空或为matrix=[[]],此时直接为False
- matrix只有一行，此时不存在i-1行
- 目标出现在最后一行，此时不存在大于target的第i行
- 目标出现在某行第一个数

**由于测试矩阵较小 执行时间尚可 时间复杂度为O(n)*

### 代码

```python3
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix or not matrix[0]:
            return False
        if matrix[0][0]>=target or len(matrix)==1:
            if target in matrix[0]:
                return True
            else:
                return False
        else: 
            for i in range(1,len(matrix)):
                if matrix[i][0]>target:
                    if target in matrix[i-1]:
                        return True
                        break
                    else :
                        return False
                        break
                elif matrix[i][0]==target:
                    return True
        if target in matrix[-1]:
            return True
        else:
            return False
            
      

            
                    
```
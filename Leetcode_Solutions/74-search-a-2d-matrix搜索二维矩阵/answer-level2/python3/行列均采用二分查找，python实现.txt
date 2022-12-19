![image.png](https://pic.leetcode-cn.com/7f56306d2eac305f3a873824eb85c909aeaf1aae1625972743ad49d74e595d48-image.png)

### 解题思路
1、对最后一列采用二分查找，确定目标值可能出现的那一行；
2、通过以上步骤找到的一行采用二分查找确定目标值存不存在。

### 代码

```python3
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix or not matrix[0]:
            return False
        def searchbin(lst):
            if len(lst)==1:
                return 0
            left=0
            right=len(lst)-1
            while left<right:
                mid=(left+right)//2
                if lst[mid]>=target:
                    right=mid
                else:
                    left=mid+1
            return left         #返回等于target或离target最近的大于target的值的id
            
        
        col_lst=[matrix[i][-1] for i in range(len(matrix))]
        col_idx=searchbin(col_lst)
        if matrix[col_idx][-1]==target:
            return True
        else:
            row_lst=matrix[col_idx]
            row_idx=searchbin(row_lst)
            if row_lst[row_idx]==target:
                return True
            else:
                return False

```
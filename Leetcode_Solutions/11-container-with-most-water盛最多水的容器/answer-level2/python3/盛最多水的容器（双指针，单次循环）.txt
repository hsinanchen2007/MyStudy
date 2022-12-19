### 解题思路
设置双指针left,right分别指数组的两端，根据规则将指针向中间移动，并更新面积最大值res，直到left==right时返回res。
算法步骤：
1. 设置指针left=0，right=len(height)-1，以及此刻的面积res = min(height[left],height[right]) * (right - left); 
2. 分别设置列表left_max与right_max存放面积最大时左边的横纵坐标与右边的横纵坐标；
3. 当左指针left < 右指针right 时，判断height[left]是否小于height[right]，若小于则left = left + 1，否则right = right - 1；
4. 左指针left或右指针right发生变化后，判断其对应的数组的值是否小于原来左指针left或者右指针right对应的值，若小于则转步骤3，否则转步骤5；
5. 计算更改后的左指针left或者右指针right的面积temp_val,若temp_val大于res，则更新面积最大值res以及left_max或者right_max, 否则面积最大值res不变；
6. 若左指针left < 右指针right 继续迭代，转步骤3，否则结束并返回面积最大值res。

### 代码

```python3
class Solution:
    def maxArea(self, height: List[int]) -> int:
        
        #方法二：双指针
        len_height = len(height)
        left = 0
        right = len_height - 1
        res = min(height[left],height[right]) * (right - left)
        left_max = [left, height[left]]
        right_max = [right, height[right]]

        while left < right:        
            if height[left] < height[right]:
                left += 1
                if height[left] < left_max[1]:
                    continue
                else:
                    temp_val = min(height[left],height[right]) * (right - left)
                    if temp_val > res:
                        res = temp_val
                        left_max = [left, height[left]]
            else:
                right -= 1
                if height[right] < right_max[1]:
                    continue
                else:
                    temp_val = min(height[left],height[right]) * (right - left)
                    if temp_val > res:
                        res = temp_val
                        right_max = [right, height[right]]
           
        return res
        
        
        
        
        
#         #方法一：冒泡算法的算法思路，超时了
#         len_height = len(height)
#         max_val = 0
#         for i in range(len_height-1):
#             for j in range(i+1, len_height):
#                 temp_val = min(height[i],height[j]) * (j-i)
#                 if max_val < temp_val:
#                     max_val = temp_val
        
#         return max_val
```
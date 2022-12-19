### 解题思路
采用双指针方法和动态规划思想，动态求解最大面积：
指向一头一尾，i = 0 ,j = len(height) - 1,当左边高于右边,j -= 1,当右边高于左边,i += 1。
当 i>=j，则跳出循环

### 代码

```python
class Solution:
    def maxArea(self, height: List[int]) -> int:
        # 双指针解
        i = 0
        j = len(height)-1
        max_area = 0
        for m in range(len(height)):
            if i >= j:
                break
            max_area = max(max_area,(j-i)*min(height[i],height[j]))
            if height[i] <= height[j]:
                i += 1
            else:
                j -= 1
        return max_area


            

    
            

```
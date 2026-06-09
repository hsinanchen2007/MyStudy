### 解题思路
**思路：**
     找到最高点，分别从两边往最高点遍历：若下一个数比当前数小，说明可接到水。
     根据最高点将数组分成左半部分和右半部分：
     1.左半部分以最高点为右边界，左边的部分储存的水分取决于左边柱子的最大高度；
     2.同理右半部分以最高点为左边界，能接雨水的值取决于当前位置与右边柱的差值。
**算法：**
     1.第一步：找到数组的最大值及对应下标。（一个for循环，从头到尾遍历，找到最高柱子。）
     2.第二步：将数组分为两个部分，左半部分处理。
        ————左半部分从0号位置开始算，以0号位置为左边柱开始遍历，left即为左边柱的位置，i表示以left为左边柱，依次往后排一直到最高位置为止。若当前位置小于左边柱，说明它可以储存水分，result=result+两者的高度差；若当前位置大于左边柱，则将当前位置作为左边柱继续往后遍历（left是一个个往后移，下一次的左边柱肯定以更高的那个为主）。
     3.第三步：右半部分处理。
        ————右半部分以最高柱子为左边柱，从右边柱（最后一个柱子）开始往前遍历，若右边柱大于前一个位置的柱子，表示可以储存水分，i会一直遍历到最高柱的位置，只要有高度差就进行相加的操作。

执行用时击败了99.54%的用户，速度很可！

![QQ图片20200306145412.png](https://pic.leetcode-cn.com/4e9a8b178e23533125cc2e4fe15cfa4707cabf74a309d12810932edf719fd187-QQ%E5%9B%BE%E7%89%8720200306145412.png)


### 代码

```python3
class Solution:
    def trap(self, height: List[int]) -> int:
        result = 0
        maxValue = -1
        maxAddr = 0
        # 取数组最大值及下标
        for i in range(0, len(height)):
            if height[i] >= maxValue:
                maxValue = height[i]
                maxAddr = i
        
        # 左半部分处理
        left = 0
        while left < maxAddr:
            for i in range(left+1, maxAddr+1):
                if height[i] < height[left]:
                    result = result + (height[left] - height[i])
                else:
                    left = i
            left += 1
        
        # 右半部分处理
        right = len(height) - 1
        while right > maxAddr:
            for i in range(right-1, maxAddr-1, -1):
                if height[i] < height[right]:
                    result = result + (height[right] - height[i])
                else:
                    right = i
            right -= 1
        return result
```
#### 理解题目

```
# 给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, 
# ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。 
# 
#  说明：你不能倾斜容器，且 n 的值至少为 2。 
# 
#  
# 
#  
# 
#  图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。 
# 
#  
# 
#  示例： 
# 
#  输入：[1,8,6,2,5,4,8,3,7]
# 输出：49 
#  Related Topics 数组 双指针


# leetcode submit region begin(Prohibit modification and deletion)
class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
# leetcode submit region end(Prohibit modification and deletion)

```
理解：取数组两个数，索引差作为宽，两个值中最小作为高，面积=宽*高 取最大
#### 解题思路
* 法1：枚举法
* 法2：头尾双指针法

#### 法1

```Python
class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        area_max = 0
        for i in range(len(height) - 1):
            for j in range(i, len(height)):
                area = (j - i) * min([height[i], height[j]])
                area_max = max([area_max, area])
        return area_max
```
#####  复杂度分析
* 时间复杂度：O(n^2),双层for循环，第一次遍历了n-1次，第二次遍历了n-i次，故为n^2
* 空间复杂度：O(1)

#### 法2

```Python
class Solution:
    def maxArea(self, height: List[int]) -> int:
        # 法2 左右边界同时向中间收敛
        area_max = 0
        i = 0
        j = len(height) - 1
        while i < j:
            # 计算最低高度,i j 收敛
            if height[i] < height[j]:
                min_height = height[i]
                i += 1
            else:
                min_height = height[j]
                j -= 1
            area = (j - i + 1) * min_height
            area_max = max([area_max, area])
        return area_max
```
#### 复杂度分析
* 时间复杂度：O(n)
* 空间复杂度:O(1)
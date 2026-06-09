### 解题思路
学习结果里面的时间最佳方法。

**本题关键思路**：双指针方法。思路同之前打卡写的相似。区别在实现上，省略了一个current_idx。
https://leetcode-cn.com/problems/trapping-rain-water/solution/bu-zhi-dao-neng-bu-neng-jian-chi-de-xiao-bai-mei-t/

### 代码

```python3
class Solution:
    def trap(self, height: List[int]) -> int:
        result = 0  # 最终返回的结果值
        left = 0
        right = len(height) - 1
        left_max = 0
        right_max = len(height) - 1

        while left < right:  # 控制边界
            # 左边比右边高时，就看右边指针指向的值是否小于右max
            # 如果是，那右指针指向的格子就能接雨水，接的值等于右max-格子
            # 这里之所以只用考虑右max，是因为在遍历的过程中，如果左高小于右高，就落入到下面的if里面，并只移动左指针，确保了遍历到的左max一定小于等于右max；而这里同理，已经确保了左max一定大于右max，只需要算右max减右高即可
            if height[left] > height[right]:  # 左边比右边高
                if height[right_max] < height[right]:
                    right_max = right
                    right -= 1
                else:
                    result += height[right_max] - height[right]
                    right -= 1
            if height[left] <= height[right]:  # 左边不高于右边
                if height[left_max] < height[left]:
                    left_max = left
                    left += 1
                else:
                    result += height[left_max] - height[left]
                    left += 1

        return result
```
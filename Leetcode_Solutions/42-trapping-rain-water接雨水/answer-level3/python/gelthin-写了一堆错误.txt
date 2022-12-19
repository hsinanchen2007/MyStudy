### 解题思路
思路不清晰，写了一堆错误，接连错误 10 次。

### 代码

```python3
class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        left_max, right_max = 0, 0
        left, right = 0, n-1
        ans = 0
        while left<=right:
            if left_max <= right_max:
                if left_max <= height[left]:
                    left_max = height[left]
                else:
                    ans += (left_max - height[left])
                left += 1
            else:
                if right_max <= height[right]:
                    right_max = height[right]
                else:
                    ans += (right_max - height[right])
                right -= 1
        return ans
```
``` python
# 解法完全错误, # BUG 选 right 的方式不对啊，[5,2,1,2,5] 选中了 2
class Solution: 
    def trap(self, height: List[int]) -> int:
        ## 这里就是细微处代码要写好
        # 每次维持两个当前最大值 (left_ind, right_ind)
        left = 0
        right = 0
        res = 0
        i = 0
        flag_left = False
        flag_right = False
        while i < len(height):
            if not flag_left:
                if height[i] >= height[left]:
                    left = i
                else:
                    flag_left = True  # left 暂时选定了
                i += 1
            elif not flag_right:
                if i+1 == len(height) or height[i] >= height[i+1]: 
                    right = i
                    flag_right = True
                    #flag_left and flag_right # BUG 放在外面会导致最后一次漏算
                    #tmp = min(height[left], height[right])*(right-left-1) - sum(height[left+1:right]) # BUG: 计算错误 （5,4,,1,2）
                    for i in range(left+1, right):
                        res += max(min(height[left], height[right])-height[i], 0)
                    #res += max(tmp, 0)
                    flag_left, flag_right = False, False
                    left = right

                i += 1
            
        return res
				
				
class Solution:  # 这个自己写的代码也不对，有 BUG.
    def trap(self, height: List[int]) -> int:
        # 官方题解最后一种解法，双指针
        if len(height) == 0:
            return 0
        left_max = height[0]
        right_max = height[-1]
        left, right = 1, len(height)-1
        ans = 0
        while left < right:
            if left_max <= height[left]:
                left_max = height[left]
                left += 1
            if right_max <= height[right]:
                right_max = height[right]
                right -= 1
            if left_max <= right_max: # 这时候 left 指针处的值可以确定
                ans += max(left_max-height[left], 0)
                left += 1
            else: # right_max >= left_max:
                ans += max(right_max-height[right], 0)
                right -= 1
        if left == right:  # 直接在上面写 left<= right 会有 BUG
            ans += max(min(left_max, right_max) - height[left], 0)
        return ans

```
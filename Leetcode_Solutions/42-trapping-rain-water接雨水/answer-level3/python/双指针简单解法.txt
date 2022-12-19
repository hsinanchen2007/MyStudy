### 解题思路
![TIM截图20200327173456.png](https://pic.leetcode-cn.com/869a76e21cd93a8e3e75dcddc97c185147e49b49a2788683bb98f0e9931ecbc8-TIM%E6%88%AA%E5%9B%BE20200327173456.png)

找到最长的那根柱子，利用双指针指向左右两边的柱子，双向遍历一遍。
**从左到右：**右指针递增，直到当前右指针的柱子比左指针的柱子长，计算区间内的雨水，然后左指针跳到右指针位置，右指针递增1，直到右指针到达最长的柱子。
**从右向左：**同理。
两次遍历分别找到了最长柱子左边和右边的雨水。

### 代码

```python3
class Solution:
    def trap(self, height: List[int]) -> int:
        if height== []: return 0
        left, right = 0, 1
        res = 0
        max_ = height.index(max(height))
        while right<= max_:
            if height[right]>=height[left]:
                res += (right-left-1)*min(height[left], height[right]) - sum(height[left+1:right])
                left = right
                right = right+1
            else: right += 1

        left, right = len(height)-2, len(height)-1
        while left>=max_:
            if height[right]<=height[left]:
                res += (right-left-1)*min(height[left], height[right]) - sum(height[left+1:right])
                right = left
                left = left-1
            else: left -= 1
        return res
        
```
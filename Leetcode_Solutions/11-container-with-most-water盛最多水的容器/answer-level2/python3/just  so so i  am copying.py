```
class Solution:
    def maxArea(self, height: List[int]) -> int:

        # 又题意可知 
        # 因为需要前后两根柱子，所以很很容易想到 双指针发
        # 由于需要纯水最多，即保证，高且离两边柱子保留，为最大
        # 所以定义两个指针，指向前后，通过指针所代表的大小进行移动指针即可
        # 代码逻辑如下
        left, right = 0, len(height)-1
        maxv = 0
        while(left<right):
            maxv = max(maxv, min(height[right], height[left])*(right-left))
            if height[left]> height[right]:
                right -= 1
            else:
                left += 1
        return maxv
```

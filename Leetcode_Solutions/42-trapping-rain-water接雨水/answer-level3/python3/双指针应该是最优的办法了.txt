### 解题思路 
官方给了很多解法，有一些没怎么仔细理解（比如栈）

拿到这个题目，比较自然想到的就是逐块进行累加，那么这个块的大小取决于他左右挡板里较小的那一个和当前位置的高度差
所以对于每一个位置，暴力的解法是向前找一个边界，向后找一个边界，然后再用我们之前构想的算法

每一个位置都需要遍历太麻烦了，可以事先先遍历的时候就存下来，相当于是要遍历三遍，而且要开不小的空间去存储中间结果

那么双指针就来了，确实比较难想，有点爬山的感觉，就是当另外一个边界比你这边的边界高的时候，你这边其实就可以进行更新了

### 代码

```python3
class Solution:
    def trap(self, height: List[int]) -> int:
        # 双指针，山顶会和
        n = len(height)
        if n == 0:
            return 0
        left = 0
        right = n-1
        max_left = height[left]
        max_right = height[right]
        ans = 0
        
        while(left<right):
            if max_left <= max_right:
                ans += max_left - height[left]
                left += 1
                max_left = max(height[left],max_left)
            
            if max_left > max_right:
                ans += max_right - height[right]
                right -= 1
                max_right = max(height[right],max_right)
        
        return ans      
```
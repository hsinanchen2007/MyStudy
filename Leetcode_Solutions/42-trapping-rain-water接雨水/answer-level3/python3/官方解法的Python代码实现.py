### 1. 暴力解法
```py
# solution 1, brute force
class Solution:
    def trap(self, height: List[int]) -> int:
        ans = 0
        n = len(height)
        for i in range(1,n):
            max_left, max_right = 0, 0
            for j in range(i,-1,-1): #Search the left part for max bar size
                max_left = max(max_left, height[j])
            for j in range(i,n): #Search the right part for max bar size
                max_right = max(max_right, height[j])            
            ans += min(max_left, max_right) - height[i]        
        return ans
```
### 2. 动态编程
```py
# solution 2, loop with left_max, right_max memory
class Solution:
    def trap(self, height: List[int]) -> int:
        if not height:
            return 0
        ans = 0
        size = len(height)
        left_max = [0]*size 
        right_max = [0]*size
        # init the memory
        left_max[0] = height[0]
        right_max[size - 1] = height[size - 1]

        for i in range(1,size):
            left_max[i] = max(height[i], left_max[i - 1])
        for i in range(size-2,-1,-1):
            right_max[i] = max(height[i], right_max[i + 1])
        for i in range(1,size):
            ans += min(left_max[i], right_max[i]) - height[i]
        return ans
```
### 3. 单调栈
```py
# solution 3, decreasing stack, refer to No.84,85
class Solution:
    def trap(self, height: List[int]) -> int:
        ans = 0
        stack = []
        for current in range(0,len(height)):
            # pop out if current height is bigger than the top one in stack
            while ((len(stack)>0) and height[current] > height[stack[-1]]):
                # pop out last one in the stack
                top = stack.pop(-1)           
                if len(stack)==0:
                    break
                # for the top, l_max is the 2nd last one in the stack, r_max is the just met current height.
                distance = current - stack[-1] - 1
                bounded_height = min(height[current], height[stack[-1]]) - height[top]
                ans += distance * bounded_height           
            stack.append(current)       
        return ans
```
### 4. 双指针
```py
# solution 4, double index pointer
class Solution:
    def trap(self, height: List[int]) -> int:
        left = 0
        right = len(height) - 1
        ans = 0
        left_max = right_max = 0
        # left_max is max value  in  height[0,    left]
        # right_max is max value  in height[right, n-1]
        while (left < right):
            left_max = max(left_max, height[left])
            right_max =  max(right_max, height[right])

            if (left_max < right_max):
                ans += (left_max - height[left])
                left +=1            
            else:
                ans += right_max - height[right]
                right -=1   
        return ans
```
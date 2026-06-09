### 解题思路
用一个栈存下所有的正数和索引，越到负数就判断。

### 代码

```python3
class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        stack = []
        res = [True] * len(asteroids)
        for i in range(len(asteroids)):
            if asteroids[i] > 0:
                stack.append((asteroids[i],i))
            elif asteroids[i] < 0:
                while stack and stack[-1][0] < abs(asteroids[i]):
                    #栈顶元素小于负数的绝对值，就弹出栈顶
                    if stack[-1][0] < abs(asteroids[i]):
                        res[stack[-1][1]]= False
                        stack.pop()
                if stack:
                    #栈顶元素等于负数的绝对值，就弹出栈顶，并删除负数
                    if stack[-1][0] == abs(asteroids[i]):
                        res[stack[-1][1]]= False
                        stack.pop()
                    res[i]= False
        ans = []
        for i in range(len(asteroids)):
            if res[i] == True:
                ans.append(asteroids[i])
        return ans
```
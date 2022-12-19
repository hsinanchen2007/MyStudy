### 解题思路
只有在栈顶元素>0,新到元素小于0=>碰撞
善于利用while-else语句：
当满足栈**非空** 并且 **新到元素<0<栈顶元素** 执行循环，否则将新到元素加入栈。
在循环中，判断**是否连续碰撞**，**是否对消**。

### 代码

```python3
class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        #栈：只有栈顶元素>0,新到元素小于0=>碰撞
        if len(asteroids)<2:return asteroids#special case
        stack=[]
        lens=len(asteroids)
        for item in asteroids:
            while stack and item <0<stack[-1]:#碰撞
                if stack[-1]<abs(item):#继续撞击
                    stack.pop()#撞没了栈顶的行星，item继续撞向下一个
                    continue
                elif stack[-1]==abs(item):#两者怼没了
                    stack.pop()
                    break
                else:#栈顶元素把item撞没了
                    break
                    
            else:# if not stack or not (item<0<stack[-1])
                stack.append(item)#其他情况均不撞击
        return stack

                    
                        



                
```
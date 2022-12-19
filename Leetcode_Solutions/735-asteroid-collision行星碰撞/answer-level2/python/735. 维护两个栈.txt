### 解题思路
如果给的序列最右边是正数的话，则永远不会相撞。
我们维护两个栈，一个栈负责全局，一个栈负责记录向左移动的恒星。
先将所有的恒星从0到len(asteroids)依次加入全局栈stack当中。
下面进行两个栈的维护：
    当栈顶为负时，把恒星加入向左恒星栈中
    当栈顶为正且向左恒星栈为空时，把该恒星加入到向右答案中
    当栈顶为正，但是向左恒星栈不为空时，取出该栈顶，和向左恒星栈的栈顶进行碰撞，结果要么不作为（大小相等），加入到全局栈中（往右的大），加入到向左恒星栈中（往左的大）
### 代码

```python
class Solution(object):
    def asteroidCollision(self, asteroids):
        """
        :type asteroids: List[int]
        :rtype: List[int]
        """
        stack = []
        for asteroid in asteroids:
            stack.append(asteroid)
        
        leftGoingStack = []
        ans = []
        while stack != []:
            cur = stack[-1]
            if cur > 0 and leftGoingStack == []:
                stack.pop()
                ans.insert(ans.begin(),cur)
            if cur > 0 and leftGoingStack != []:
                lefGoingAsteroid = leftGoingStack[-1]
                leftGoingStack.pop()
                if abs(cur) > abs(lefGoingAsteroid):
                    stack.append( cur)
                elif abs(cur) == abs(lefGoingAsteroid):
                    1+1
                else:
                    leftGoingStack.append(-1*abs(lefGoingAsteroid))
                stack.pop()
            if cur < 0:
                leftGoingStack.append(cur)
                stack.pop()
        return leftGoingStack[::-1] + ans

```
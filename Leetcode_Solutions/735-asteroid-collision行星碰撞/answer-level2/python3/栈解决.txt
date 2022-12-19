### 解题思路
利用栈的性质很自然地可以完成这一题
首先，遍历元素，默认元素可以入栈（首元素，或与栈顶同号元素，必不会发生碰撞）

其次解决发生碰撞的情况
只有在左边的向右，在右边的向左，才会发生碰撞，如果反过来，即使运动方向不同，距离也会越来越远
所以只在栈不空且栈顶是正数的情况才进行处理

接下来就简单了，新元素不够大，无事发生
新元素一样大，栈退回 结束
新元素更大，栈退回，继续检测碰撞

while前的else表示异号时的情况
而while的else表示异号但是反向运动的情况（也即是上面说的越来越远的情况）
while中的部分处理越来越近会碰撞的情况

### 代码

```python3
class Solution:
    def asteroidCollision(self, asteroid: List[int]) -> List[int]:
        ans = []
        if len(asteroid) == 0 :
            return ans
        elif len(asteroid) == 1 :
            return asteroid
        for i in asteroid :
            if len(ans) == 0 or ans[-1] * i >= 0 :
                ans.append(i)
            else :
                while len(ans)!=0 and ans[-1] > 0 :
                    if abs(ans[-1]) > abs(i) :
                        break
                    elif abs(ans[-1]) == abs(i) :
                        ans.pop()
                        break
                    else :
                        ans.pop()
                else :
                    ans.append(i)

        return ans
```
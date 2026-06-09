利用栈的思想，遍历给定数组里的数，大于0直接入栈；小于0的话，则从栈尾开始向前遍历，如果栈不为空且栈尾数字大于0小于当前数字，则依次去除栈尾元素。若栈为空或栈尾元素小于0，则直接入栈；若栈尾元素等于当前数的绝对值则去除栈尾元素；否则不对栈进行操作。
```
class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        res = [asteroids[0]]
        for num in asteroids[1:]:
            if num < 0:
                if res == [] or res[-1] < 0:
                    res.append(num)
                else:
                    while res != [] and res[-1] > 0 and res[-1] < abs(num):
                        res = res[:-1]
                    if res == [] or res[-1] < 0:
                        res.append(num)
                    elif res[-1] == abs(num):
                        res = res[:-1]
            else:
                res.append(num)
        return res
```

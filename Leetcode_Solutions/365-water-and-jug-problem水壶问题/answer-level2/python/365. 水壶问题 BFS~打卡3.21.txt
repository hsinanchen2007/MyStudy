### 解题思路
首先这道题中有个要求：
>装满任意一个水壶
>清空任意一个水壶
>从一个水壶向另外一个水壶倒水，直到装满或者倒空

说明这是一个从一个状态到另外一个状态：BFS!!!，只要找到符合要求的就返回即可
如下图（代码中有注释！！）
![image.png](https://pic.leetcode-cn.com/78cf6ca8c4d4321f4df770315b55959b1bf781b2c9620bbb41d14e1f87133732-image.png)

这道题是还是要将问题进行建模，只要想到了就很容易的
### 代码

```python3
class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:

        queue = [(0, 0)]
        visited = set((0, 0))
        
        def operate(cur_state):
            """这里实现题目中运行的三个操作"""
            a, b = cur_state
            next_state = set()
            # 装满任意一个水壶，有两种情况装满A，装满B
            next_state.add((x, b)) 
            next_state.add((a, y)) 

            # 清空任意一个水壶，有两种情况清空A，情况B
            next_state.add((0, b))
            next_state.add((a, 0))
            
            # 从一个水壶向另外一个水壶倒水，直到装满或者倒空
            # 第一种，A倒入B
            if a + b < y: # A倒空了
                next_state.add((0, a + b))
            elif a + b >= y: # B装满了
                next_state.add((a- (y - b), y))

            # 第二种，B倒入A
            if a + b < x:  # B倒空了
                next_state.add((a + b, 0))
            elif a + b <= x: # A装满了
                next_state.add((x, b - (x - a)))

            return next_state

        while queue:
            cur_state = queue.pop(0)
            if cur_state[0] == z or cur_state[1] == z or cur_state[0] + cur_state[1] == z:
                return True
            next_state = operate(cur_state)
            for state in next_state:
                if state not in visited:
                    queue.append(state)
                    visited.add(state)
        return False
```
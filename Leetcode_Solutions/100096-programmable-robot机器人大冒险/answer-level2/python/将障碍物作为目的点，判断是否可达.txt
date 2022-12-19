### 解题思路
1.将障碍物和目标点都作为目的点，通过判断是否可以到达来判断是否碰撞
2.将目的点坐标先平移n次大循环距离，保留最后一次循环进行单步判断，减少最后判断需要的累加
2.1 为了简单，假定是目标点逐渐向0，0靠近
2.2 在最后一次command循环之前，都不需要进行单步的判断，因此可以通过一次移动整个command距离来减少计算，实际是通过乘法把目标点平移到最后一次需要command单步的位置


### 代码

```python3
class Solution:
    def calcLeftStep(self, purpose: List[int], distx, disty) -> List[int]:
      stepx = int(purpose[0]/distx) # 从x=0开始走到purpse_x需要多少步
      stepy = int(purpose[1]/disty)
      step = min(stepx, stepy) # 取较小值
      left_step = [0, 0]
      left_step[0] = purpose[0] - step * distx # 剩余距离
      left_step[1] = purpose[1] - step * disty
      return left_step 
    
    def judgeReach(self, command: str, left_step: List[int]) -> bool:
      while left_step[0] >=0 and left_step[1] >= 0:
        for c in command:
          if left_step[0] == 0 and left_step[1] == 0: # 判断是否到达
            return True
          if c == 'U':
            left_step[1] -= 1
          else:
            left_step[0] -= 1
      return False

    def robot(self, command: str, obstacles: List[List[int]], x: int, y: int) -> bool:
      lx = 0
      ly = 0

      distx = 0
      disty = 0
      for c in command:
        if c == "U":
          disty += 1
        else:
          distx += 1

      left_step = self.calcLeftStep([x, y], distx, disty)
      print(left_step)
      if not self.judgeReach(command, left_step): # 终点不可达
        return False

      if not obstacles: # 无障碍物
        return True

      for ob in obstacles:
        if ob[0] <= x and ob[1] <= y: # 只需要判断终点右下区域
          left_step = self.calcLeftStep(ob, distx, disty)
          print(left_step)
          if self.judgeReach(command, left_step): # 障碍物可达
            return False
      
      return True
      
```
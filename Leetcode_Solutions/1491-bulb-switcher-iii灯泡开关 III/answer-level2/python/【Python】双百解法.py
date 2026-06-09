### 解题思路
看题看了很久…简而言之就，如果到第i盏灯的时候，前i盏灯中的编号最大值(max(light[:i+1])如果等于i，就能满足蓝灯的要求。

### 代码

```python3
class Solution:
    def numTimesAllBlue(self, light: List[int]) -> int:
        ans = 1 if light[0] == 1 else 0 
        max_value = light[0]
        for i in range(1,len(light)):
            max_value = max(max_value, light[i])
            if i+1 == max(light[i], max_value):
                ans += 1
        return ans

```
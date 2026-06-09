### 解题思路
想要灯变蓝一次，则要满足扫描过的灯的最大序号等与扫过的灯的个数。扫描一遍输入，维护一个变量记录当前扫过的灯的最大序号即可。

### 代码

```python3
class Solution:
    def numTimesAllBlue(self, light: List[int]) -> int:
        cur_max = 0
        ans = 0
        for i in range(len(light)):
            if light[i] > cur_max:
                cur_max = light[i]  
            if cur_max == i+1:
                ans += 1
        return ans
```
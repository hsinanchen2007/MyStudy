### 解题思路
pos逆序，计算到达时间，数峰个数

### 代码

```python3
class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        if not position: return 0
        cars = sorted(zip(position, speed), reverse=True)
        times, ans = [(target - p) / s for p, s in cars], 1
        cur_max = times[0]
        for i in range(1, len(times)):
            if times[i] > cur_max:
                ans += 1
                cur_max = times[i]
        return ans

```
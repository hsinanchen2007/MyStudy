### 解题思路
正序列计数到最高峰
逆序列计数到最高峰

### 代码

```python3
class Solution:
    def trap(self, height: List[int]) -> int:
        if len(height)==0:
            return 0
        now = [0, height[0]]
        def count_water(height, now):        
            i = 0
            water = []
            while i<len(height):
                if height[i] <= now[1]:
                    water_now = now[1]-height[i]
                    water.append(water_now)
                else:
                    now = [i, height[i]]
                    water.append(0)
                i += 1
            return water,now
        
        water_z,now = count_water(height, now)
        #print(water_z)
        #print(now)
        re_height = height[now[0]:]
        re_height.reverse()
        n = [0, re_height[0]]
        
        water_n,n = count_water(re_height, n)
        #print(water_n)
        inde = now[0]
        ans = sum(water_z[:inde])+sum(water_n)#+water_n.reverse()+sum(w)

        return ans

```
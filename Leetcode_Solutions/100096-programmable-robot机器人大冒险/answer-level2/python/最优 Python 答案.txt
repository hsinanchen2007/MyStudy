解题不难，难的是写的优雅。

```python
class Solution(object):
    def robot(self, command, obstacles, x, y):
        """
        :type command: str
        :type obstacles: List[List[int]]
        :type x: int
        :type y: int
        :rtype: bool
        """
        # 每走一圈 U 和 R 的步数
        u_times = r_times = 0
        for i in command:
            if i == 'U':
                u_times += 1
            elif i == 'R':
                r_times += 1
        
        # x,y 在不在行进的线路上，由于路线循环，所以可以直接判断
        def can_i_get_there(x, y):
            xr = int(x / r_times)
            yr = int(y / u_times)

            if abs(xr - yr) > 1:
                return False
            
            t = min(xr, yr)
            start = [r_times * t, u_times * t]
            if start  == [x, y]:
                return True

            for i in command:
                if i == 'U':
                    start[1] += 1
                elif i == 'R':
                    start[0] += 1
                
                if start == [x, y]:
                    return True

            return False
        
        # 只判断终点之前的障碍物
        for i, v in enumerate(obstacles):
            vx, vy = v
            if vx <= x and vy <= y:
                if can_i_get_there(vx, vy):
                    return False
        
        if not can_i_get_there(x, y):
            return False
        
        return True
```
```
class Solution(object):
    def robotSim(self, commands, obstacles):
        """
        :type commands: List[int]
        :type obstacles: List[List[int]]
        :rtype: int
        """
        x = 0
        y = 0
        d_i = 0
        max_l = 0
        
        my_dict = {}
        for val in obstacles:
            my_dict[tuple(val)] = 1
        
        for command in commands:
            if command == -1:
                d_i =(d_i + 1) % 4
            elif command == -2:
                d_i = (d_i - 1 + 4) % 4
            else:
                if d_i == 0:
                    while not my_dict.has_key((x, y+1)) and command:
                        y += 1
                        command -= 1    
                elif d_i == 2:
                    while not my_dict.has_key((x, y-1)) and command:
                        y -= 1
                        command -= 1    
                elif d_i == 1:
                    while not my_dict.has_key((x+1, y)) and command:
                        x += 1
                        command -= 1
                elif d_i == 3:
                    while not my_dict.has_key((x-1, y)) and command:
                        x -= 1
                        command -= 1
                new_l = pow(x,2) + pow(y,2)
                if new_l > max_l:
                    max_l = new_l
        return max_l
```

执行用时 :340 ms, 在所有 python 提交中击败了98.11%的用户
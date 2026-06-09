```
class Solution:
    def leastBricks(self, wall: List[List[int]]) -> int:
        height = len(wall)
        width = sum(wall[0])
        #  垂线穿过最少的砖，就是穿过除墙左右边缘外最多的砖缝
        #  chink统计处于同一水平距离的缝隙的数目
        chink ={}
        for line in wall:            
            s = 0
            for block_width in line:
                # s表示当前砖块的右边缘到墙左边缘的距离
                s = s+block_width
                if s not in chink:
                    chink[s] = 0
                chink[s] += 1
        
        chink.pop(width)  # 去掉墙的右边缘统计 
        # 每一行都只有一块砖的话，只得穿过所有砖
        if not chink:
            return height
            
        return height - max(chink.values())
        

                
```

```
        if grid[0][0] == 1:
            return -1

        N = len(grid)
        directions = [(0,1), (0,-1), (1,0), (-1,0), (1,1), (1,-1), (-1,-1), (-1,1)]
        
        stacks = [([0,0], 1)]
        grid[0][0] = 1
        
        while stacks:
            curr_node, total_step = stacks.pop(0)
            if curr_node[0] == N-1 and curr_node[1] == N-1:
                return total_step
            
            for direc in directions:
                next_node_x = curr_node[0] + direc[0]
                next_node_y = curr_node[1] + direc[1]
                # 首先判断是否出了边界, 如果没出边界判断是否被访问过
                if 0 <= next_node_x <= N-1 and 0 <= next_node_y <= N-1 and grid[next_node_x][next_node_y] == 0:
                    grid[next_node_x][next_node_y] = 1
                    stacks.append(([next_node_x, next_node_y], total_step+1))
        
        
        return -1
```

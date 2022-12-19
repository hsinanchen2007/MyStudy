这种周期性推进的完全可以理解成一个环，移动K个就像念珠往前挪动K个珠子，每移动元素个数长度其实就是一个周期，不会影响最终的list表现形式，所以在处理的时候要用k对元素个数取模，第一次参加周赛，只能用一个暴力办法解决了，不管是时间还是空间都不算是最优解
class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        m = len(grid)
        n = len(grid[0])
        list_length = m*n
        k = k% list_length #周期处理
        new_grid_1 = [] #可以有更好的处理方式
        for i in grid:
            for j in range(n):
                new_grid_1.append(i[j])
        new_grid = [0]*(list_length)     
        for i in range(list_length):
            if i <= list_length - 1 -k:                
                new_grid[i + k] = new_grid_1[i]
            else:
                new_grid[i+ k - list_length] = new_grid_1[i]
        for j in range(list_length):
            grid_index = j // n
            sub_index = j % n
            grid[grid_index][sub_index] = new_grid[j]
            
        return grid
#简单易懂

执行用时 :48 ms, 在所有 Python3 提交中击败了93.75%的用户
内存消耗 :14 MB, 在所有 Python3 提交中击败了100.00%的用户

题目要求返回是否完好到达终点，而终点（x,y）0 <= x <= 1e9, 0 <= y <= 1e9，所以暴力算路径会超时。
所幸在于指令command是一种循环，实际上每一层循环的坐标都是第一次循环UR数量的倍数加上基础坐标。
这样就可以求得，只要任何一个obstacle在路径上，就可以输出false。
所以只用匹配每个obstacle是否在循环路径中。
变成了一道初中数学问题。
xn = n*x + x1
yn = n*y + y1
反向求解即可

# class Solution:
    def robot(self, command: str, obstacles: List[List[int]], x: int, y: int) -> bool:
        a, b = 0, 0
        path = [[0,0]]

        #第一次循环的路径，作为基础坐标（x1, y1）
        for v in command:
            if v == "U":
                b += 1
            else:
                a += 1
            path.append([a, b])

        #判断终点是否能到达
        if [x % path[-1][0] , y - ((x // path[-1][0]) * path[-1][1])] not in path:
            return False
        
        #判断ob在终点范围以内，再判断是否在循环路径中
        for ob in obstacles:
            if ob[0] <= x and ob[1] <= y:
                if [ob[0] % path[-1][0] , ob[1] - ((ob[0] // path[-1][0]) * path[-1][1])] in path:
                    return False
        return True


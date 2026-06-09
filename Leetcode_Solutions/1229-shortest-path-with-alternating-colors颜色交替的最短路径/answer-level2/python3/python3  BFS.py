class Solution:
    def shortestAlternatingPaths(self, n: int, red_edges: List[List[int]], blue_edges: List[List[int]]) -> List[int]:
        
        if n < 1:
            return []
        res_r = [-1 for _ in range (n)]
        res_b = [-1 for _ in range (n)]
        res =[-1 for _ in range(n)]
        res_r[0] = 0
        res_b[0] = 0
        queue = []
        rn = len(red_edges)
        bn = len(blue_edges)

        for i in range(rn):
            if red_edges[i][0] == 0:
                queue.append([red_edges[i][0],red_edges[i][1],"R"])
                red_edges[i][0] = -1    # 修改值，使得下次不会在使用
        for i in range(bn):
            if blue_edges[i][0] == 0:
                queue.append([blue_edges[i][0],blue_edges[i][1],"B"])
                blue_edges[i][0] = -1   # 修改值，使得下次不会在使用

        while len(queue) > 0:
            cur = queue.pop(0)

            if cur[2] == "R":   # 红色边到达这个节点
                if res_r[cur[1]] >= 0:
                    res_r[cur[1]] = min(res_r[cur[1]],res_b[cur[0]] + 1)
                else:
                    res_r[cur[1]] = res_b[cur[0]] + 1

                for i in range(bn):         #搜索从这个节点出发的所有蓝色边
                    if blue_edges[i][0] == cur[1]:
                        queue.append([blue_edges[i][0],blue_edges[i][1],"B"])
                        blue_edges[i][0] = -1
            else:             # 蓝色边到达这个节点
                if res_b[cur[1]] >= 0:
                    res_b[cur[1]] = min(res_b[cur[1]],res_r[cur[0]] + 1)
                else:
                    res_b[cur[1]] = res_r[cur[0]] + 1

                for i in range(rn):   #搜索从这个节点出发的所有红色边
                    if red_edges[i][0] == cur[1]:
                        queue.append([red_edges[i][0],red_edges[i][1],"R"])
                        red_edges[i][0] = -1
        
        for i in range(n):  # 取最小值
            if res_r[i] >=0 and res_b[i] >= 0:
                res[i] = min(res_r[i],res_b[i])
            else:
                res[i] = max(res_r[i],res_b[i])
        return res
第一次写题解,当作笔记吧.

        思路: blocked 能封锁的 最多坐标数是 (len(blocked)*(len(blocked)-1))//2, 
              如果从开始-->目标 能走的步数大于这个数,
                 从 目标-->开始 能走的步数大于这个数,  (因为目标也可能被blocked包围,双向检测)
                 则True   
              广度搜索,走过的放入walked.
              判断是否走过或者在blocked里,用set()查询O(1).

下图是用 Onenote画的,最大封锁坐标数. 等差为1的等差数列求和.
![1036. 逃离大迷宫_草图.png](https://pic.leetcode-cn.com/45fde40094c9b17243e055621fe5356f2f26d2f60dc5092baab4def795dd6b27-1036.%20%E9%80%83%E7%A6%BB%E5%A4%A7%E8%BF%B7%E5%AE%AB_%E8%8D%89%E5%9B%BE.png)
具体代码都写了注释,变量名都是很直观的.
```
class Solution:

    def isEscapePossible(self, blocked: list, source: list, target: list) -> bool:
        if not blocked:  # 刷力扣的第一条,不管题意说没说空,都先来个空集.
            return True
        blocked = set([(x, y) for x, y in blocked])
        walked_steps = 1  # 开始步数,出发点也占据 1个坐标方块
        source_to_target = Solution._bfs(source, blocked, walked_steps, target)  # 把初始点和目标点传给BFS.
        target_to_source = Solution._bfs(target, blocked, walked_steps, source)  # 和上面一样,对调.
        return source_to_target and target_to_source

    @staticmethod
    def _bfs(start, blocked: set, walked_steps: int, end: list):
        movies = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        walked = set()
        walked.add((start[0], start[1]))  # 把出发点加入walked
        q = [start]  # list的pop() O(1),当作queue用. 
        while q:
            if walked_steps > (len(blocked)*(len(blocked)-1))//2:  # 步数超过最大封锁坐标数.
                return True
            x, y = q.pop()  
            for m in movies:
                new_x = x + m[0]
                new_y = y + m[1]
                if [new_x, new_y] == end:  # 如果已经走到目标点,就返回True
                        return True
                if 0 <= new_x < 1000000 and 0 <= new_y < 1000000:                   
                    if (new_x, new_y) not in blocked:  # 不是障碍坐标点 (可以写在最上面的if 里, 可是太长了...我就写下面了.)
                        if (new_x, new_y) not in walked:  # 且没走过
                            walked_steps += 1  # 步数加1
                            q.append([new_x, new_y])  # 加到q里, 下一次开始走的坐标.
                            walked.add((new_x, new_y))  # 加到走过的坐标集合walked里.
        return False  # 能走的都走过了,步数没有超过最大封锁数,或者没有走到end(即target).
```

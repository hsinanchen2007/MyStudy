这一题就是简单的贪心法的运用，当然要比经典的四色问题要简单。步骤就是：按顺序依次遍历每个花园，遍历的过程中，检查遍历到的点周围颜色情况，然后挑一个没用过的颜色放入即可，而且尽可能用最少的花。这里面关键点就是遍历到每个点时，如何筛选出已经用过的花，因为花只有4朵，且不可重复。
不过，有个地方我一直没太看懂，就是题目的一条要求是：不存在花园有 4 条或者更多路径可以进入或离开。我的理解是如果把N个花园看做一张图，那么每个花园代表的节点的入度或出度数小于4，但我丝毫看不出这个要求在题目中体现出来了。如果有朋友看懂了这个要求，还请不吝赐教。
**代码如下**
```Python
class Solution(object):
    def gardenNoAdj(self, N, paths):
        """
        :type N: int
        :type paths: List[List[int]]
        :rtype: List[int]
        """
        # 初始化路径为0
        route = [0] * N
        from collections import defaultdict
        # 该字典用来记录边的集合：key->value表示与key相连接的节点在value集合内
        path_dict = defaultdict(list)
        # 将paths顺序排序，使得最后的结果也是顺序排列的
        paths.sort()
        for path in paths:
            path_dict[path[0]].append(path[1])
            path_dict[path[1]].append(path[0])
        # 开始贪心操作，即遍历的过程中，检查遍历到的点周围颜色情况，然后挑一个没用过的颜色放入即可
        # 而且尽可能用最少的花
        for i in range(1, N+1):
            all_flower = list(range(1, 5))
            for value in path_dict[i]:
                # 剔除用过的花，最后选取第一朵没有用过的花即可
                if route[value-1] in all_flower:
                    all_flower.remove(route[value-1])
            route[i-1] = all_flower[0]
        return route

if __name__ == "__main__":
    N = 4
    paths = [[1, 2], [3, 4]]
    route = Solution().gardenNoAdj(N, paths)
    print(route)
```
执行效率中等吧，在40%左右。
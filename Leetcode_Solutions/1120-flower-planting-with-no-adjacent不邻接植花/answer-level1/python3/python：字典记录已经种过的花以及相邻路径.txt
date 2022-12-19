执行用时 : 244 ms, 在Flower Planting With No Adjacent的Python3提交中击败了91.86% 的用户

内存消耗 : 17.6 MB, 在Flower Planting With No Adjacent的Python3提交中击败了100.00% 的用户


```
class Solution:
    def gardenNoAdj(self, N, paths):
        from collections import defaultdict
        garden_flower = {}  # 记录已经种过花的花园钟的是哪一种
        path_dict = defaultdict(list)  # 记录各个花园相连的花园，list的长度不会超过3
        for path in paths:
            path_dict[path[0]].append(path[1])
            path_dict[path[1]].append(path[0])

        flower = set([1, 2, 3, 4])  # 一共4种花
        result = []
        # 从第一个花园开始，依次种花，遍历相连的花园都种了啥，然后看看这个花园可以种啥
        for i in range(1, N+1):  
            if i in path_dict:
                used_flower = []
                for connected_garden in path_dict[i]:
                    if connected_garden in garden_flower:
                        used_flower.append(garden_flower[connected_garden])
                this_garden_flower = (flower - set(used_flower)).pop()
            else:
                this_garden_flower = 1
            result.append(this_garden_flower)
            garden_flower[i] = this_garden_flower
        return result
```
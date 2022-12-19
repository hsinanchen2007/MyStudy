### 解题思路
此处撰写解题思路
终于做出来了，虽然性能很差，以后学到新东西再改进吧，这里先说下这道题的思路与收获。
#### 思路
使用BFS单纯进行搜索。当然这样肯定会超时。因此：
1.坐标离散化。
    就是所谓的坐标离散化处理，这样做是很有必要的，通过大矩阵变小矩阵，大大缩小时间复杂度。
    
这时我得到如下结果：
![image.png](https://pic.leetcode-cn.com/8cb23ed812a89496e5651ec2461a665f170137016e16fc9352f14fcb30a09c90-image.png)
2.使用set优化搜索。
    使用BFS的同时我们一定会找个东西记录访问过的坐标。如果你用list，很很遗憾，no。还是用set集合进行查找，效率很高。

    使用set后不再超时：
![image.png](https://pic.leetcode-cn.com/e9949e767396a2fe2cbbeb854f88bc0790495b7f029af3058ce5c27044e8b6e1-image.png)

3.设置步数界限
    如果不能到达，这说明source或者target被堵住啦，那么如何知道在最坏情况下被赌住可以走的步数呢？
    最坏的一种情况就是，blocked坐标和两个边界一起形成一个三角形，堵住source或target。
    在blocked为最大长度200时，最坏情况下可以走的步数计算为： 1+2+3+4+5+...+198+199=(1+199)*199/       2=19900 ，也即max_steps=len(blocked)*len(blocked-1)/2.
    这个可以作为界限，当步数大于max_steps时，说明没有被堵住。
    当然对于source和target要都判断是否被堵。

    0th                              
         |-------------------- X            
         |-------------------X
         |                .
         |             .
         .           . 
         .        X
         .    X
    200  | X
    
    根据提示，效率提高三倍：
![image.png](https://pic.leetcode-cn.com/9ab370ed1f995f160252068079afaf3d76349f6e9e0f7e6c57472dc7a1477185-image.png)



### 代码
# -*- coding: utf-8 -*-
"""
@author: MaBingyang
@contact: qq418055608@163.com
@software: PyCharm
@file: bigmaze.py
@time: 2020/2/3 13:14
"""


class Solution:
    def isEscapePossible(self, blocked, source, target) -> bool:
        DIRECTION = ((0, 1), (1, 0), (-1, 0), (0, -1))
        ROW = COL = pow(10, 6)

        #主要为离散化做准备，将坐标轴进行分区
        def part(ls, final):
            ls.sort()
            part = []
            last = -1
            for x in ls:
                part.append((last, x))
                part.append((x, x))
                last = x
            part.append((ls.pop(), final))
            part = filter(lambda x: x[0] + 1 != x[1], part)
            part = list(set(part))
            part.sort()
            return part
        #用与将坐标进行转化
        def translate_xy(x, y, xpart, ypart):
            _ = list(filter(lambda width: width[0] < x < width[1] or x == width[0] == width[1], xpart))
            if len(_) == 1:
                x = xpart.index(_[0])
            _ = list(filter(lambda width: width[0] < y < width[1] or y == width[0] == width[1], ypart))
            if len(_) == 1:
                y = ypart.index(_[0])
            return x, y
        #判断是否可以访问此坐标
        def check(x, y, blocked):
            if (x, y) not in blocked and 0 <= x < ROW and 0 <= y < COL: return True
            return False

        #普通的bfs搜索
        def BFS(source, target, blocked):
            blocked = {*blocked}
            steps_blocked = len(blocked) * (len(blocked) - 1) // 2
            steps = []
            blocked.add(source)
            steps.append(source)

            for point in steps:
                if point == target:
                    return True
                if len(steps) > steps_blocked:
                    return True
                for direction in DIRECTION:
                    x_ = point[0] + direction[0]
                    y_ = point[1] + direction[1]
                    if check(x_, y_, blocked):
                        blocked.add((x_, y_))
                        steps.append((x_, y_))

            return False

        #进行初始化处理，包括 坐标离散转化
        def init():
            #如果无阻碍直接返回True
            if not blocked: return False
            nonlocal ROW,COL,source,target
            xe = [e[0] for e in blocked]
            ye = [e[1] for e in blocked]
            xpart = part(list(set(xe)), ROW)
            ypart = part(list(set(ye)), COL)
            x_len = len(xpart)
            y_len = len(ypart)
            source = translate_xy(*source, xpart, ypart)
            target = translate_xy(*target, xpart, ypart)

            for index, el in enumerate(blocked):
                blocked[index] = translate_xy(*el, xpart, ypart)
            ROW = x_len
            COL = y_len
            return True

        if init():return BFS(target, source, blocked) and BFS(source, target, blocked)
        else:return True

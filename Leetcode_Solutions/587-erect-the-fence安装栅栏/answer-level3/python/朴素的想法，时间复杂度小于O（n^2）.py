最简单直接的方法就是从边界的一棵树出发，以这棵树作为直线的一个点，让这条直线沿一个方向旋转，最先碰到的树必然是边界点，继续这个过程，直到回到最开始的位置。
需要考虑如果有多棵树位于同一条边界线上，我们选择距离之前的一棵树最短的那棵

如何判断哪棵树是直线最先碰到的呢？可以通过线段的夹角来判断，考虑下一个边界点与之前的两个边界点构成的钝角的补角，这个补角就是多边形的外角，表示直线从一条边到相邻的另一条边旋转的角度，这个角度一定比多边形内部的点小，此外，还要尽可能避免浮点数运算，时间复杂度O（k*（n-1）），k是边界点的个数

下面是代码



class Solution(object):
    def outerTrees(self, points):
        """
        :type points: List[List[int]]
        :rtype: List[List[int]]
        """
        def findAnotherTree(t1, t2, points):
            
            a = [t2[0] - t1[0], t2[1] - t1[1]]
            b = [-a[0], -a[1]]
            min_norm = 300
            for t in points:
                if t == t2:
                    continue
                else:
                    c = [t[0] - t2[0], t[1] - t2[1]]
                    norm_c = abs(c[0]) + abs(c[1])
                    s1 = (a[0]*b[0] + a[1]*b[1]) * abs(a[0]*b[0] + a[1]*b[1])
                    s2 = (a[0]*c[0] + a[1]*c[1]) * abs(a[0]*c[0] + a[1]*c[1])
                    sa = a[0]**2 + a[1]**2
                    sb = b[0]**2 + b[1]**2
                    sc = c[0]**2 + c[1]**2
                    #找到夹角最小的点，此外如果共线，则选距离最短的下一颗树
                    if s1 * sa * sc < s2 * sa * sb or (s1 * sa * sc == s2 * sa * sb and norm_c < min_norm):
                        min_norm = norm_c
                        t3 = t[:]
                        b = c[:]
            return t3
        #如果小于4棵树，所有的点必然都是边界点，直接输出
        if len(points) < 4:
            return points
        
        tree_list = []
        min_y = 100
        for p in points:
            if p[1] < min_y:
                min_y = p[1]
                lowest_point = p
        
        #从位置最低的树开始逆时针搜索，直线初始为水平
        t1 = [lowest_point[0] - 1, lowest_point[1]]
        t2 = lowest_point
        tree_list.append(t2)
        while True:
            t3 = findAnotherTree(t1, t2, points)
            if t3 == tree_list[0]:
                break
            else:
                tree_list.append(t3)
                t1 = t2[:]
                t2 = t3[:]
        return tree_list
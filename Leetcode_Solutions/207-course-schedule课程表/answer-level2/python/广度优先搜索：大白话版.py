由题给出的课程关系，将课程看作点，我们可以得到一些彼此链接的点，并且点与点之间存在着指向，也就是有方向。  

而这种方向我们可以看做是一种依赖关系，比如下图，要完成 3 我们需要先完成 1，但是要完成 1 又得先完成 2，可 2 又依赖于 3，3 最终又依赖于 1，那么此时无解。  
![image.png](https://pic.leetcode-cn.com/3f586afa64d228cab0cc5a94806c563209e68caf25935321efad3a5285c11819-image.png)
  
如果有过多线程开发经验的人，那么就知道这形成了死锁，即那个任务都无法完成。  

那么要想完成所有课程，则不能存在这种死循环式的依赖关系，即任意个课程相连均不会构成 顺时针或逆时针的 环。  

所以到这里，我们可以将该问题转换为比较直观的表述方式：  
>如何在给定的有向点图中，确定是否存在 顺时针或逆时针 的环。

那么想想有那些算法能够检测图中是否存在环呢？首先我想到了并查集，但是并查集不能确定该环是否是顺时针或逆时针存在的，即无法作用于有向图。  

那么再思考下曾经刷过的“走迷宫的算法题”，广度优先搜索可以以一种向四周发散的方式找到出口，即不是深度优先的。那么当我们走到一个点时就给该点打上标记，然后如果后面又走到了这个点，那么我们便发现这个迷宫存在着一条路径永远也走不出去，这样就可以看作是找到了一个有向环。  

有了思路，我们来尝试写代码：
```
class Solution(object):
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        # 记录要学习 index 表示的课程前得学习多少其他课程
        marks = [0 for _ in range(numCourses)]
        # 记录学完 index 表示的课程后可学习的课程的集合
        relation = [[] for _ in range(numCourses)]

        for cur, pre in prerequisites:
            # 表示学习 cur 课程前得学习 marks[cur] 个课程
            marks[cur] += 1
            # 学习完 pre 课程就可以学习 relation[pre] 集合中的课程了
            relation[pre].append(cur)

        queue = []

        for course in range(numCourses):
            if marks[course] == 0: # 学习 course 课程不需要先学习其他课程
                queue.append(course)

        while queue:
            course = queue.pop(0)
            # 学习完了一个课程
            numCourses -= 1 
            for next_course in relation[course]:
                # next_course 的前置课程数量减少一个，因为 course 学完了
                marks[next_course] -= 1 
                if marks[next_course] == 0: # 表示学习 next_course 不需要先学习其他课程了
                    queue.append(next_course)
        return numCourses == 0
```

可能大家平时和图接触得比较少，所以一开始难以找出解题方式，你把此题看作是多棵多叉树可能会好一点，就像下图画的那样，只要子节点中不存在向根节点的指向，那么我们就可以学习完所有课程，图中几个画红线的示例指向就是不允许的。

![image.png](https://pic.leetcode-cn.com/33f101582b4a4e6eb4972c9087792e9da6d311b9b64d1a02d00b8fd3a8f75e19-image.png)

>搜索订阅号 Apelife
>关注后回复 图解，分享给你leetcode动态图解解题集
>定期为大家分享题解，学习经验，解题思路等

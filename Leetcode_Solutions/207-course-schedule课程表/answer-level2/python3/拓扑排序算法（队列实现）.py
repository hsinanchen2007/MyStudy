**解题思路：** 通俗的说，将课程的先修课程数目作为该课程的入度，最先开始学习的就是入度为0的课程。随着学习的课程的数量的增加，当某些课程的入度减少到0时，就是到了该学习这门课的时候了。所以，数学角度就是对结点（也就是这里的课程）进行拓扑排序，并按顺序更新结点入度，最终判断是否所有结点的入度都为0（即所有课程都学完了）。
**具体过程：**
1、用列表记录所有课程的入度和后置课程，遍历入度列表，将入度为0的课程放入队列；
2、弹出队首元素，同时将所有该课程的后置课程的入度-1，若变成0，则放入队列；
3、重复步骤2直至队列为空；
4、遍历入度列表，若所有课程入度都为0，返回True；

## 示例代码（Python3）
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        
        #计算所有课程的入度和后置课程
        in_d = [0 for i in range(numCourses)]
        post = [[] for i in range(numCourses)]
        for c,pc in prerequisites:
            in_d[c] += 1
            post[pc].append(c)
            
         
        #新建队列，存放入度为0的课程
        from queue import Queue
        q = Queue()
        for i in range(numCourses):
            if in_d[i] == 0:
                q.put(i)
                
        #队列不为空
        while not q.empty():
            c = q.get()
            #后置课程入度-1，如果为0则放入队列
            for i in post[c]:
                in_d[i] -= 1
                if in_d[i] == 0:
                    q.put(i)

        #再次遍历入度
        for i in in_d:
            if i > 0:
                return False
        return True
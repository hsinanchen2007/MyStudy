```
bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize){
    /* 1、首先了解下，什么是图
        图起始就是模拟不同的东西的相连
        
       2、图的存储（邻接矩阵）
          1）无序图
             0------- 1    n(i,j) 表示vi和vj之间的连线    0  1  0  1    
             \        |                                   1  0  1  0
              \       |                                   0  1  0  1
               3 -----2                                   1  0  1  0
           对接线都是0，以对角线为轴对称  
          
          2）有序图
          0------->1                        0  1  0  0
          |        |    入度                0  0  1  0
          V        V    出度                0  0  0  1
          3------->2                        0  0  1  0
        
        3、图的搜索
               1
              / \
             2   3      
            /   /| \
           4   5 6  7
          1）深度优先搜索 （DFS）
             1-2-4-3-5-6-7
             
          2) 广度优先 （BFS）
             1-2-3-4-5-6-7
             
          这题属于典型的：有向判断是否有环的
       */
    
    int* inDegree = malloc(numCourses * sizeof(int));
    int result = 0;
    int continueFlg = 0;
    /* 初始化 */
    for(int i = 0; i < numCourses; i++) {
        inDegree[i] = 0;
    }
    /* 统计每个课程依赖的课程数，即节点入度 */
    for(int i = 0; i < prerequisitesSize; i++) {
        inDegree[prerequisites[i][0]]++;
    }
    for(int i = 0; i < numCourses; i++) {
        continueFlg = 0;
        for (int j = 0; j < prerequisitesSize; j++) {
            if ((inDegree[prerequisites[j][1]] == 0 && prerequisites[j][0] != -1)) {//课程prerequisites[j][1]入度为0 且 j行prerequisites未匹配
                inDegree[prerequisites[j][0]]--;
                prerequisites[j][0] = -1;//j行prerequisites标记为已匹配
                continueFlg = 1;
            }
        }
        if (continueFlg == 0) {
            break;
        }
    }
    for(int i = 0; i < numCourses; i++) {
        result += inDegree[i];
    }
    free(inDegree);
    return ((result > 0 ) ? false : true);
}
```

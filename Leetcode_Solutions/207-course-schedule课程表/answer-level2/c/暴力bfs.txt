```
bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize){
    int inDegree[numCourses];
    for(int i = 0; i < numCourses; i++) {
        inDegree[i] = 0;
    }
    int result = numCourses;
    int continueFlg = 0;

    /* 统计每个课程依赖的课程数，即节点入度 */
    for(int i = 0; i < prerequisitesSize; i++) {
        inDegree[prerequisites[i][0]]++;
    }
    
    int *queue = (int *)malloc(numCourses * sizeof(int));
    int head = 0;
    int tail = 0;
    // 首先入队入度为 0 的结点
    for (int i = 0; i < numCourses; i++) {
        if (inDegree[i] == 0) {
            queue[tail] = i;
            tail++;
        }
    }
    
    while (head != tail) {
        for (int j = 0; j < prerequisitesSize; j++) {
            if (prerequisites[j][1] == queue[head]) {
                inDegree[prerequisites[j][0]]--;
                
                // 入队入度为 0 的结点
                if (inDegree[prerequisites[j][0]] == 0 ) {
                    queue[tail] = prerequisites[j][0];
                    tail++;
                }  
            }            
        }
        head++;
        result--;
    }

    return result == 0;
}
```

```
#define INVALID -1
bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize){
    if (prerequisites == NULL || prerequisitesColSize == NULL) {
        return false;
    }
    int inDegree[numCourses]; // 入度表
    int adjaceTable[numCourses][numCourses]; // 依赖领姐表
    memset(inDegree, 0, sizeof(inDegree));
    memset(adjaceTable, 0, sizeof(adjaceTable));
    for (int i = 0; i < prerequisitesSize; i++) {
        int t = prerequisites[i][0];
        inDegree[t]++;
        int m = prerequisites[i][1];
        adjaceTable[m][t] = 1; // 表示m->t关系存在
    }

    int dequeu[numCourses]; // 创建队列
    memset(dequeu, INVALID, sizeof(dequeu));
    int front = 0, rear = -1; // 初始化对头和对尾
    // 将入度为0的课程入对
    for (int i = 0; i < numCourses; i++) {
        if (inDegree[i] == 0) {
            dequeu[++rear] = i; // 将课程号入对
        }
    }
    // 队列非空则bfs按拓扑排序处理
    int res = numCourses;
    while (front <= rear) {
        int top = dequeu[front++];
        res--;
        for (int i = 0; i < numCourses; i++) {
            if (top != INVALID && adjaceTable[top][i]) {
                adjaceTable[top][i] = 0;
                inDegree[i]--;
                if (inDegree[i] == 0) {
                    dequeu[++rear] = i;
                }
            }
        }
    }
    return res == 0 ? true : false;
}
```

```
#define QUE_MAX_SIZE 2000

int front;
int rear;
int Queue[QUE_MAX_SIZE];

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize){
    front = rear = 0;
    memset(Queue, 0, sizeof(int)*QUE_MAX_SIZE);    
    //printf("prerequisitesColSize=%d\r\n", *prerequisitesColSize);
    int *indegrees = (int *)calloc(numCourses+1, sizeof(int));
    int m = prerequisitesSize;
    int *rst = (int*)calloc(numCourses, sizeof(int));
    *returnSize = 0;
    //入度统计
    for (int i = 0; i < m; i++) {
        int inde = prerequisites[i][0];
        indegrees[inde]++;
    }
    //入度为0的入队列
    for (int i = 0; i < numCourses; i++) {
        if (indegrees[i] == 0) {
            //printf("indegrees[%d]:%d\n",i,indegrees[i]);            
            Queue[rear++] = i;
        }
    }
    //处理队列
    while (front != rear) {
        int pre = Queue[front++];
        numCourses--;
        rst[*returnSize] = pre;
        (*returnSize)++;
        for (int i = 0; i < m; i++) {
            if (pre == prerequisites[i][1]) {
                if (--indegrees[prerequisites[i][0]] == 0) {                    
                    Queue[rear++] = prerequisites[i][0];
                }
            }
        }
    }
    free(indegrees);
    if (numCourses != 0) {
        *returnSize = 0;
    }
    return rst;
}
```

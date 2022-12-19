```
bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize){
    int G[numCourses][numCourses];
    memset(G, 0, sizeof(int) * numCourses * numCourses);
    int que[numCourses + 2];
    int input[numCourses];
    memset(input, 0, sizeof(int) * numCourses);
    for (int i = 0; i < prerequisitesSize; i++) {
        G[prerequisites[i][1]][prerequisites[i][0]] = 1;
        input[prerequisites[i][0]]++;
    }
    int begin = 0;
    int end = 0;

    for (int j = 0; j < numCourses; j++) {
        if (input[j] == 0) {
            que[end++] = j;
        }        
    }
    int len = 0;
    while (begin != end) {
        int node = que[begin];
        begin++;
        len++;
        for (int j = 0; j < numCourses; j++) {
            if (G[node][j] == 1) {
                input[j]--;
                if(input[j] == 0) {
                    que[end++] = j;
                }
            }        
        }
    }
    if (len == numCourses) {
        return true;
    }
    return false;
}
```
